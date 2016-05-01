/*
 * testImplicitTypeConversion.cpp
 *
 * Demonstrates problem that can arise with implicit type conversion
 * when class has a one arg constructor.
 *
 * To compile, link, and run this example:
 *  - copy Polynomial.h, Polynomial.cpp, and testImplicitTypeConversion.cpp into a directory
 *  - to compile (creating Polynomial.o and testImplicitTypeConversion.o):
 *         g++ -c Polynomial.cpp
 *         g++ -c testImplicitTypeConversion.cpp
 *    then link:
 *         g++ Polynomial.o testImplicitTypeConversion.o
 *  - alternatively, you can compile and link in one step (without creating
 *    any .o files):
 *         g++ Polynomial.cpp testImplicitTypeConversion.cpp
 *  - finally, to run the program, just enter the name of the executable:
 *         a.out
 *
 * OR USE THE ASSOCIATED MAKEFILE
 * make testImplicitTypeConversion
 *
 * Originally written by Beck Hasti for CS 368, Spring 2004
 * Updated by Jim Skrentny for CS 368, Fall 2004
 */

#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {

    Polynomial p1;
    cout << "p1; p1 = " << p1 << endl;

    Polynomial p2 = 4.1;
    cout << "p2=4.1; p2 = " << p2 << endl;

    p1 = 3.2;

    cout << "p1=3.2; p1 = " << p1 << endl;

    p2 += 8.7;
    cout << "p2+=8.7; p2 = " << p2 << endl;

    Polynomial p3;
    cout << "p3; p3 = " << p3 << endl;

    p3 = p2 + 4.2;
    cout << "p3=p2+4.2; p3 = " << p3 << endl;

    p1 = 6.5 + p3;
    cout << "p1=6.5+p3; p1 = " << p1 << endl;

    return 0;
}
