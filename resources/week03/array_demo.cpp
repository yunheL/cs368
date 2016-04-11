#include <iostream>  
using namespace std;

void display(int b[] , int c) {
    cout << "[ " ;
    for ( int i=0; i < c ; i++ )
        printf( "%3d", b[i] );

    cout << "]" << endl;
}

void fill_rand_int(int n, int a[]) {
    cout << "generating random values from 0 to " << n << endl;
    for ( int i=0; i < n; i++ ) {
       a[i] = rand()%n;
    }
}

int main() {

    const int LENGTH = 10;
    int a[LENGTH];

    fill_rand_int(LENGTH,a);

    display(a,LENGTH);

    return 0;
}
