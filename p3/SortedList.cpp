#include <iostream>
#include "SortedList.h"

using namespace std;

//no-arg constructor
SortedList::SortedList() :
head(new Listnode)
{
  cout << "list no-arg constructor" << endl;
}

//insert - done
bool SortedList::insert(Student *s)
{
  Listnode* s_node;
  s_node = new Listnode;
  s_node->student = s;  

  Listnode* curr = head;
  Listnode* prev = head;
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
      return false;
    }
    else if(curr->student->getID() > s->getID())
    {
      //insert the node befre curr and after prev
      s_node->next = curr;
      prev->next = s_node;
      return true;
    }
  }

  //if the inserted node has the largest ID
  curr->next = s_node;
  
  return true;
}

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


//remove
Student* SortedList::remove(int studentID)
{
  Listnode* curr = head;
  Listnode* prev = head;
//  Listnode* ret;
  bool first_loop = true;

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
      //ret = curr;
      //delete curr;
      //return ret;
      return curr->student;
    }
    else if(curr->student->getID() > studentID)
    {
      //already not possible to find a match
      return NULL;
    }
  }
  return NULL;
}

//print - done
void SortedList::print() const
{
  Listnode* curr = head;

  while(curr->next != NULL)
  {
    curr = curr->next;
    (*curr->student).print();
    cout << endl;
  }
}
