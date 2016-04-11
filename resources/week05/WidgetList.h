#include <iostream>
using namespace std;

class WidgetList {

  public:
    WidgetList();                      // constructor
    void add(int w);                   // add to end
    int size() const;                  // return number of Widgets in the list
    int capacity() const;              // return current space in the list
    void print(ostream &output) const; // print the list

  private:
    static const int SIZE = 10;        // initial size of array
    int *Widgets;                      // array of Widget
    int numItems;                      // number of items current in the array
    int arraySize;                     // the current size of the array

}; // don't forget the semi-colon here
