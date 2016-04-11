#include "stdafx.h"

// CONSTRUCTOR with member initialization list
// equivalent to:
// Widgets = new int[SIZE];
// numItems = 0;
// arraySize = SIZE;
WidgetList::WidgetList(): Widgets(new int[SIZE]), numItems(0), arraySize(SIZE) {
}

// add w to end of WidgetList
void WidgetList::add(int w) {
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


// Return the number of Widgets in the list
int WidgetList::capacity() const {
   return arraySize;
}

// print the list
void WidgetList::print(ostream &output) const {
  cout << "[ " ;
  for ( int i=0; i < numItems; i++ ) 
    cout << Widgets[i] << ", " ;
  cout << "]" << endl;
}

