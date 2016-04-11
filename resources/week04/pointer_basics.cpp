#include <iostream>  
#include "stdio.h"
using namespace std;

// ----------------------------------------------------------------------------
// NOTE: file move or rename will break links from syllabus and main page
// ----------------------------------------------------------------------------

/*
   ----------------------------------------------------------------------------
   Because of the use of C++11 form for array initialization, i
   pointer_basics.cpp must be compiled with C++11 libraries.
 
   To do this on CS Linux workstations: 
   /s/gcc-5.1/bin/g++ -std=c++11 pointer_basics.cpp  
   ----------------------------------------------------------------------------
*/


/*
   ------------------------------------------------
   output (absolute memory addresses will vary):
   ------------------------------------------------
   int x = 3;    // x = 3
   int &y = x;   // y = 3
   int *z = &x;  // z = 0x7ffd0235a464
   &x = 0x7ffd0235a464
   &y = 0x7ffd0235a464
   &z = 0x7ffd0235a458
   *z = 3
   a     = 0x7ffd0235a440
   &a    = 0x7ffd0235a440
   *a    = 11
   a[0]  = 11
   &a[0] = 0x7ffd0235a440
   int *w = z;
   w = 0x7ffeafc0ba14
   &w = 0x7ffeafc0b9e8
   *w = 3
   ------------------------------------------------ 
*/

main() {

    int x = 3;
    int &y = x;
    int *z = &x;

    cout << "int x = 3;    // x = " << x << endl;
    cout << "int &y = x;   // y = " << y << endl;
    cout << "int *z = &x;  // z = " << z << endl;

    cout << "&x = " << &x << endl;
    cout << "&y = " << &y << endl;
    cout << "&z = " << &z << endl;

    //cout << "*x = " << *x << endl; // COMPILER ERROR
    //cout << "*y = " << *y << endl; // COMPILER ERROR
    cout << "*z = " << *z << endl;

    // Let's check out the array
    int a[] {11,22,33};

    cout << "a     = " << a  << endl;
    cout << "&a    = " << &a << endl;
    cout << "*a    = " << *a << endl;

    cout << "a[0]  = " << a[0] << endl;
    cout << "&a[0]  = " << &a[0] << endl;
    //cout << "*a[0]  = " << *a[0] << endl; // COMPILER ERROR

    int *w = z;
    cout << "int *w = z;" << endl;
    cout << "w = " << w << endl;
    cout << "&w = " << &w << endl;
    cout << "*w = " << *w << endl;
    
}
