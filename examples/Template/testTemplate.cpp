/*
 * This program gives examples of how templates are instantiated and used.
 */
#include <iostream>
#include <string>
#include "fctnTemplates.h"
#include "ObjectWrapper.h"
using namespace std;

int main() {

    int i1 = 5, i2 = 9;
    double d1 = 3.2, d2 = 9.7;
    string s1("hello"), s2("goodbye");

    cout << minimum(i1, i2) << endl;
    cout << minimum<double>(d1, d2) << endl;
    cout << minimum(s1, s2) << endl;

    swapIt(i1, i2);
    swapIt(d1, d2);
    swapIt(s1, s2);

    cout << "After swapIt, i1 = " << i1 << ", i2 = " << i2 << endl;
    cout << "After swapIt, d1 = " << d1 << ", d2 = " << d2 << endl;
    cout << "After swapIt, s1 = " << s1 << ", s2 = " << s2 << endl;

    ObjectWrapper<int> obj1(8);
    ObjectWrapper<double> obj2(3.14);
    ObjectWrapper<string> obj3(s2);

    obj1.setValue(2);
    obj3.setValue(s1);

    cout << obj1.getValue() << endl;
    cout << obj2.getValue() << endl;
    cout << obj3.getValue() << endl;
    cout << s1 << " " << s2 << endl;

    return 0;
}
