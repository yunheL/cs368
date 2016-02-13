#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;

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

//option 7
void displayArray(double user_array[], int actual_len)
{
  int i = 0;
  cout << "The elements of the array are: ";
  for(i = 0; i < actual_len; i++)
  {
    cout << user_array[i] << " ";
  }
  cout << "\n";
}

int main()
{
  //declaring variables
  int choice = 0; //variable that holds user choice input
  int actual_len = 0;
  double user_array[100];

  //display the welcome message
  cout << "Welcome!\n";

  //prompt user to enter choice
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
	break;

      case 3:
	break;

      case 4:
	break;

      case 5:
	break;

      case 6:
	break;

      case 7:
        displayArray(user_array, actual_len);

	break;

      case 8:
	break;
    }
  }
  //repeated prompted with choice 1-8
  while(choice < 9 && choice > 0);

  return 0;
}

