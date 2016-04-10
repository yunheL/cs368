///////////////////////////////////////////////////////////////////////////////
////                   ALL STUDENTS COMPLETE THESE SECTIONS
//// Main Class File:  main.cpp
//// File:             SortedList.cpp
//// Semester:         cs368 Spring 2016
////
//// Author:           Yunhe Liu
//// CS Login:         yunhe
//// Lecturer's Name:  Deb
//// Lab Section:      
////
////////////////////// PAIR PROGRAMMERS COMPLETE THIS SECTION ////////////////////
////
//// Pair Partner:     (name of your pair programming partner)
//// Email:            (email address of your programming partner)
//// CS Login:         (partner's login name)
//// Lecturer's Name:  (name of your partner's lecturer)
//// Lab Section:      (your partner's lab section number)
////
////////////////////// STUDENTS WHO GET HELP FROM OTHER THAN THEIR PARTNER //////
////                   fully acknowledge and credit all sources of help,
////                   other than Instructors and TAs.
////
//// Persons:          Identify persons by name, relationship to you, and email.
////                   Describe in detail the the ideas and help they provided.
////
//// Online sources:   Google, piazza, stackoverflow 
////////////////////////////// 80 columns wide //////////////////////////////////

/*
 * This class implments the SortedList.h file
 * <p>Bugs: memory leak
 * @author: Yunhe Liu
 */

#include <iostream>
#include "SortedList.h"

using namespace std;

/*
 * constructor
 */
//no-arg constructor
SortedList::SortedList() :
head(new Listnode)
{
  head->student = NULL;
  head->next = NULL;
  cout << "list no-arg constructor" << endl;
}

/*
 * Big three
 */
//copy constructor
SortedList::SortedList(const SortedList &S) :
head(new Listnode)
{
  cout<< "list copy constructor" << endl;

  Listnode* curr = S.head;
  Listnode* n_curr = head;  

  while(curr->next  != NULL)
  {
    curr = curr->next;

    Listnode* n_node;
    n_node = new Listnode;
    n_node->student = curr->student;
    n_node->next = NULL;
    //insert to new list
    n_curr->next = n_node;
    
    //update n_curr
    n_curr = n_curr->next;
  }
}

//deconstructor
SortedList::~SortedList(){
  cout << "list deconstructor" << endl;
//  freeList(head);
  Listnode* curr;
  Listnode* nxt;
  curr = head->next;
  while(curr != NULL)
  {
    nxt = curr->next;
    delete curr;
    curr = nxt;
  }
  delete head;
  //delete curr;
  //delete nxt;
}

//copy assignment
SortedList & SortedList::operator=(const SortedList &S)
{
  cout<< "list assignment" << endl;
  
  //check for self-assignment - if so, do nothing
  if(this == &S)
    return *this;

  else
  {
    //remove all the original nodes
    Listnode* curr = head->next;
    Listnode* nxt;
    while(curr != NULL)
    {
      nxt = curr->next;
      delete curr;
      curr = nxt;
    }
    head->next = NULL;
    Listnode* prev = head;
    curr = S.head->next;
    Listnode* n_curr;
    //n_curr = new Listnode;
    //n_curr->next = NULL;
    //n_curr->student = NULL;
    //Listnode* n_head = n_curr;
    
    while(curr != NULL)
    {
      n_curr = new Listnode;
      n_curr->student = curr->student;
      n_curr->next = NULL;
      prev->next = n_curr;
      curr = curr->next;
      prev = prev->next;
    }
   
    //delete n_curr; 
    return *this;
  }
}

/*
 * insert student at sorted location if student is not already in the list
 * @return true upon successful insert, otherwise false
 */
//insert - done
bool SortedList::insert(Student *s)
{
  Listnode* s_node;
  //s_node = new Listnode;
  //s_node->student = s;  
  //s_node->next = NULL;
  Listnode* curr = head->next;
  Listnode* prev = head;
 
  while(curr != NULL){
     if(curr->student->getID() == s->getID()) return false;
     if(curr->student->getID() > s->getID()){
	 s_node = new Listnode;
         s_node->student = s;  
         s_node->next = NULL;
 
         s_node -> next = curr;
         prev->next = s_node;
	 return true;
     }

     prev = curr;
     curr = curr->next;
  }
 s_node = new Listnode;
 s_node->student = s;  
 s_node->next = NULL;

 
  prev->next = s_node;
  return true;
  /*
  bool first_loop = true;

  while(curr->next != NULL)
  {
    curr = curr->next;
    if(!first_loop)
    {
      prev = prev->next;
    }
    first_loop = false;

    if(curr->student->getID() == s->getID())
    {
      delete s_node;
      return false;
    }
    else if(curr->student->getID() > s->getID())
    {
      //insert the node befre curr and after prev
      s_node->next = curr;
      prev->next = s_node;
      
      //delete s_node;
      return true;
    }
  }
  

  //if the inserted node has the largest ID
  curr->next = s_node;
	
  return true;
  */
}

/*
 * find student with specific student id in sorted list
 * @return student* if found, otherwise return NULL
 */
//find - done
Student* SortedList::find(int studentID)
{
  Listnode* curr = head; 

  while(curr->next != NULL)
  {
    curr = curr->next;
    if(curr->student->getID() == studentID)
      return curr->student;
  }
 
  return NULL;
}

/*
 * Remove student with specific studentID if student is found in the list
 * @return student* if succesfully removed, otherwise return NULL
 */
//remove
Student* SortedList::remove(int studentID)
{
  Listnode* curr = head;
  //Listnode* prev = head;
  Listnode* ret;
  Student * s = NULL;
  //bool first_loop = true;
  while(curr->next != NULL){
    if(curr->next->student->getID() == studentID){
       s = curr->next->student;
       ret = curr->next;
       curr->next = ret->next;
       delete ret;
       return s; 
    }
    curr = curr->next;
  }
  return NULL;
  /*
  while(curr->next != NULL)
  {
    curr = curr->next;
    if(!first_loop)
    {
      prev = prev->next;
    }
    first_loop = false;

    if(curr->student->getID() == studentID)
    {
      //remove node
      prev->next = curr->next;
      ret = curr;
      delete curr;
      return ret->student;
      //return curr->student;
    }
    else if(curr->student->getID() > studentID)
    {
      //already not possible to find a match
      return NULL;
    }
  }
  return NULL;
  */
}

/*
 * format print the sorted list
 */
//print - done
void SortedList::print() const
{
  Listnode* curr = head->next;

  while(curr != NULL)
  {
    (*curr->student).print();
    cout << endl;
    curr = curr->next;
  }
  
}

//freeList
/*
void SortedList::freeList(Listnode *L)
{
  //mechanism implemented in destructor and assignment operator already
}
*/

//copyList
/*
ListNode* SortedList::copyList(Listnode *L)
{
  //mechanism implemented in copy constructor and copy assignmet already
}
*/
