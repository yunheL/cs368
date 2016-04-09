#include <iostream>
#include "Student.h"

using namespace std;

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

//accessor - ID
int Student::getID() const
{
  return studentID;
}

//accessor - credits
int Student::getCredits() const
{
  return credits;
}

//accessor - GPA
double Student::getGPA() const
{
  return GPA;
}

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

void Student::print() const
{
  cout << studentID << ',' << credits << ',' << GPA;
}
