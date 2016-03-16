#include<stdio.h>
#include<stdlib.h>

void mystery(int *a, int &b, int * &c) {
    *a = b;
    a = c;
    *a = 1;
    c = new int(3);
    b = 5;
}

int main() { 
    int x = 2;
    int *y = new int(4);
    int *z = new int(6);
    int **w = &y;
    mystery(&x, *z, *w);
    printf("%d %d %d %d\n", x, *y, *z, **w);
    //cout << x << " " << *y << " " << *z << " " << **w << endl;
    return 0;
}
