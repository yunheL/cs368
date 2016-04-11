/*
 * main.cpp
 *
 * Tests overloaded operators of the IntList class. 
 *
 */
#include <iostream>
#include "IntList.h"

using namespace std;

int main() {

    IntList L1,L2,L3;

    //main.cpp:16: error: no match for operator+= in L1 += 10’
    L1 += 5;

    //main.cpp:19: error: no match for operator+ in L1 + L2
    L3 = L1 + L2;
    cout << "L3 = " ;
    L3.print();
    cout << endl;
//    cout << L1;

    //main.cpp:25: error: no match for operator[] in L1[0]
    if ( L1[0] == 5 ) 
        cout << "L1[0]==5" << endl;
    else
        cout << "L1[0]!=5" << endl;


    //main.cpp:29: error: no match for operator== in L1 == L2
    if ( L1==L2 ) 
        cout << "L1==L2" << endl;
    else
        cout << "L1!=L2" << endl;


    return 0;
}
