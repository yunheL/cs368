#include "stdafx.h"

int main() {
    cout << "TestWidget_main_start" << endl;

    Widget w; // no-arg constructor is called
    cout   << "Widget w;    w.getId()  = " << w.getId() << endl;
    cout   << "           w.getName()  = " << w.getName() << endl;
    w.setId(3); cout << "w.setId(3);  w.getId()  = " << w.getId() << endl << endl;

    Widget *x;      // no constructor called (YET!)
    cout << "Widget *x;    x = " << x << endl << endl;

    x = new Widget; // no-arg constructor called
    cout << "x = new Widget; (*x).getId() = " << (*x).getId() ;
    cout << "                   x->getId() = " << x->getId() << endl;

    x->setId(13);
    cout << "x->setId(13);   (*x).getId() = " << (*x).getId() ;
    cout << "                  x->getId() = " << x->getId() << endl;

    (*x).setId(11);
    cout << "(*x).setId(11); (*x).getId() = " << (*x).getId() ;
    cout << "                  x->getId() = " << x->getId() << endl;

    //Widget y(15);
    //cout << "Widget y(15);     y.getId() = " << y.getId() << endl;

    typedef Widget * WidgetPtr;
    WidgetPtr y = new Widget;
    cout << y->getId() << endl;

    cout << "TestWidget_main_end" << endl;
    return 0;
}
