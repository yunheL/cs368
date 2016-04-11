//cs368 week11
//Overloading ++ and --

//prefix: ++x 
//postfix x++
//see example in polynomial.h & polynomial.cpp
//for prefix and postfix, if you overload one then
//usually you will also want to overload the other

//Input redirection
int x;
cin >> x;
Point p;
cout << "enter x y : ";
cin >> p; //if >> is overloaded

//point, if member
in >> p.x;
in >> p.y;

//point, if non-member
int a,b;
in >> a;
in >> b;
p.setX(a);
p.setY(b);

//condition states for input stream
//States: of any input stream
//eof - end of file
//good - every is okay
//bad - cannot recover
//fail - can recover

//Java throws exception and c++ stay silent
//Programmer must check condition state of input stream

//Userful member functions (where in is a stream)
in.eof();
in.good();
in.bad();
in.fail();  //returns true if failbit or badbit are set 
in.clear(); //Clear all error bits, so new input can be read once it 
            //enters into an error state, it stays in there until you 
            //clear it.
in.setstate(state);

//in main.cpp
Point p;
if(cin >> p)
  cout << "p = " << p << p << endl;
  else{
    cout << "Error unddle to read must be int"
    cout
//see the rest in resources how to use clear() and ignore()
//note that clear() does not flush the buffer

//C++ string class
//in string library (#include <string>)
//overload support for relational operators: == != >
//c++ string are mutatble
String s = "hello";
s.index(0);

//C-style strings
//C-style string = an array of characters ending in '\0'
char line[255];
cin.getline(line, 255);