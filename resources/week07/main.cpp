#include "stdafx.h"

// Used to test creation of Widget
void testWidget() {
    cout << "TestWidget_main_start" << endl;

    Widget w; // no-arg constructor is called
    cout   << "Widget w;    w.getId()  = " << w.getId() << endl;
    cout   << "           w.getName()  = " << w.getName() << endl;
    w.setId(3); 
    cout << "w.setId(3);  w.getId()  = " << w.getId() << endl << endl;

    Widget *x;      // no constructor called (YET!)
    cout << "Widget *x;    x = " << x << endl << endl;

    x = new Widget; // the no-arg constructor is called
    cout << "x = new Widget; (*x).getId() = " << (*x).getId() ;
    cout << "                  x->getId() = " << x->getId() << endl;

    x->setId(13);
    cout << "x->setId(13);   (*x).getId() = " << (*x).getId() ;
    cout << "                  x->getId() = " << x->getId() << endl;

    (*x).setId(11);
    cout << "(*x).setId(11); (*x).getId() = " << (*x).getId() ;
    cout << "                  x->getId() = " << x->getId() << endl;

    delete x;  // free the memory that was allocated earlier
    cout << "TestWidget_main_end" << endl;
}

void testWidgetList() {
  cout << "TestWidgetList_start" << endl;
  WidgetList wlist;
  wlist.print(cout);
  Widget w;
  wlist.add(w);
  wlist.print(cout);
  //cout << "wlist.to_string() = " << wlist.to_string() << endl;
  cout << "TestWidgetList_end" << endl;
}

int main() {

    testWidget();
    testWidgetList();

    typedef Widget * WidgetPtr;
    WidgetPtr y = new Widget;
    cout << y->getId() << endl;
    delete y;

    return 0;
}
