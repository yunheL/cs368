/*
 * Example showing the use of manipulators (and simple I/O).
 *
 * Written by Beck Hasti for CS 368
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
