#include <iostream>  
using namespace std;


int main() {


    int w = 3,x,y,z;
    int a[] = { w, x, y, z};
    int* b[] = { &w, &x, &y, &z};

    cout << "The value of w is w = " << w << endl;
    cout << "The value of x is x = " << x << endl;
    cout << "The value of y is y = " << y << endl;
    cout << "The value of z is z = " << z << endl << endl;

    cout << "The address of w is: &w = " << &w << endl;
    cout << "The address of x is: &x = " << &x << endl;
    cout << "The address of y is: &y = " << &y << endl;
    cout << "The address of z is: &z = " << &z << endl << endl;

    for ( int i=0; i < 4 ; i++ ) 
        cout << "The value of a[" << i << "] = " << a[i] << endl;

    cout << endl;
    for ( int i=0; i < 4 ; i++ ) 
        cout << "The address of a[" << i << "] is &a[" << i <<  "]=" << &a[i] << endl;
    cout << endl;

    cout << "*intPtr is a pointer to an int, and is assiged the address of w" << endl;
    cout << "*intPtr = &w;" << endl;

    int *intPtr = &w;
    cout << "intPtr = " << intPtr << endl << endl;

    cout << "!!! DEREFERENCE intPtr TO GET THE VALUE THAT It POINTS TO !!!" << endl;
    cout << "*intPtr = " << *intPtr << endl;

    cout << "We can view the address of intPtr" << endl;
    cout << "&intPtr = " << &intPtr << endl;
    cout << "We can save the address of intPtr in a new pointer variable." << endl;
    cout << "**intPtrPtr = &intPtr;" << endl;
    cout << "**intPtrPtr is a pointer to a pointer to an int." << endl;

    int **intPtrPtr = &intPtr;
    cout << "The value in intPtrPtr = " << intPtrPtr << endl;
    cout << "The value in what is pointed to by intPtrPtr: *intPtrPtr = " << *intPtrPtr << endl;
    cout << "The value in what is pointed to by what is pointed to by intPtrPtr: **intPtrPtr = " << **intPtrPtr << endl << endl;

    cout << "We can view the address of intPtrPtr" << endl;
    cout << "&intPtrPtr = " << &intPtrPtr << endl;
    cout << endl << "***intPtrPtr = &intPtrPtr;" << endl;
    cout << "We can save the address of intPtrPtr in a new pointer variable." << endl;
    int ***intPtrPtrPtr = &intPtrPtr;
    cout << "***intPtrPtrPtr is a pointer to a pointer to a pointer to an int." << endl;
    cout << "*intPtrPtrPtr = " << *intPtrPtrPtr << endl;
    cout << "**intPtrPtrPtr = " << **intPtrPtrPtr << endl;
    cout << "***intPtrPtrPtr = " << ***intPtrPtrPtr << endl << endl;


    // Dereference the pointer to x
    cout << "intPtr = " << intPtr << endl ;
    cout << "*&intPtr = " << *&intPtr << endl;
    cout << "&*intPtr = " << (&*intPtr) << endl ;
    cout << "*intPtrPtr = " << *intPtrPtr << endl << endl;

    cout << "&intPtr = " << &intPtr << endl ;
    cout << "intPtrPtr = " << intPtrPtr << endl << endl;

    return 0;
}
