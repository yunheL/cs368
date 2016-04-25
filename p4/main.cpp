#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include "ComplexNumber.h"

using namespace std;

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
