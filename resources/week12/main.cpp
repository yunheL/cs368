#include <iostream>
#include <istream>
#include <string>
#include <memory>
#include "Point.h"

using namespace std;

int main() {

   int a;  
   cout << "Enter an int " << endl;
   cin >> a;
   while ( true ) {
       cout << "a = " << a << " ; " ;
       if (cin.fail()) { cout << " fail" << endl; }
       if (cin.bad()) cout << " bad" << endl;
       if (cin.eof()) cout << " eof" << endl;
       if (cin.good()) {
           cout << " good" << endl;
           std::cin.ignore(1000, '\n');
           break;
       }
       cin.clear();
       std::cin.ignore(1000, '\n');
       cout << "Enter an int " << endl;
       cin >> a;
   }
   cout << "a = " << endl;
   if (cin.fail()) cout << "fail" << endl;
   if (cin.bad()) cout << "bad" << endl;
   if (cin.eof()) cout << "eof" << endl;
   if (cin.good()) cout << "good" << endl;

   // c-style string example
   cout << "Enter your name (char array): " ;
   char line[255];
   //cin >> line;        // reads until whitespace
   cin.getline(line,80); // reads until new line
   cout << "Your name is: " << line << endl;

   // string class example
   cout << "Enter your address (string): ";
   string address;
   if (getline(cin,address)) {
       cout << "address = " << address << endl;
   } else { 
       cout << "unable to read address" << endl;
   }

   // Read n characters into a string variable
   a = ( a < 0 ) ? -a : a ;
   cout << "Enter " << a << " characters: " ;
   char charArray[a+1];
   if ( cin.getline(charArray,a+1) ) {
       cout << "charArray = [" << charArray << "]" << endl;
   } else {
       cout << "Too many characters.  Asked for " << a << " characters" << endl;
       cin.clear();
       cin.ignore(1000,'\n'); // get rid of rest of line of input
   }

}

// For more examples:
// c-style vs string
// http://www.tutorialspoint.com/cplusplus/cpp_strings.htm
//
// Basic IO
// http://www.tutorialspoint.com/cplusplus/cpp_basic_input_output.htm
