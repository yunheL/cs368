#include <iostream>  
#include <random>
#include <time.h>
using namespace std;

void printIntArray(int a[], int n) {
    for( int i=0; i < n; i++ )
       cout << a[i] << " ";
    cout << endl;
}

void printDoubleArray(double a[], int n) {
    for( int i=0; i < n; i++ )
       cout << a[i] << " ";
    cout << endl;
}

// argc - number of command line arguments
// argv - array of char strings (the command-line args)
int main(int argc, char ** argv) {
    srand(time(NULL));  // to get random (unseeded)

    const int N = 10;
    int ra[N];
    double rda[N];
    int lo = 10;
    int hi = 15;
    
    // set the distribution of random values
    std::uniform_real_distribution<double> unif(lo,hi);

    // random number generator
    std::default_random_engine re; 

    for ( int i=0; i < N; i++ ) {
       ra[i]  = rand() % N;  // [0,N)
       rda[i] = unif(re);    // [lo,hi)
    }

    printIntArray(ra,N);
    printDoubleArray(rda,N);

    return 0;
}
