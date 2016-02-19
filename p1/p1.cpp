#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;

void displayArray(double user_array[], int actual_len);

void displayChoicePrompt()
{
  //prompt user to enter choice
  printf("1) Feed array input\n");
  printf("2) Determine the minimum element in the array\n");
  printf("3) Determine the maximum element in the array\n");
  printf("4) Sort the array of integers\n");
  printf("5) Determine the average of the elements in the array\n");
  printf("6) Randomly generate array elements within a specific range\n");
  printf("7) Print the elements of the array\n");
  printf("8) Exit program\n");
  printf("Enter your choice: "); //TODO - should I insert "\n" here?
}

//option 1
void feedArrayInput(double user_array[], int actual_len)
{
  //feed the elements of the array
  int i = 0;
  cout << "Enter the elements of the array: ";

  if(actual_len == 0)
  {
    cout << "\n";
  }

  for(i = 0; i < actual_len; i++)
  {
    cin >> user_array[i];
  }

}

//option 2
double findMin(double user_array[], int actual_len)
{
  double min = user_array[0];

  int i = 0;
  for(i = 1; i < actual_len; i++)
  {
    if(user_array[i] < min)
    {
      min = user_array[i]; 
    }
  }
  return min;
}

//option 3
double findMax(double user_array[], int actual_len)
{
  double max = user_array[0];

  int i = 0;
  for(i = 1; i < actual_len; i++)
  {
    if(user_array[i] > max)
    {
      max = user_array[i]; 
    }
  }
  return max;
}

//option 4
void selectionSort(double user_array[], int actual_len)
{
  int i = 0; //outer loop indicates the postion to fill next
  //int j = 0; //inner loop to find the smallest value in the unsorted part
  int min_Index = 0;//index of minimum value in the unsorted part
  double min = 0;

  for(i = 0; i < actual_len; i++)
  {
    min_Index = i;
    int j = i + 1;
    for(; j < actual_len; j++)
    {
      if(user_array[j] < user_array[min_Index])
      {
        min_Index = j;
      }
    }
    min = user_array[min_Index];
    user_array[min_Index] = user_array[i];
    user_array[i] = min;
  }
}

//option 5
double computeAve(double user_array[], int actual_len)
{
  double sum = user_array[0];
  int i = 0;
  for(i = 1; i < actual_len; i++)
  {
    sum = sum + user_array[i];
  }
  
  return sum/(double)(actual_len);
}

//option 6
void randomArray(int numEle, double a, double b, double random_array[])
{
  //srand(1000);

  int i = 0;
  for(i = 0; i < numEle; i++)
  {
    random_array[i] = (b - a) * ((double)rand()/(double)RAND_MAX) + a;
  }
}

//option 7
void displayArray(double user_array[], int actual_len)
{
  int i = 0;
  cout << "The elements of the array are: ";
  for(i = 0; i < actual_len; i++)
  {
    printf("%.3f ", user_array[i]);
    //cout << user_array[i] << " ";
  }
  cout << "\n";
}

//option 8
void displayExitMsg()
{
  cout << "Exiting the program!\n" << "Thank you!\n";
}

int main()
{
  //declaring variables
  int choice = 0; //variable that holds user choice input
  int actual_len = 0;
  double user_array[100];
  double random_array[100];
  double max = 0;
  double min = 0;
  double ave = 0;
  int numEle = 5;
  double a = 0;
  double b = 10;

  srand(1000);

  //display the welcome message
  cout << "Welcome!\n";
  do{
    displayChoicePrompt();
    cin >> choice;
    //printf("choice is: %d\n", choice); //TODO - remove debug code

    switch(choice)
    {
      //feed array input
      case 1:
	//feed the length of the array
	cout << "Enter the number of elements in the array: ";
	cin >> actual_len;

        //TODO - flush the cin buffer
	//cin.clear();
	//cin.ignore(INT_MAX);
	feedArrayInput(user_array, actual_len);
	break;

      case 2:
        min = findMin(user_array, actual_len);
        cout << "Minimum element in array: " << min << "\n";
	break;

      case 3:
	max = findMax(user_array, actual_len);
        cout << "Maximum element in array: " << max << "\n";
	break;

      case 4:
        selectionSort(user_array, actual_len);
        displayArray(user_array, actual_len);
	break;

      case 5:
	ave = computeAve(user_array, actual_len);
        cout << "The average of the elements are: " << ave << "\n";
	break;

      case 6:
 	cout << "Enter the number of elements in the array: ";
	cin >> numEle;

	cout << "Enter the lower range for the elements: ";
	cin >> a;

	cout << "Enter the upper range for the elements: ";
	cin >> b;

	randomArray(numEle, a, b, random_array);
	displayArray(random_array, numEle);
	break;

      case 7:
        displayArray(user_array, actual_len);

	break;

      case 8:
        displayExitMsg();
        choice = 9;
	break;
    }
  }
  //repeated prompted with choice 1-8
  while(choice < 9 && choice > 0);

  return 0;
}

