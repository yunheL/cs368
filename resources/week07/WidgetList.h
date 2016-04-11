#ifndef WIDGETLIST_H
#define WIDGETLIST_H

#include <iostream>
#include <vector>
#include "Widget.h"
using namespace std;

class WidgetList {

  public:
    WidgetList();                      // constructor
//    ~WidgetList();                     // destructor
    void add(const Widget &w);         // add to end
    int size() const;                  // return number of Widgets in the list
    int capacity() const;              // return current space in the list
    void print(ostream &output) const; // print the list
    std::string to_string() const;     // c++11 to_string

  private:
    static const int SIZE = 10;        // initial size of array
    vector<Widget> Widgets;            // vector of Widget
    int numItems;                      // number of items current in the array
    int arraySize;                     // the current size of the array

}; // don't forget the semi-colon here

#endif
