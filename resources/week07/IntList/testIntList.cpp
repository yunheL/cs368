/*
 * testIntList.cpp
 *
 * Tests the IntList class.  Because of the print statements embedded in the
 * IntList class, as testIntList runs, the various constructors, destructors,
 * etc. being called are reported (to standard output).
 *
 * To compile, link, and run this example:
 *  - copy IntList.h, IntList.cpp, and testIntList.cpp into a directory
 *  - to compile (creating IntList.o and testIntList.o):
 *         g++ -c IntList.cpp
 *         g++ -c testIntList.cpp
 *    then link:
 *         g++ IntList.o testIntList.o
 *  - alternatively, you can compile and link in one step (without creating
 *    any .o files):
 *         g++ IntList.cpp testIntList.cpp
 *  - finally, to run the program, just enter the name of the executable:
 *         a.out
 *
 * Originally written by Beck Hasti for CS 368, Spring 2004
 */
#include <iostream>
#include "IntList.h"

using namespace std;

void copyAgain(IntList L) {
    IntList Lnew = L;
    Lnew.print();
    L.print();
}

int main() {
    IntList L1;
    IntList L2(25);

    IntList *p, *q;
    p = new IntList;
    q = new IntList(25);

    for (int i = 0; i < 20; i++)
        L1.addToEnd(i+1);
    L1.print();

    L2 = L1;
    L2.addToEnd(-1);

    IntList L3(L1);

    L1.print();
    L2.print();
    L3.print();

    copyAgain(L3);

//    delete p;
//    delete q;

    return 0;
}
