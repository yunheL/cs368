#include "stdafx.h"
#include "WidgetList.h"
#include "Widget.h"

// CONSTRUCTOR with member initialization list
// equivalent to:
// vector<Widget> Widgets; // = new Widget[SIZE];
// numItems = 0;
// arraySize = SIZE;
WidgetList::WidgetList(): numItems(0), arraySize(SIZE) {
}

// DESTRUCTOR must free all allocated memory
//WidgetList::~WidgetList() {
//   delete Widgets;
//}

// add w to end of WidgetList
// pass Widget by const by reference
void WidgetList::add(const Widget &w) {
  Widgets.push_back(w);
  if ( numItems < arraySize ) {
    Widgets[numItems] = w;
    numItems++;
  } else {
    cout << "Array is full... SORRY!" << endl;
  }
}

// Return the number of Widgets in the list
int WidgetList::size() const {
   return numItems;
}


// Return the capacity of Widgets in the list
int WidgetList::capacity() const {
   return arraySize;
}

// Return a string representation of this list
std::string to_string() {
   string s = "[to_string]";
   return s;
}

// print the list
void WidgetList::print(ostream &output) const {
  cout << "[ " ;
  for ( int i=0; i < numItems; i++ ) 
      cout << (Widgets.at(i)).to_string() << ", ";
//    cout << Widgets[i].getName() << ", " ;
  cout << "]" << endl;
}

