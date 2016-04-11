#include <iostream>
#include <stdio.h>
using namespace std;

// ========================
// IO from and to standard
// IO streams in CPP
// ========================
int main(int argc, char ** argv) {
    enum direction { NORTH, SOUTH };
    const int date = 1; // Feb 1st
    // date = date + 2; ILLEGAL
    cout << "Hello world" << endl;
    printf( "Today is February %d! \n", date );
    printf( "North = %d South = %d\n", NORTH, SOUTH );
    cout << "North = " << NORTH << endl;
}
