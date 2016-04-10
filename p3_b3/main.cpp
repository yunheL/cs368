///////////////////////////////////////////////////////////////////////////////
////                   ALL STUDENTS COMPLETE THESE SECTIONS
//// Title:            cs368_p3
//// Files:            main.cpp, Student.cpp, SortedList.cpp, Student.h,
//                     SortedList.h
//// Semester:         cs368  Spring 2016
////
//// Author:           Yunhe Liu
//// Email:            liu348@wisc.edu
//// CS Login:         yunhe
//// Lecturer's Name:  Deb
//// Lab Section:      (your lab section number)
////
////////////////////// PAIR PROGRAMMERS COMPLETE THIS SECTION ////////////////////
////
////                   CHECK ASSIGNMENT PAGE TO see IF PAIR-PROGRAMMING IS ALLOWED
////                   If pair programming is allowed:
////                   1. Read PAIR-PROGRAMMING policy (in cs302 policy) 
////                   2. choose a partner wisely
////                   3. REGISTER THE TEAM BEFORE YOU WORK TOGETHER 
////                      a. one partner creates the team
////                      b. the other partner must join the team
////                   4. complete this section for each program file.
////
//// Pair Partner:     (name of your pair programming partner)
//// Email:            (email address of your programming partner)
//// CS Login:         (partner's login name)
//// Lecturer's Name:  (name of your partner's lecturer)
//// Lab Section:      (your partner's lab section number)
////
////////////////////// STUDENTS WHO GET HELP FROM OTHER THAN THEIR PARTNER //////
////                   must fully acknowledge and credit those sources of help.
////                   Instructors and TAs do not have to be credited here,
////                   but tutors, roommates, relatives, strangers, etc do.
////
//// Persons:          Identify persons by name, relationship to you, and email.
////                   Describe in detail the the ideas and help they provided.
////
//// Online sources:   Google, piazza, stack overflow
//
//
//
//
//
// Conclusion on how the update influenced the two classes:
// The update mattered on the SortedList class. For Student class, since all
// the fields are of primitive types (int, int , double). The Student.cpp 
// did not use the "new" operator, thus no alloc on for objects on the heap.
// And it is unlikely for memory leak to happen here.
// However, when it comes to the SortedList class, the Sortedlist itself is
// a more compliated data structure, with the struct listnode as one of 
// its field (which is not primitive type). Many alloc on heap happened in 
// this case. And memory leak can also happen. 
////////////////////////////// 80 columns wide //////////////////////////////////

/* This class extensive tests the Student.cpp class and SortedList.cpp Class
 * <p>Bugs: memory leak
 * @author: Yunhe Liu
 *
 */

#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <fstream>

#include "Student.h"
#include "SortedList.h"

using namespace std;

/*
 * Main methods constructor instance and call method to test the
 * functionality of student and sortedlist class.
 * @return return 0 upon success exit
 */

int main(int argc, char* argv[])
{
  cout << endl << "Test Student class functionality===" << endl;
  Student st0;
  Student st1(1);
  Student st2(2, 8, 4.0);
  Student st3(3, 3, 4.0);
  Student st4(4, 4, 4.0);

  cout << "st2_ID = " << st2.getID() << endl;
  cout << "st2_credit = " << st2.getCredits() << endl;
  cout << "st2_GPA = " << st2.getGPA() << endl;

  st2.update('f', 2);
  cout << "st2_ID = " << st2.getID() << endl;
  cout << "st2_credit = " << st2.getCredits() << endl;
  cout << "st2_GPA = " << st2.getGPA() << endl;

  st1.print();
  st2.print();
  cout << endl << "===Test SortedList CLass Functionality===" << endl;

  SortedList list0;

  Student* st2_ptr = &st2;
  Student* st3_ptr = &st3;
  Student* st4_ptr = &st4;

  cout << "insert id=2: " << list0.insert(st2_ptr) << endl;
  cout << "insert id=2: " << list0.insert(st2_ptr) << endl;
  cout << "insert id=4: " << list0.insert(st4_ptr) << endl;

  cout << "insert id=4: " << list0.insert(st4_ptr) << endl;
  cout << "insert id=3: " << list0.insert(st3_ptr) << endl;
  cout << "insert id=3: " << list0.insert(st3_ptr) << endl;

  cout << "remove id=4: " << list0.remove(4) << "; expected: " << &st4 << endl;
  cout << "remove id=2: " << list0.remove(2) << "; expected: " << &st2 << endl;
  cout << "remove id=2: " << list0.remove(2) << "; expected: " << NULL << endl;

  cout << "insert id=2: " << list0.insert(st2_ptr) << endl;
  cout << "insert id=2: " << list0.insert(st2_ptr) << endl;
  cout << "insert id=4: " << list0.insert(st4_ptr) << endl;

  list0.print();
  cout << "find2: " << list0.find(2) << "; expected: " << &st2 << endl;
  cout << "find3: " << list0.find(3) << "; expected: " << &st3 << endl;

  cout << endl << "===Test stu cp assign, cp constr, de-constr===" << endl;
  Student st5(st3);
  st5.print();
  cout << endl;

  st5 = st4;
  st5.print();
  cout << endl;

  cout << endl << "===Test list cp assign, cp constr, de-constr===" << endl;

  SortedList list1(list0);
  cout << "list 1 print: " << endl;
  list1.print();

  cout << "construct list2" << endl;
  SortedList list2;

  cout << "list2 print before copy assignment" << endl;
  list2.print();

  list2 = list0;
  cout << "list2 print after copy assignment" << endl;
  list2.print(); 

  return 0;
}

