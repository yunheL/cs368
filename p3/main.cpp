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
  Student st3(3, 3, 4.0);
  Student st4(4, 4, 4.0);

  cout << "st2_ID = " << st2.getID() << endl;
  cout << "st2_credit = " << st2.getCredits() << endl;
  cout << "st2_GPA = " << st2.getGPA() << endl;

  st2.update('f', 2);
  cout << "st2_ID = " << st2.getID() << endl;
  cout << "st2_credit = " << st2.getCredits() << endl;
  cout << "st2_GPA = " << st2.getGPA() << endl;

  st1.print();
  st2.print();
  cout << endl << "=================================" << endl;

  SortedList list0;

  Student* st2_ptr = &st2;
  Student* st3_ptr = &st3;
  Student* st4_ptr = &st4;

  cout << "insert id=2: " << list0.insert(st2_ptr) << endl;
  cout << "insert id=2: " << list0.insert(st2_ptr) << endl;
  cout << "insert id=4: " << list0.insert(st4_ptr) << endl;

  cout << "insert id=4: " << list0.insert(st4_ptr) << endl;
  cout << "insert id=3: " << list0.insert(st3_ptr) << endl;
  cout << "insert id=3: " << list0.insert(st3_ptr) << endl;

  cout << "remove id=4: " << list0.remove(4) << "; expected: " << &st4 << endl;
  cout << "remove id=2: " << list0.remove(2) << "; expected: " << &st2 << endl;
  cout << "remove id=2: " << list0.remove(2) << "; expected: " << NULL << endl;

  list0.print();
  cout << "find2: " << list0.find(2) << "; expected: " << NULL << endl;
  cout << "find3: " << list0.find(3) << "; expected: " << &st3 << endl;

  return 0;
}
