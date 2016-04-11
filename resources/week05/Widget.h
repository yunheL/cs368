#include <string>
using namespace std;

class Widget {

  static int nextId;
  static int getNextId();
  int id;
  string name;

  public:
    Widget() ;                   
  //  Widget(int) ;                   
    void setId(int) ;              // mutator:  id
    int getId() const;             // accessor: id
    string getName() const;        // accessor: name
   
}; // don't forget the semi-colon
