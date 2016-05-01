/*
 * testPolynomial.cpp
 *
 * Tests the Polynomial class.
 *
 * To compile, link, and run this example:
 *  - copy Polynomial.h, Polynomial.cpp, and testPolynomial.cpp into a directory
 *  - to compile (creating Polynomial.o and testPolynomial.o):
 *         g++ -c Polynomial.cpp
 *         g++ -c testPolynomial.cpp
 *    then link:
 *         g++ Polynomial.o testPolynomial.o
 *  - alternatively, you can compile and link in one step (without creating
 *    any .o files):
 *         g++ Polynomial.cpp testPolynomial.cpp
 *  - finally, to run the program, just enter the name of the executable:
 *         a.out
 *
 * OR USE THE ASSOCIATED MAKEFILE
 *
 * Originally written by Beck Hasti for CS 368, Spring 2004
 * Updated by Jim Skrentny for CS 368, Fall 2004
 */
#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {

    Polynomial p0;
    double a[] = {1.1, 2.2, 3.3, 4.4};
    Polynomial p1(a, 4);
    Polynomial p2(p1);
    cout << "p1 is " << p1 << endl << "p2 is " << p2 << endl;

    Polynomial p3 = p1 + p2;
    p1 += p3;
    cout << "p1 is " << p1 << endl << "p2 is " << p2 << endl;
    cout << "p3 is " << p3 << endl;

    double a4[] = {3, 3, 3, 3, 3}; 
    Polynomial p4(a4, 5);
    cout << p4 << endl;
    p4 += Polynomial(8);
    cout << p4 << endl;

    Polynomial p5 = p4 * 0.5;
    Polynomial p6 = 4 * p5;
    cout << p5 << endl << p6 << endl;

    // Uncommenting these lines and compiling will result in a .
    // compilation error.  Why?
//    int x = 2;
//    p5 += x;
//    cout << p5 << endl << x << endl;

    if (p4 == p4) 
        cout << "p4 == p4" << endl;
    if (p4 == p6) 
        cout << "p4 == p6" << endl;

    return 0;
}
