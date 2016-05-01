#include <iostream>
#include "Point.h"
using namespace std;

// for Points on the stack
std::ostream & operator<<(std::ostream& out, Point const & p) {
    out << "(" << p.getX() << "," << p.getY() << ")" ;
    return out;
};


istream & operator>>(istream & in, Point & p) {

   int a,b;
   if (in >> a && in >> b) {
     p.setX(a);
     p.setY(b);
   } else {
      in.setstate(ios::failbit);
   }
   return in;
};
