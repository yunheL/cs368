///////////////////////////////////////////////////////////////////////////////
////                   ALL STUDENTS COMPLETE THESE SECTIONS
//// Main Class File:  main.cpp
//// File:             ComplexNumber.cpp
//// Semester:         cs368 Spring 2016
////
//// Author:           Yunhe Liu
//// CS Login:         yunhe
//// Lecturer's Name:  Deb
//// Lab Section:      (your lab section number)
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
//// Online sources:  Google, Stack Overflow, cplusplus.com 
////////////////////////////// 80 columns wide //////////////////////////////////

/*
 * This class implements the ComplexNumber header file. Functionalities
 * inluding constructs, print and equal (member functions), assignment
 * operators, arithmetic operators relational operators and I/O operators
 * overloading.
 * @author: Yunhe Liu
 */

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include "ComplexNumber.h"

using namespace std;

/*
 * Constructor take in 0 argument.
 */
//0-arg constructor
ComplexNumber::ComplexNumber(): real(0.0), imag(0.0){
//  cout << "0-arg constructor" << endl;
}

/*
 * Constructor take in 2 arguments.
 */
//2-arg constructor
ComplexNumber::ComplexNumber(double real_part, double imaginary_part): 
real(real_part), imag(imaginary_part){
//  cout << "2-arg constructor" << endl;
}

/*
 * Copy constructor.
 * @param Take in the ComplexNumber to be copy from
 */
//copy constructor
ComplexNumber::ComplexNumber(const ComplexNumber & rhs):
real(rhs.real), imag(rhs.imag){
//  cout << "copy constructor" << endl;
}

/*
 * Formatting printing the ComplexNumber 
 */
//print
void ComplexNumber::print(ostream & out) const {
  if(imag > 0 || imag == 0)
    out << real << " + " << imag << "i";
  else
  {
    double abs_imag = 0 - imag;
    out << real << " - " << abs_imag << "i";
  }
}

/*
 * See whether who ComplexNumber equals each other
 * @Param take in the two complex numbers to be compared
 * @return true if the two complex numbers are identical
 */
//equals
bool ComplexNumber::equals(const ComplexNumber & rhs) const {
  if(real == rhs.real && imag == rhs.imag)
  {
    return true;
  }
  return false;
}

/*
 * Copy assignment
 * @param Take in the complex number to copy from
 * @return the assigned complex number
 */
// = operator
const ComplexNumber & ComplexNumber::operator= (const ComplexNumber & rhs){
  if(this == &rhs){
    return *this;
  }

  else{
    real = rhs.real;
    imag = rhs.imag;
  }
  return * this;
}

/*
 * Overload += operator
 * @param second oprand
 * @return the updated complex number
 */
// += operator
const ComplexNumber & ComplexNumber::operator+= (const ComplexNumber & rhs){
  real = real + rhs.real;
  imag = imag + rhs.imag;
  return * this;
}

/*
 * Overload -= operator
 * @param second oprand
 * @return the updated complex number
 */
// -= operator
const ComplexNumber & ComplexNumber::operator-= (const ComplexNumber & rhs){
  real = real - rhs.real;
  imag = imag - rhs.imag;
  return * this;
}

/*
 * Overload *= operator
 * @param second oprand
 * @return the updated complex number
 */
// *= operator
const ComplexNumber & ComplexNumber::operator*= (const ComplexNumber & rhs){
  double origin_real = real;
  real = real * rhs.real - imag * rhs.imag;
  imag = origin_real * rhs.imag + imag * rhs.real;
  return * this;
}

/*
 * Overload + operator
 * @param two oprands
 * @return the sum
 */
//overload +
ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs){
  ComplexNumber answer(lhs);
  answer += rhs;
  return answer;
}

/*
 * Overload - operator
 * @param two oprands
 * @return the result
 */
//overload -
ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs){
  ComplexNumber answer(lhs);
  answer -= rhs;
  return answer;
}

/*
 * Overload * operator
 * @param two oprands
 * @return the result
 */
//overload *
ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs){
  ComplexNumber answer(lhs);
  answer *= rhs;
  return answer;
}

/*
 * Overload == operator
 * @param two oprands
 * @return true if the two oprands are equal
 */
//relational ==
bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs){
  if(lhs.equals(rhs)) 
    return true;
  else 
    return false;
}

/*
 * Overload != operator
 * @param two oprands
 * @return true if the two oprands are not equal
 */
//relational !=
bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs){
  if(lhs.equals(rhs)) 
    return false;
  else 
    return true;
}

/*
 * Overload output stream
 * @param output stream and complex number to be output.
 */
//output stream
ostream & operator<<(ostream & out, const ComplexNumber & n) {
  n.print(out);
  return out;
}

/*
 * Overload input stream
 * @param input stream and complex number to be write
 */
//input stream
istream & operator>>(istream & in, ComplexNumber & n) {
  double in_real = 0.0;
  double in_imag = 0.0;
  char arr[255];
  char oprand;
  in >> in_real;
  in >> oprand;
  in >> arr;
  int i = 0;
  while(arr[i++] != 'i');
  arr[i-1] = '\0';
  in_imag = atof(arr);
//  cout << "in_imag" << in_imag << endl;
  if(oprand == '-')
  {
    in_imag = 0 - in_imag;
  } 
  ComplexNumber inputNumber(in_real, in_imag); 
  n = inputNumber;

  return in;
}
//correct verison to submit
