#include<stdio.h>
#include<stdlib.h>

int main()
{
  int arr[8]= {6,4,2,1,3,5,7,8};

  for(int i = 0; i<8;i++)
  {
    *(arr+i) = *arr+i;
  }

  for(int i=0; i<8; i++ )
  {
    printf("%d ", arr[i]);
  }
}
