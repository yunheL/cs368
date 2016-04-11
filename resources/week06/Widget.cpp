#include "Widget.h"
#include <iostream>
using namespace std;

// STATIC MEMBERS OF THE CLASS
int Widget::nextId = 0;

int Widget::getNextId() {
    return nextId++;
}

// INSTANCE MEMBERS OF THE CLASS
Widget::Widget() : id(getNextId()) {
    name = "Widget_" + std::to_string(id);
}

int Widget::getId() const { 
    return id; 
}

string Widget::getName() const { 
    return name; 
}

string Widget::to_string() const { 
    return "ID:" + std::to_string(id) + " name:" + name; 
}

void Widget::setId(int i) { 
    id = i; 
}

void Widget::setName(const string &n) {
    name = n;
}


