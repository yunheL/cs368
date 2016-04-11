#include "Widget.h"

// STATIC MEMBERS OF THE CLASS
int Widget::nextId = 0;

int Widget::getNextId() {
    return nextId++;
}

// INSTANCE MEMBERS OF THE CLASS
Widget::Widget() : id(getNextId()) {
    name = "Widget_" + to_string(id);
}

int Widget::getId() const { 
    return id; 
}

string Widget::getName() const { 
    return name; 
}

void Widget::setId(int i) { 
    id = i; 
}
