// =========================
//  string class
// =========================

#include <iostream>
#include <string>

using namespace std;

int main( int argc, char * argv[ ] ) {

    // A better way to use a string of text
    string nameStr = "deb";
    cout << "My name is " << nameStr << endl;
    cout << "nameStr.size() is " << nameStr.size() << endl;
    cout << "nameStr.length() is " << nameStr.length() << endl;

    // A better way to use a string of text
    string nameStr2 = nameStr + " Deppeler";
    nameStr2[0] = 'D';
    cout << "My name2 is " << nameStr2 << endl;
    cout << "nameStr2.size() is " << nameStr2.size() << endl;
    cout << "nameStr2.length() is " << nameStr2.length() << endl;

    cout << "nameStr.compare(nameStr2) is " << nameStr.compare(nameStr2) << endl;
    cout << "nameStr2.compare(nameStr) is " << nameStr2.compare(nameStr) << endl;

}
