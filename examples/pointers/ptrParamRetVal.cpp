#include <iostream>
#include <string>

using namespace std;

////////////////////////////////////////////////////////////////////////////////

// Pass-by-reference (simple swap)
void swap1(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

// Simulated pass-by-reference (simple swap)
void swap2(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

////////////////////////////////////////////////////////////////////////////////

// Pass-by-value with: primitive type, pointer, array
void passByValue(int x, int *y, int z[]) {
    x = 1;
    y = new int;
    *y = 2;
    *z = 3;
    z = new int[3];
    y = new int[2];
    *z = 4;
    *y = 5;
}

// Pass-by-reference with: primitive type, pointer
// Note that body of function is same as body of passByValue
void passByRef(int &x, int * &y, int *z) {
    x = 1;
    y = new int;
    *y = 2;
    *z = 3;
    z = new int[3];
    y = new int[2];
    *z = 4;
    *y = 5;
}

// Pass-by-reference with pointers: good use vs. bad use
void passByRef2(int * &x, int * &y) {
    int z[4];
    z[0] = 3;
    x = new int[2];
    y = z;
}

////////////////////////////////////////////////////////////////////////////////

// Return value: primitive value
int returnVal1() {
    int x = 4;
    return x;
}

// Return value: pointer (bad use)
int *returnVal2() {
    int x = 5;
    return &x;  // note: generates warning, but compiles
}

// Return value: pointer (good use)
int *returnVal3() {
    int *x = new int;
    *x = 6;
    return x;
}

////////////////////////////////////////////////////////////////////////////////

// Helper method for printing arrays
void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main() {

    int a = 1, b = 2, c = 3, d = 4;

    cout << "Swap using pass-by-reference and simulated with pointers" << endl;
    cout << a << "   " << b << "   " << c << "   " << d << endl;

    swap1(a, b);
    swap2(&c, &d);

    cout << a << "   " << b << "   " << c << "   " << d << endl;
    cout << "--------------------------------------------------------" << endl;


    int e[4], f[4];
    for (int i = 0; i < 4; i++)  e[i] = 3*i;
    // f = e;  <---- assignment of arrays not allowed
    for (int i = 0; i < 4; i++) f[i] = e[i];

    cout << "Pass-by-value: primitive, pointer, array" << endl;
    cout << endl << "Initial values of a, b, e, e[]" << endl;
    cout << a << "   " << b << "   " << e << "   ";
    printArr(e, 4);
    cout << endl;

    passByValue(a, &b, e);

    cout << endl << "After calling passByValue(a, &b, e)" << endl;
    cout << a << "   " << b << "   " << e << "   ";
    printArr(e, 4);
    cout << endl;
    cout << "--------------------------------------------------------" << endl;


    cout << "Pass-by-reference: primitive, pointer, array" << endl;

    // passByRef(a, &b, f);  // nope
    // passByRef(a, e, f);   // nope
    int *g = new int[4];
    for (int i = 0; i < 4; i++) g[i] = f[i];


    cout << endl << "Initial values of a, g, g[], f, f[]" << endl;
    cout << a << "   " << g << "   ";
    printArr(g, 4);
    cout << "   " << f << "   ";
    printArr(f, 4);
    cout << endl;

    passByRef(a, g, f);

    cout << endl << "After calling passByRef(a, g, f)" << endl;
    cout << a << "   " << g << "   ";
    printArr(g, 4);
    cout << "   " << f << "   ";
    printArr(f, 4);
    cout << endl;
    cout << "--------------------------------------------------------" << endl;


    int *p = new int;
    int *q = new int;
    *p = *q = 8;

    cout << "Pass-by-reference: pointers (good vs. bad)" << endl;
    cout << endl << "Initial values of p, *p, q, *q" << endl;
    cout << p << "   " << *p << "   " << q << "   " << *q << endl;

    passByRef2(p, q);

    cout << endl << "After calling passByRef2(p, q)" << endl;
    cout << p << "   " << *p << "   " << q << "   " << *q << endl;

    swap1(a, b);

    cout << endl << "After calling swap1(a, b)" << endl;
    cout << p << "   " << *p << "   " << q << "   " << *q << endl;
    cout << "--------------------------------------------------------" << endl;


    int aa, *bb, *cc;

    cout << "Return values" << endl;
    cout << endl << "Initial values of aa, bb, *bb, cc, *cc" << endl;
    cout << aa << "   " << bb << "   " << *bb << "   " << cc << "   " 
         << *cc << endl;

    aa = returnVal1();
    *bb = returnVal1();

    cout << endl << "After assigning aa and *bb to returnVal1()" << endl;
    cout << aa << "   " << bb << "   " << *bb << "   " << cc << "   " 
         << *cc << endl;

    bb = returnVal2();

    cout << endl << "After bb = returnVal2()" << endl;
    cout << aa << "   " << bb << "   " << *bb << "   " << cc << "   " 
         << *cc << endl;

    cc = returnVal3();

    cout << endl << "After cc = returnVal3()" << endl;
    cout << aa << "   " << bb << "   " << *bb << "   " << cc << "   " 
         << *cc << endl;

    return 0;
}


