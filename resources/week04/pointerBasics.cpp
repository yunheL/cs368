#include <iostream>  
#include "stdio.h"
using namespace std;


int main() {


    int w = 3,x,y,z;
    int *p;    // created but not initialized
    double *q; // created but not initialized
    int *s, *t; // both s and t are pointers to ints
    int *u, v;  // u is ptr, v is not
    int **dblP; // dblP is a pointer to a pointer to an int

    // Assigning values to pointers
    // a pointer variable contains either an address or NULL
    q = NULL;
    p = &w ;  // rarely used, p points to x
              // & is the "address-of" operator
              
    s = new int(2) ; // s points to new allocated (unitialized) memory (like Java)

    t = s ; // assign to value in other ptr of same type

    //s = p ; // would cause a mem leak from int that was created line21
            // would need to delete s; before reassigning from p to s
            // delete(s);
    x=y=z=1;
    u=p;
    v=5;
    dblP = &u;   
    q = new double(1.5);

    printf("w=%d x=%d y=%d z=%d *p=%d *q=%f *s=%d *t=%d *u=%d v=%d **dblP=%d\n",
            w,x,y,z, *p, *q, *s, *t, *u, v, **dblP) ;

    delete s ;  // now points to int created by s 

    return 0;
}
