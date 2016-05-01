/*
 * overloadIO.cpp
 *
 * Example showing overloading I/O operators
 * (in a very simple way)
 *
 * Written by Beck Hasti for CS 368
 */
#include <iostream>

using namespace std;


/*
 * The Point class represents integer points (x, y)
 */
class Point {

    friend ostream & operator<<(ostream & out, const Point & p);
    friend istream & operator>>(istream & in, Point & p);

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


/*
 * Overload <<
 */
ostream & operator<<(ostream & out, const Point & p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}


/*
 * Overload >> 
 */
istream & operator>>(istream & in, Point & p) {
    char ch;
    int x, y;

    in.get(ch);
    while (ch == ' ' || ch == '\n' || ch == '\t')
        in.get(ch);

    if (ch != '(') { 

        return in;
    }

    in >> x;         // read in x value

    in.get(ch);
    while (ch == ' ' || ch == '\n' || ch == '\t')
        in.get(ch);

    if (ch != ',') {

        return in;
    }
	
    in >> y;         // read in y value

    in.get(ch);
    while (ch == ' ' || ch == '\n' || ch == '\t') 
        in.get(ch);

    if (ch != ')') {

        return in;
    }

    // only after the entire point has been read in successfully do we update p
    p.x = x;
    p.y = y;
    return in;
}


/*
 * Prompts user for two points and displays the results.
 */
int main() {
    Point p, q;

    cout << "enter a point: ";
    cin >> p;
	
    cout << "you entered: " << p << endl;

    cout << "enter another point: ";
    cin >> q;
	
    cout << "you entered: " << q << endl;

    return 0;
}
