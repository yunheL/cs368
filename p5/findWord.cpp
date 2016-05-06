///////////////////////////////////////////////////////////////////////////////
////                   ALL STUDENTS COMPLETE THESE SECTIONS
//// Title:            cs368 p5
//// Files:            findWord.cpp
//// Semester:         cs368 Spring 2016
////
//// Author:           Yunhe Liu
//// Email:            liu348@wisc.edu
//// CS Login:         yunhe
//// Lecturer's Name:  Deb
//// Lab Section:      (your lab section number)
////
////////////////////// PAIR PROGRAMMERS COMPLETE THIS SECTION ////////////////////
////
////                   CHECK ASSIGNMENT PAGE TO see IF PAIR-PROGRAMMING IS ALLOWED
////                   If pair programming is allowed:
////                   1. Read PAIR-PROGRAMMING policy (in cs302 policy) 
////                   2. choose a partner wisely
////                   3. REGISTER THE TEAM BEFORE YOU WORK TOGETHER 
////                      a. one partner creates the team
////                      b. the other partner must join the team
////                   4. complete this section for each program file.
////
//// Pair Partner:     (name of your pair programming partner)
//// Email:            (email address of your programming partner)
//// CS Login:         (partner's login name)
//// Lecturer's Name:  (name of your partner's lecturer)
//// Lab Section:      (your partner's lab section number)
////
////////////////////// STUDENTS WHO GET HELP FROM OTHER THAN THEIR PARTNER //////
////                   must fully acknowledge and credit those sources of help.
////                   Instructors and TAs do not have to be credited here,
////                   but tutors, roommates, relatives, strangers, etc do.
////
//// Persons:         Deb, Mohit, Nivetha, thanks for the great semester!
////                   
////
//// Online sources: Google, cplusplus.com, 
//                   CS368 Course Assignment page (P5) file I/O example 
////                 
////////////////////////////// 80 columns wide //////////////////////////////////
#include "stdio.h"
#include "stdlib.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

/*
 * This class takes in a word and a text file and count the occurence
 * of word in the file and print out the line at the same time.
 * <p>Bugs: unknown
 * @author Yunhe Liu
 */

/*
 * This method takes in a word and a file_name, opens the file and
 * count the occurence of the word in the file and print out the line.
 * @param (file_name) text file name
 * @param (word) the word to be found
 * @return the number of occurence of the word
 */
int find(string& file_name, string& word)
{
  ifstream myFile(file_name.c_str());
  int count = 0; //count the occurence
  int i = 0;     //loop counter
  bool exist = false; //true if word occurs in line
  int line_number = 0; //line number in the test

  //make sure file is successfully opened
  if(myFile)
  {
    string line;//holds the current line
	 
    cout << "Searching for '" << word << "' in file 'test.txt'" << endl; 

    //keep iterating until hit the end of the file
    while (!getline(myFile, line).eof()) 
    {
      //record the current line number
      line_number++;

      //cannot be any occurence if the line is shorter than the word
      if(line.length() >= word.length())
      {
        //iterate through line to find occurences
	for(i = 0; i < line.length() - word.length(); i++)
	{
          //notice there can be multiple occurence in the line
	  if(line.substr(i, word.length()).compare(word) == 0)
	  {
    	    count++;
            //change exist to true so this line will be printed
	    exist = true;
	  }
	}
       
        //only print the line with the occurence once
	if(exist)
	{
	  cout << line_number << " : " << line << endl;
	}
      }
      //change exist back to false before going to a new line
      exist = false;
    }	
  }
  //Oops cannot open file
  else {
    cerr << "File '" << file_name << "' could not be opened" << endl;
    count = -1; //return -1 on error
  }
  //and NEVER forget to close the file
  myFile.close();
  return count;
}

/*
 * This method prompt user to enter correct commendline information. Call
 * find() to run its functionalities and print out the number of the
 * word occurence in the file.
 * @param (argv[1]) word
 * @param (argv[2]) file_name
 * @return 0 on success, otherwise -1
 */
int main(int argc, char* argv[])
{
  //make sure user enters 3 args
  if(argc != 3)
  {
    cout << "Proper usage: findWord <word> <file>" << endl;
    cout << "where " << endl;
    cout << "  <word> is a sequence of non-whitespace characters" << endl;
    cout << "  <file> is the file in which to search for the word" << endl;
    cout << "example: findWord the test.txt" << endl;

    return -1; //return -1 on error
  } 
 
  //Read CommandLine
  string word = argv[1];
  string file_name = argv[2];

  //call find() to take care of everything
  int occur = find(file_name, word);

  //return -1 
  if (occur == -1) return -1;

  //print out the total occurence
  cout << "# occurrences of " << "'" << word << "'" << " = " << occur << endl;

  //return 0 on success
  return 0;
}
//version control: correct version for submission -5/6/16 5pm
