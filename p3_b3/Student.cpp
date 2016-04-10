///////////////////////////////////////////////////////////////////////////////
//////                   ALL STUDENTS COMPLETE THESE SECTIONS
////// Main Class File:  main.cpp
////// File:             Student.cpp
////// Semester:         cs368 Spring 2016
//////
////// Author:           Yunhe Liu
////// CS Login:         yunhe
////// Lecturer's Name:  Deb
////// Lab Section:      
//////
//////////////////////// PAIR PROGRAMMERS COMPLETE THIS SECTION ////////////////////
//////
////// Pair Partner:     (name of your pair programming partner)
////// Email:            (email address of your programming partner)
////// CS Login:         (partner's login name)
////// Lecturer's Name:  (name of your partner's lecturer)
////// Lab Section:      (your partner's lab section number)
//////
//////////////////////// STUDENTS WHO GET HELP FROM OTHER THAN THEIR PARTNER //////
//////                   fully acknowledge and credit all sources of help,
//////                   other than Instructors and TAs.
//////
////// Persons:          Identify persons by name, relationship to you, and email.
//////                   Describe in detail the the ideas and help they provided.
//////
////// Online sources:   Google, piazza, stackoverflow 
//////////////////////////////// 80 columns wide ///////////////////////////////


/* This class implements the Student.h file.
 * <p> Bugs: Memory leak
 * @Author: Yunhe Liu
 */


#include <iostream>
#include "Student.h"

using namespace std;

/*
 * constructor
 */
//default no-arg constructor
Student::Student() :
studentID(0), credits(0), GPA(0.0){
  cout<< "default no-arg constructor" << endl;
}

//default one-arg constructor
Student::Student(int ID) :
studentID(ID), credits(0), GPA(0.0){
  cout<< "default 1-arg constructor" << endl;
}

//default three-arg constructor
Student::Student(int ID, int cr, double grPtAv) :
studentID(ID), credits(cr), GPA(grPtAv){
  cout<< "default 3-arg constructor" << endl;
}

/*
 * Big three
 */
//Copy constructor
Student::Student(const Student &S) :
studentID(S.studentID), credits(S.credits), GPA(S.GPA)
{
  cout<< "student copy constructor" << endl;
}

//deconstructor
Student::~Student()
{
  cout<<"student destructor" << endl;
}

//copy assignment
Student & Student::operator=(const Student &S)
{
  cout << "student assignment" << endl;
  //check for self-assignment - if so, do nothing
  if(this == &S)
    return *this;

  else
  {
    studentID = S.studentID;
    credits = S.credits;
    GPA = S.GPA;
  }
  return *this;
}

/*
 * @return studentID
 */
//accessor - ID
int Student::getID() const
{
  return studentID;
}

/*
 * @return credits
 */
//accessor - credits
int Student::getCredits() const
{
  return credits;
}

/*
 * @return GPA
 */
//accessor - GPA
double Student::getGPA() const
{
  return GPA;
}

/*
 * update student's GPA and credit with additional
 * grade and cr
 */
//update()
void Student::update(char grade, int cr)
{
  float numericalGrade = 0.0;
  float add_points = 0.0;
  float old_points = 0.0;
  float total_points = 0.0;
  int total_cr = 0;
  float updatedGPA = 0.0;

  //convert letter grade to numerical grade
  if(grade == 'A' || grade == 'a')
    numericalGrade = 4.0;
  else if(grade == 'B' || grade == 'b')
    numericalGrade = 3.0;
  else if(grade == 'C' || grade == 'c')
    numericalGrade = 2.0;
  else if(grade == 'D' || grade == 'd')
    numericalGrade = 1.0;
  else if(grade == 'F' || grade == 'f')
    numericalGrade = 0.0;

  //calculate the additional points
  add_points = numericalGrade * cr;
  //cout << "add_points is " << add_points << endl;

  //calculate the old points
  old_points = GPA * credits;
  //cout << "old_points is " << old_points << endl;

  //calculate the total points
  total_points = add_points + old_points;
  //cout << "total_point is " << total_points << endl;

  //calculate the total credits
  total_cr = credits + cr;
  //cout << "total_cr is " << total_cr << endl;

  //calculate the updated GPA
  updatedGPA = ((float)(total_points))/((float)(total_cr));
  //cout << "updatedGPA is " << updatedGPA << endl;

  //upate GPA
  GPA = updatedGPA;

  //update Credit
  credits = credits + cr;
}

/*
 * formatted print student info
 */
void Student::print() const
{
  cout << studentID << ',' << credits << ',' << GPA;
}


