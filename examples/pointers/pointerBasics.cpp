/*
 * pointerBasics.cpp
 * 
 * Program illustrating how pointers are declared, assigned values, and 
 * dereferenced.
 */

#include <iostream>

using namespace std;


int main() {

    int x, y, z;

    /////////////////////////////////
    // declaring pointer variables //
    /////////////////////////////////

    int *p;    
    double *q; 
    int *s, *t; 


    //////////////////////////////////
    // assigning values to pointers //
    //////////////////////////////////

    q = NULL;  
    p = &x;
    s = new int;
    p = s;

    cout << "Assigning to pointers:\n" 
         << "  p: " << p 
         << "  q: " << q 
         << "  s: " << s 
         << "  t: " << t 
         << endl;


    ///////////////////////////////////////
    // referencing the values pointed to //
    ///////////////////////////////////////

    x = 3;
    p = &x;
    *p = 5;
    y = *p + 8;
    *s = *p;

    cout << "\nDereferencing pointers:\n" 
         << "  &x: " << &x 
         << "   x: " << x 
         << endl
         << "  &y: " << &y 
         << "   y: " << y 
         << endl
         << "   p: " << p  
         << "  *p: " << *p 
         << endl
         << "   s: "  << s  
         << "   *s: " << *s 
         << endl;


    // be aware of precedence rules

    z = *p + 1;
    y = *p++;
    cout << "\nPrecedence concerns:\n" 
         << "  y: " << y 
         << "  z: " << z 
         << "  p: " << p 
         << endl;


    ////////////////////////////////
    // declaring and initializing //
    ////////////////////////////////

    int *a = new int(4);
    int *b = new int();

    cout << "\nDeclaring and initializing:\n"
        << "   a: " << a 
        << "  *a: " << *a 
        << endl
        << "   b: " << b 
        << "  *b: " << *b 
        << endl;



    return 0;
}


