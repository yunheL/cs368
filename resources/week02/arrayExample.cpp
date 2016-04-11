// PRIMITIVE ARRAYS
//
// DON'T USE PRIMITIVE ARRAYS, USE VECTORS INSTEAD
// THIS EXAMPLE IS INCLUDED IN CASE YOU
// FIND CODE THAT USED PRIMITIVE ARRAYS

#include <iostream>
using namespace std;

void printArray(int a[], int b, char c) {
    for ( int i=0; i < b; i++ )
        cout << c << "[" << i << "]=" << a[i] << endl;

}

int main() {

    int x = 4;
    int y[x]; // primitive array
              // y is a pointer to the first byte of the array
              // the array has room for 4*32bit integer values

    int z[] = { 1, 2, 3, 4}; // primitive array
              // z is a pointer to the first byte of the array
              // the array has room for 4*32bit integer values

    printArray(y,x,'y');
    printArray(z,x,'z');
    cout << "x=" << x << endl;
    cout << "&x=" << &x << endl;
    cout << "y[" << x << "]=" << y[x] << endl;
    cout << "&y=" << &y << endl;
    cout << "z[" << x << "]=" << z[x] << endl;
    cout << "&z=" << &z << endl;
    return 0;
}
