#include <iostream>  
#include <vector>
using namespace std;

// pass by value
void noswap( int a, int b ) {
   int t = a; a = b; b = t;
}

// pass by reference
void swap( int &a, int &b ) {
    int t = a; a = b; b = t;
}

// pass by const reference
void constswap( const int &a, const int &b ) {
//   int t = a; a = b; b = t; // compiler errors
}

int main() {
   int x = 3, y = 4;
   noswap( x, y );     cout << "x=" << x << " y=" << y << endl;
   swap( x, y );       cout << "x=" << x << " y=" << y << endl;
   constswap( x, y );  cout << "x=" << x << " y=" << y << endl;
   return 0;
}

