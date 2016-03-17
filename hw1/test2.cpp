#include<stdio.h>
#include<stdlib.h>

int main()
{
  int *p;
  int a[7]= {1,2,3,4,5,6,7};

  p = a;
  p++;
  p[4] = 8;
}
