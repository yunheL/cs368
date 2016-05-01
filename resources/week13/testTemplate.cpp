/*
 * This program gives examples of how templates are instantiated and used.
 */
#include <iostream>
#include <string>
#include "fctnTemplates.h"
#include "ObjectWrapper.h"
using namespace std;

int main() {

    int x = 5, y = 9;
    double c = 3.2, d = 9.7;
    string s("hello"), t("goodbye");

    cout << minimum(x, y) << endl;
    cout << minimum<double>(c, d) << endl;
    cout << minimum(s, t) << endl;

    swapIt(x, y);
    swapIt(c, d);
    swapIt(s, t);

    cout << "After swapIt, x = " << x << ", y = " << y << endl;
    cout << "After swapIt, c = " << c << ", d = " << d << endl;
    cout << "After swapIt, s = " << s << ", t = " << t << endl;

    ObjectWrapper<int> o1(8);
    ObjectWrapper<double> o2(3.14);
    ObjectWrapper<string> o3(t);

    o1.setValue(2);
    o3.setValue(s);

    cout << o1.getValue() << endl;
    cout << o2.getValue() << endl;
    cout << o3.getValue() << endl;
    cout << s << " " << t << endl;

    // test swapIt with int,double
    // swapIt(x,d); // no matching function for call to swapIt(int&, double&)
    //swapIt<double>(x,d); //  no matching function for call to swapIt(int&, double&)
    swapCast(x,d); 
    cout << "after swapCast(x,d): x = " << x << " and d = " << d << endl;

    return 0;
}
