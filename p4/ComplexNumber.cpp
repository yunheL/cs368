#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include "ComplexNumber.h"

using namespace std;

//0-arg constructor
ComplexNumber::ComplexNumber(): real(0.0), imag(0.0){
//  cout << "0-arg constructor" << endl;
}

//2-arg constructor
ComplexNumber::ComplexNumber(double real_part, double imaginary_part): 
real(real_part), imag(imaginary_part){
//  cout << "2-arg constructor" << endl;
}

//copy constructor
ComplexNumber::ComplexNumber(const ComplexNumber & rhs):
real(rhs.real), imag(rhs.imag){
//  cout << "copy constructor" << endl;
}

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

//equals
bool ComplexNumber::equals(const ComplexNumber & rhs) const {
  if(real == rhs.real && imag == rhs.imag)
  {
    return true;
  }
  return false;
}

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

// += operator
const ComplexNumber & ComplexNumber::operator+= (const ComplexNumber & rhs){
  real = real + rhs.real;
  imag = imag + rhs.imag;
  return * this;
}

// -= operator
const ComplexNumber & ComplexNumber::operator-= (const ComplexNumber & rhs){
  real = real - rhs.real;
  imag = imag - rhs.imag;
  return * this;
}

// *= operator
const ComplexNumber & ComplexNumber::operator*= (const ComplexNumber & rhs){
  double origin_real = real;
  real = real * rhs.real - imag * rhs.imag;
  imag = origin_real * rhs.imag + imag * rhs.real;
  return * this;
}

//overload +
ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs){
  ComplexNumber answer(lhs);
  answer += rhs;
  return answer;
}

//overload -
ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs){
  ComplexNumber answer(lhs);
  answer -= rhs;
  return answer;
}

//overload *
ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs){
  ComplexNumber answer(lhs);
  answer *= rhs;
  return answer;
}

//relational ==
bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs){
  if(lhs.equals(rhs)) 
    return true;
  else 
    return false;
}

//relational !=
bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs){
  if(lhs.equals(rhs)) 
    return false;
  else 
    return true;
}

//output stream
ostream & operator<<(ostream & out, const ComplexNumber & n) {
  n.print(out);
  return out;
}


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

