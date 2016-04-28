/**
 * @author See Contributors.txt for code contributors and overview of BadgerDB.
 *
 * @section LICENSE
 * Copyright (c) 2012 Database Group, Computer Sciences Department, University of Wisconsin-Madison.
 */

#include "btree.h"
#include "filescan.h"
#include "exceptions/bad_index_info_exception.h"
#include "exceptions/bad_opcodes_exception.h"
#include "exceptions/bad_scanrange_exception.h"
#include "exceptions/no_such_key_found_exception.h"
#include "exceptions/scan_not_initialized_exception.h"
#include "exceptions/index_scan_completed_exception.h"
#include "exceptions/file_not_found_exception.h"
#include "exceptions/end_of_file_exception.h"


//#define DEBUG
namespace badgerdb
{

NonLeafNodeInt* root;

// -----------------------------------------------------------------------------
// BTreeIndex::BTreeIndex -- Constructor
// -----------------------------------------------------------------------------

BTreeIndex::BTreeIndex(const std::string & relationName,
		std::string & outIndexName,
		BufMgr *bufMgrIn,
		const int attrByteOffset,
		const Datatype attrType)
{
    // Print out parameters (for debugging)
    std::cout << "Entering BTreeIndex()\n";

    // Set internal fields to passed in parameters
    bufMgr = bufMgrIn;
    attributeType = attrType;
    this->attrByteOffset = attrByteOffset;
    scanExecuting = false;

    // Get index file name
    std::ostringstream idxStr;
    idxStr << relationName << '.' << attrByteOffset;
    std::string indexName = idxStr.str(); // indexName is name of index file
    outIndexName = indexName;
    
    // Open index file if it exists, otherwise create one
    if (File::exists(indexName)) {
        file = new BlobFile(indexName, false);

        // Read back the meta info
        headerPageNum = file->getFirstPageNo();
        Page *header;
        bufMgr->readPage(file, headerPageNum, header);
        struct IndexMetaInfo* metaInfo = (struct IndexMetaInfo*) header;

        // Make sure everything matches up!
        if (attrByteOffset != metaInfo->attrByteOffset)
            throw BadIndexInfoException("attrByteOffset mismatch");
        if (attrType != metaInfo->attrType)
            throw BadIndexInfoException("attrType mismatch");
        if (strncmp(metaInfo->relationName, relationName.c_str(), sizeof(metaInfo->relationName)) != 0)
            throw BadIndexInfoException("relationName mismatch");
        
        // Set root page number
        rootPageNum = metaInfo->rootPageNo;

        // Unpin header page!
        bufMgr->unPinPage(file, headerPageNum, false);

    } else {
        // Create new file for index
        file = new BlobFile(indexName, true);
        headerPageNum = file->getFirstPageNo();

        // Set up meta info!
        Page* header;
        bufMgr->allocPage(file, headerPageNum, header);
        
        struct IndexMetaInfo* metaInfo = (struct IndexMetaInfo *) header;
        strncpy(metaInfo->relationName, relationName.c_str(), sizeof(metaInfo->relationName));
        metaInfo->attrByteOffset = attrByteOffset;
        metaInfo->attrType = attrType;
        metaInfo->rootPageNo = rootPageNum = 2; // See btree.h for details
        
        // Set up root page!
        Page* rootPage;
        bufMgr->allocPage(file, rootPageNum, rootPage);
        root = (struct NonLeafNodeInt*) rootPage;
        root->level = 1;

        // Don't forget to unpin!
        bufMgr->unPinPage(file, headerPageNum, true);
        bufMgr->unPinPage(file, rootPageNum, true);
        bufMgr->flushFile(file);

        // Insert currently existing records into B+ tree
        FileScan* scanner = new FileScan(relationName, bufMgr);
        RecordId curr;
        try {
            while (1) {
                // Scan each entry, getting record & inserting into tree
                scanner->scanNext(curr);
                std::string recordStr = scanner->getRecord();
                const char *record = recordStr.c_str();
                insertEntry(record + attrByteOffset, curr);
            }
        // Will throw exception when end of file is reached
        } catch (EndOfFileException e) {}
        
        bufMgr->flushFile(file);
    }

    std::cout << "Exiting BTreeIndex()\n";
}


// -----------------------------------------------------------------------------
// BTreeIndex::~BTreeIndex -- destructor
// -----------------------------------------------------------------------------

BTreeIndex::~BTreeIndex()
{
    std::cout << "Entering ~BTreeIndex()\n";
    // TODO: first unpin pages!
    bufMgr->flushFile(file);
    delete file;
    delete bufMgr;
    std::cout << "Exiting ~BTreeIndex()\n";
}

// -----------------------------------------------------------------------------
// BTreeIndex::insertEntry
// -----------------------------------------------------------------------------

const void BTreeIndex::insertEntry(const void *key, const RecordId rid) 
{
    // Print out parameters
    std::cout << "Entering insertEntry()\n";
    if (attributeType == INTEGER) {
        // Reinterpret key
        int key_int = *(reinterpret_cast<const int*>(key)); 

        // Get root & set curr to it
        PageId currPageNum = rootPageNum;
        Page* currPage;
        bufMgr->readPage(file, currPageNum, currPage);
        struct NonLeafNodeInt* curr = (struct NonLeafNodeInt*) currPage;
        
        // Try to get to a leaf node
        struct LeafNodeInt* leaf = NULL;
        while (leaf == NULL) {
            // Search for next node
            int i;
            for (i = 0; i < INTARRAYNONLEAFSIZE; i++) {
                // TODO: Figure out cases where things are full
                if (curr->pageNoArray[i] == 0) {
                    break; // Might need to do more in this case
                }
                if (curr->keyArray[i] >= key_int) {
                    break;
                }
             }

            int level = curr->level; // Might need to use later in some cases!
            // Get next node (alloc new one if doesn't exist)
            bool createNew = curr->pageNoArray[i] == 0;
            if (createNew) {
                curr->keyArray[i] = key_int;

                // Set up new node
                bufMgr->allocPage(file, curr->pageNoArray[i], currPage);
            } else {
                // Read in page containing next node
                bufMgr->readPage(file, curr->pageNoArray[i], currPage);
            }
            PageId temp = curr->pageNoArray[i];
            // If this is a leaf, set the leaf!
            if (curr->level == 1) {
                leaf = (struct LeafNodeInt*) currPage; 
                if (createNew) {
                    // If we just created this one, wanna clear out everything
                    for (int j = 0; j < INTARRAYLEAFSIZE; j++) {
                        leaf->keyArray[j] = 0;
                    }
                }
            } else {
                curr = (struct NonLeafNodeInt*) currPage;
                if (createNew) {
                    // If we just created this one, wanna clear out everything
                    curr->level = level - 1;
                    for (int j = 0; j < INTARRAYNONLEAFSIZE; j++) {
                        curr->keyArray[j] = 0;
                        curr->pageNoArray[j] = 0;
                    }
                    curr->pageNoArray[INTARRAYNONLEAFSIZE] = 0;
                }
            }

            // Unpin current page and set new currPageNum
            bufMgr->unPinPage(file, currPageNum, true);
            currPageNum = temp;
        }
        
        // Now at the leaf level 
        for (int i = 0; i < INTARRAYLEAFSIZE; i++) {
            std::cout << leaf->keyArray[i];
            //std::cout << leaf->ridArray[i];
        } 
        std::cout << std::endl;
        // Unpin leaf
        bufMgr->unPinPage(file, currPageNum, true);
    } else if (attributeType == DOUBLE) {
        // We should focus on getting the int's to work first, then it should
        // be pretty obvious how to do for other data types!
        std::cout << "key: " << *(reinterpret_cast<const double*>(key)) << "\n";
    } else if (attributeType == STRING) {
        std::cout << "key: " << reinterpret_cast<const char*>(key) << "\n";
    }

    std::cout << "Exiting insertEntry()\n";
}

// -----------------------------------------------------------------------------
// BTreeIndex::startScan
// -----------------------------------------------------------------------------

const void BTreeIndex::startScan(const void* lowValParm,
				   const Operator lowOpParm,
				   const void* highValParm,
				   const Operator highOpParm)
{
    std::cout << "Entering startScan()\n";
    // Check if another scan is going on, if so, end it!
    if (scanExecuting)
        endScan();
    
    // Set relevant fields
    scanExecuting = true;
    lowOp = lowOpParm;
    highOp = highOpParm;

    // Get root 
    PageId currPageNum = rootPageNum;
    Page* currPage;
    bufMgr->readPage(file, currPageNum, currPage);

    // Set low & high vals, navigate to lowVal
    if (attributeType == INTEGER) {
        lowValInt = *(reinterpret_cast<const int*>(lowValParm));
        highValInt = *(reinterpret_cast<const int*>(highValParm));

        // TODO: Navigate to where lowVal starts in our tree
        struct NonLeafNodeInt* curr = (struct NonLeafNodeInt*) currPage;
        
    } else if (attributeType == DOUBLE) {
        lowValDouble = *(reinterpret_cast<const double*>(lowValParm));
        highValDouble = *(reinterpret_cast<const double*>(highValParm));
    } else {
        lowValString = *(reinterpret_cast<const std::string*>(lowValParm));
        highValString = *(reinterpret_cast<const std::string*>(highValParm));
    } 
    std::cout << "Exiting startScan()\n";
}

// -----------------------------------------------------------------------------
// BTreeIndex::scanNext
// -----------------------------------------------------------------------------

const void BTreeIndex::scanNext(RecordId& outRid) 
{

    std::cout << "Entering scanNext()\n";
    std::cout << "Exiting scanNext()\n";
}

// -----------------------------------------------------------------------------
// BTreeIndex::endScan
// -----------------------------------------------------------------------------
//
const void BTreeIndex::endScan() 
{
    std::cout << "Entering endScan()\n";
    scanExecuting = false; // May need to do more stuff TODO: Figure that out!
    std::cout << "Exiting endScan()\n";
}

}
