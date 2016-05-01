#include <iostream>
using namespace std;

class Point {

    friend std::ostream & operator<<(std::ostream & out, Point const & p);
    friend std::istream & operator>>(std::istream & in, Point & p);

  public:

    // constructors
    Point(): x(0), y(0) { }
    Point(int a, int b): x(a), y(b) { }
    
    // accessors
    int getX() const { return x; }
    int getY() const { return y; }

    // mutators
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    
 private:
    
    int x, y;
};
