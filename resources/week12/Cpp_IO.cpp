/*
 * Example showing the use of manipulators (and simple I/O).
 *
 * Written by Beck Hasti for CS 368
 *
 * Build command:
 * /s/gcc-5.1/bin/g++ -std=c++11 -g Cpp_IO.cpp 
 *
 * Output:
 * a.out
 * x is 1234, y is 8763.14, str is cs368
 * 1234                 8763.141500 cs368
 * 97215                  12.340000 November
 * Enter a number and a string: 4 hi 
 * x is 4, str is hi
 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int x = 1234;
    double y = 8763.1415;
    string str = "cs368";

    cout << "x is " << x << ", y is " << y <<", str is " << str << endl;

    cout << left << setw(20) << x << " " 
         << right << setw(11) << setprecision(6) << fixed << y << " " 
         << str << endl;

    cout << left << setw(20) << 97215 << " " 
         << right << setw(11) << setprecision(6) << fixed << 12.34 << " " 
         << "November" << endl;

    cout << "Enter a number and a string: ";
    cin >> x >> str;
    cout << "x is " << x << ", str is " << str << '\n';
}
