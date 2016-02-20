///////////////////////////////////////////////////////////////////////////////
////                   ALL STUDENTS COMPLETE THESE SECTIONS
//// Title:            368 p1
//// Files:            p1.cpp
//// Semester:         Spring 2016
////
//// Author:           Yunhe Liu
//// Email:            liu348@wisc.edu
//// CS Login:         yunhe
//// Lecturer's Name:  Deb Deppeler
//// Lab Section:      N/A 
////
////////////////////// STUDENTS WHO GET HELP FROM OTHER THAN THEIR PARTNER //////
////                   must fully acknowledge and credit those sources of help.
////                   Instructors and TAs do not have to be credited here,
////                   but tutors, roommates, relatives, strangers, etc do.
////
//// Persons:          Identify persons by name, relationship to you, and email.
////                   Describe in detail the the ideas and help they provided.
//
////                   I went to Deb's lecture and it was a great time! :)
//
//// Online sources:   avoid web searches to solve your problems, but if you do
////                   search, be sure to include Web URLs and description of 
////                   of any information you find.
//
//                     piazza <https://piazza.com/class/ij1w7j04cwl101?cid=83>
//                     stackoverflow<http://stackoverflow.com/questions/
//                     10776073/random-double-between-min-and-max>
////////////////////////////// 80 columns wide /////////////////////////////////
//CFM: this is the correct file to submit.
/*
 * This class is the only class for this program and includes the
 * implementation for all the functionalities.
 * @Author: Yunhe Liu
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;

//function declaration
void displayArray(double user_array[], int actual_len);

/*
 * This funciton prompt user choices they have in a formatted manner.
 */
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
  printf("Enter your choice: "); 
}

/*
 * This function fill array elements. 
 * @ Param: Take in the array to write to and the number of elements to write
 */
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

/*
 * This function finds the minimum value in the array by linear search.
 * @ Param: Take in the array and the number of elements in the array
 */
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

/*
 * This function finds the maximum value in the array by linear search.
 * @ Param: Take in the array and the number of elements in the array
 */
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

/*
 * This function sorts the array by selection sort
 * * @ Param: Take in the array and the number of elements in the array
 */
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

/*
 * This function computers the average of the array
 * @ Param: Take in the array and the number of elements in the array
 */
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

/*
 * This function generates random numbers to fill in the array.
 * @ Param: Take in the array and the number of elements in the array,
 *          and the lower and upper bound of the elements and the
 *          array to write to.
 */
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

/*
 * This method display the array in a formatted manner
 * @ Param: Take in the array and the number of elements in the array.
 */
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

/*
 * This method displays exit message.
 */
//option 8
void displayExitMsg()
{
  cout << "Exiting the program!\n" << "Thank you!\n";
}

int main()
{
  //declaring variables
  int done = 0;             //boolean to see whether want to exit
  int choice = 0;           //variable that holds user choice input
  int actual_len = 0;       //length of the array
  double user_array[100];   //array base address (size of array is 100)
  double max = 0;           //max value in the array
  double min = 0;           //min value in the array
  double ave = 0;           //average of the array
  double a = 0;             //lower bound for random generator 
  double b = 10;            //upper bound for random generator

  srand(1000);              //random number generator with 1000 as seed

  //display the welcome message
  cout << "Welcome!\n";
  do{
    displayChoicePrompt();
    //read in choice entered by user
    cin >> choice;

    //switch based on the choice entered
    switch(choice)
    {
      //feed array input
      case 1:
	//feed the length of the array
	cout << "Enter the number of elements in the array: ";
	cin >> actual_len;

        //flush the cin buffer
	//cin.clear();
	//cin.ignore(INT_MAX);
	feedArrayInput(user_array, actual_len);
	break;

      //call methoed to find the minimum value of the array
      case 2:
        min = findMin(user_array, actual_len);
        printf("Minimum element in array: %.3f ", min);
        cout << "\n";
	break;

      //call method to find the maximum value of the array
      case 3:
	max = findMax(user_array, actual_len);
        printf("Maximum element in array: %.3f ", max);
        cout << "\n";
	break;

      //call methoed to selection sort the array
      case 4:
        selectionSort(user_array, actual_len);
        displayArray(user_array, actual_len);
	break;

      //call method to find the average of the array
      case 5:
	ave = computeAve(user_array, actual_len);
        printf("The average of the elements are: %.3f ", ave);
        cout << "\n";
	break;

      //call method to generate the random array with upper bound b and
      //lower bound a and with acutal_len elements
      case 6:
 	cout << "Enter the number of elements in the array: ";
	cin >> actual_len;

	cout << "Enter the lower range for the elements: ";
	cin >> a;

	cout << "Enter the upper range for the elements: ";
	cin >> b;

	randomArray(actual_len, a, b, user_array);
	displayArray(user_array, actual_len);
	break;

      //call method to print the array in a formatted 
      case 7:
        displayArray(user_array, actual_len);

	break;
      
      //call method to display exit message and set the done boolean to true
      case 8:
        displayExitMsg();
        done = 1;
	break;
    }
  }
  //repeated prompted with choice 1-8
  while(choice < 9 && choice > 0 && done != 1);
 
  //detec invalid input and terminate the program 
  if(choice > 8 || choice < 1)
  {
    cout << "Invalid input, program terminate." << "\n";
    return -1;
  }

  //return 0 when exit correctly
  return 0;
}

