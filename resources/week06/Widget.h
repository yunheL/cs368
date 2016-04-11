#ifndef WIDGET_H
#define WIDGET_H

#include <string>
using namespace std;

class Widget {

  static int nextId ;
  static int getNextId() ;
  int id;
  string name;

  public:
    Widget() ;                   

    int getId() const;                  // accessor: id
    string getName() const;             // accessor: name
    string to_string() const;           // accessor: id-name

    void setId(int) ;                   // mutator:  id
    void setName(const string&) ;        // mutator: name

   
}; // don't forget the semi-colon

#endif
