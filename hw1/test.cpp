#include<stdio.h>
#include<stdlib.h>

void mystery(int *a, int &b, int * &c) {
    printf("--\n");
    printf("*a=%d\n", *a);
    printf("b=%d\n",b);
    *a = b;

    printf("---\n");
    printf("a=%p\n", a);
    printf("c=%p\n",c);
    a = c;

    printf("----\n");
    printf("a=%d\n", *a);
    *a = 1;

    printf("-----\n");
    printf("c=%p\n",c); 
    c = new int(3);
    printf("*c=%d\n",*c);
 

    printf("------\n");
    b = 5;
    printf("b=%d\n",b); 
    printf("b pointing to%p\n",&b); 
    //printf("*b=%d\n",*b);
 
}

int main() { 
    int x = 2;
    int *y = new int(4);
    printf("*y is %d\n", *y);

    int *z = new int(6);
    printf("*z is %d\n", *z);

    int **w = &y;
    printf("**w = &y is %d\n", **w);

    printf("&x=%p\n", &x);
    printf("*z=%d\n",*z);
    printf("*w=%d\n",**w);
    //printf("&x=%p *z=%d *w=%d\n", &x, *z, *w);
    mystery(&x, *z, *w);
    //printf("%d %d %d %d\n", x, *y, *z, **w);
    //cout << x << " " << *y << " " << *z << " " << **w << endl;
    return 0;
}
