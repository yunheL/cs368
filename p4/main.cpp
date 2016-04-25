///////////////////////////////////////////////////////////////////////////////
////                   ALL STUDENTS COMPLETE THESE SECTIONS
//// Title:            cs368_p4
//// Files:            main.cpp, ComplexNumber.cpp
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
//// Online sources:   Google, Stack Overflow, cplusplus.com 
////////////////////////////// 80 columns wide //////////////////////////////////

/*
 * This class reads in user input complex number to test the functionality
 * of the implemented complex number clas.
 * @author: Yunhe Liu
 */


#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include "ComplexNumber.h"

using namespace std;

/*
 * main method for testing functionaly of the ComplexNumber class.
 * @return 0 upon success
 */
int main(int argc, char* argv[])
{
  cout << "Enter a complex number C1: " << endl;
  ComplexNumber C1;
  cin >> C1;

  cout << "Enter a complex number C2: " << endl;
  ComplexNumber C2;
  cin >> C2;

  cout << "For C1 = " << C1 << " and C2 = " << C2 << " : " << endl;

  ComplexNumber C3;
  C3 = C1 + C2;
  cout << "C1 + C2 = " << C3 << endl;

  C3 = C1 - C2;
  cout << "C1 - C2 = " << C3 << endl;

  C3 = C1 * C2;
  cout << "C1 * C2 = " << C3 << endl;

  string result;

  if(C1 == C2)
    result = "true";
  else
    result = "false";

  cout << "C1 == C2 is " << result << endl;

  if(C1 != C2)
    result = "true";
  else
    result = "false";

  cout << "C1 != C2 is " << result << endl;

  ComplexNumber original_C1;
  original_C1 = C1;
  
  C1 += C2;
  cout << "After C1 += C2, C1 = " << C1 << endl;

  C1 = original_C1;

  C1 -= C2;
  cout << "After C1 -= C2, C1 = " << C1 << endl;

  C1 = original_C1;

  C1 *= C2;
  cout << "After C1 *= C2, C1 = " << C1 << endl;

  return 0;

/*
  cout << "**tesing 0-arg constructor" << endl;
  ComplexNumber c0;
  //cout << "c0.real = " << c0.real << endl; 
  //cout << "c0.imag = " << c0.imag << endl;

  cout << "**tesing 2-arg constructor" << endl;
  ComplexNumber c1(1.0, 1.0);
  //cout << "c1.real = " << c1.real << endl; 
  //cout << "c1.imag = " << c1.imag << endl;

  cout << "**tesing copy constructor" << endl;
  ComplexNumber c2(c1);
  //cout << "c1.real = " << c1.real << endl; 
  //cout << "c1.imag = " << c1.imag << endl;

  cout << "**tesing print" << endl;
  c0.print();
  cout << endl;
  c1.print();
  cout << endl;
  c2.print();
  cout << endl;
 
  cout << "**tesing equals" << endl;
  cout << "c0 = c1: " << c0.equals(c1) << endl;
  cout << "c1 = c2: " << c1.equals(c2) << endl;

  cout << "**tesing = operator" << endl;
  ComplexNumber c3;
  c3 = c1;
  c3.print();
  cout << endl;

  cout << "**tesing += operator" << endl;
  c3 += c1;
  c3.print();
  cout << endl;

  cout << "**tesing -= operator" << endl;
  c3 -= c1;
  c3.print();
  cout << endl;

  cout << "**tesing *= operator" << endl;
  ComplexNumber c4(4.2, 8.3);
  ComplexNumber c5(3.1, -9.2);
  c4 *= c5;
  c4.print();
  cout << endl;

  cout << "**tesing + overload" << endl;
  c4 =  c1 + c2;
  c4.print();
  cout << endl;

  cout << "**tesing - overload" << endl;
  c4 =  c1 - c2;
  c4.print();
  cout << endl;

  cout << "**tesing * overload" << endl;
  ComplexNumber c6(4.2, 8.3);
  c4 =  c5 * c6;
  c4.print();
  cout << endl;

  cout << "**tesing == relational" << endl;
  ComplexNumber c7(4.2, 8.3);
  bool result;

  if(c6 == c6) 
    result = true;
  else 
    result = false;
  cout << "c6 == c6: " << result << endl;

  if(c6 == c7) 
    result = true;
  else 
    result = false;
  cout << "c6 == c7: " << result << endl;

  if(c6 == c5) 
    result = true;
  else 
    result = false;
  cout << "c6 == c5: " << result << endl;

  cout << "**tesing != relational" << endl;
  if(c6 != c6) 
    result = true;
  else 
    result = false;
  cout << "c6 != c6: " << result << endl;

  if(c6 != c7) 
    result = true;
  else 
    result = false;
  cout << "c6 != c7: " << result << endl;

  if(c6 != c5) 
    result = true;
  else 
    result = false;
  cout << "c6 != c5: " << result << endl;

  cout << "**testing output stream" << endl;
  cout << c7 << endl;

  cout << "**testing input stream" << endl;
  cout << "Enter a complex number C1: " << endl;  
  cin >> c7;
  c7.print();
  cout << endl;

//  cin.clear();
//  cin.ignore('i');

  cout << "Enter a complex number C2: " << endl;
  ComplexNumber c8;  //(4.2,8.3);
  cin >> c8;
  cout << "c8 = ";
  c8.print();
  cout << endl;

  c8 *= c7;
  c8.print();
  cout << endl;

  return 0;
*/
}
//correct version to submit
