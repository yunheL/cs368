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
