#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <fstream>

#include "Student.h"
#include "SortedList.h"

using namespace std;

int main(int argc, char* argv[])
{
  Student st0;
  Student st1(1);
  Student st2(2, 8, 4.0);

  cout << "st2_ID = " << st2.getID() << endl;
  cout << "st2_credit = " << st2.getCredits() << endl;
  cout << "st2_GPA = " << st2.getGPA() << endl;

  st2.update('f', 2);
  cout << "st2_ID = " << st2.getID() << endl;
  cout << "st2_credit = " << st2.getCredits() << endl;
  cout << "st2_GPA = " << st2.getGPA() << endl;

  st1.print();
  st2.print();

  return 0;
}
