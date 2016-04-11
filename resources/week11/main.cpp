#include <iostream>
#include "Point.h"

using namespace std;

int main() {

   // c++11
   // int* ptr = nullptr;
   // ptr = new int;
   int * ptr = NULL;
   ptr = new int;

   cout << "ptr = " << ptr << endl;
   cout << "*ptr = " << *ptr << endl;
   cout << "&ptr = " << &ptr << endl;


   Point p1;
   p1.setX(1);
   p1.setY(2);
   cout << "p1.getX() = " << p1.getX() << endl ;
   //TODO: fix this: 
   cout << "p1 = " ;
   cout << p1 ;
   cout << endl;

   Point *p2 = new Point(1,2);
   cout << "p2 = " << p2 << endl;
   cout << "*p2 = ";
   cout << *p2 ;
   cout << endl;


   // test error for point
   // causes error: invalid conversion from "const char*" to "int"
   Point p;
   cout << "Enter x and y for point p: " ;
   if (cin >> p) 
   	cout << p << endl;
   else {
        cout << "Invalid x and y.  They must be int values." << endl;
	cin.clear();
        cin.ignore(1000,'\n'); // hopefully 1000 is enough to clear buffer
   }



   // c-style string example
   cout << "Enter your name: " ;
   char line[255];
   //cin >> line;        // reads until whitespace
   cin.getline(line,80); // reads until new line
   cout << "Your name is: " << line << endl;


}
