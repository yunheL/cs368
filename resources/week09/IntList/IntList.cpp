/*
 * IntList.cpp
 *
 * NOTE: print statements have been added to most functions in order to show
 * what gets called when testIntList is run.  These are for testing purposes
 * only; normally, we would not include such statements in our class code.
 *
 * Originally written by Beck Hasti for CS 368, Spring 2004
 */

#include <iostream>
#include "IntList.h"

using namespace std;

// Note: in order to use cout (including in the print() function), we need to
// include iostream and use the standard namespace.


// Default (no-argument) constructor
IntList::IntList() : 
items(new int[SIZE]), numItems(0), arraySize(SIZE) {
    cout << "default constructor" << endl;
}


// Constructor - takes an initial size
IntList::IntList(int size) : 
items(new int[size]), numItems(0), arraySize(size) {
    cout << "one arg constructor" << endl;
}


// Copy constructor
IntList::IntList(const IntList &L) : 
items(new int[L.arraySize]), numItems(L.numItems), arraySize(L.arraySize) {
    cout << "copy constructor" << endl;
    for (int k = 0; k < numItems; k++)
        items[k] = L.items[k];
}


// Destructor
IntList::~IntList() {
    cout << "destructor" << endl;
    delete [] items;
}


// Overload the assignment operator
IntList & IntList::operator=(const IntList &L) {
    cout << "assignment" << endl;
    // check for self-assignment - if so, do nothing
    if (this == &L)
        return *this;

    else {
        delete [] items;               // free storage pointed to by items
        items = new int[L.arraySize];  // allocate new array
        arraySize = L.arraySize;       // set arraySize

        // copy items from L's array to the new array
        // (and also set numItems)
        for (numItems = 0; numItems < L.numItems; numItems++)
            items[numItems] = L.items[numItems];
    }

    return *this;
}

// OVERLOAD ADDITION ASSIGNMENT
void IntList::operator+=(int new_value) {
     addToEnd(new_value);
}

// OVERLOAD INDEXING OPERATOR
int IntList::operator[](int index) const {
     return items[index];
}

// OVERLOAD EQUALITY OPERATOR
bool IntList::operator==(const IntList & rhs) const  {
    if ( numItems != rhs.numItems ) return false;
    for ( int i=0; i < numItems ; i++ ) {
        if ( items[i] != rhs.items[i] ) 
            return false;
    }
    return true;
}

// OVERLOAD ADDITION as an IntList member function
IntList & IntList::operator+(const IntList & other) {
     for ( int i=0; i < other.numItems; i++ ) {
         addToEnd( other[i] );
     }
     return *this;
}

// OVERLOAD ADDITION as a free function
IntList & operator+(IntList & lhs, const IntList & rhs) {
     for ( int i=0; i < rhs.numItems; i++ ) {
         lhs.addToEnd( rhs[i] );
     }
     return lhs;
}

// OVERLOAD << operator for output
std::ostream & operator << ( std::ostream & out, const IntList & list ) {
     list.print(out);
     return out;
}

// addToEnd - adds item k to the end of the list
// If the array is full, the array is first doubled in size.
void IntList::addToEnd(int k) {

    // check if enough room, if not, double the array
    if (numItems == arraySize) {
        int *newItems = new int[arraySize*2];
        for (int i = 0; i < numItems; i++)
            newItems[i] = items[i];
        delete [] items;
        items = newItems;
        arraySize *= 2;
    }

    // add the item
    items[numItems] = k;
    numItems++;
}

// print - prints out the list to the console (using cout)
void IntList::print() const {
    print(std::cout);
}

// print - prints out the list to the console (using cout)
void IntList::print(std::ostream & out) const {
    out << "[ " ;
    for (int i = 0; i < numItems; i++)
        out << items[i] << " " ;
    out << "]";
}
