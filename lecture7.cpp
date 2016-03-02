//CS368 Week7 Lecture
//C++ Classes
//Acknowledgements to instructor Deb Deppeler

//Similar to Java classes
//Similar to struct (public embers by default)
//Class(private by default)

class Widget{
	public:  //member function
	string getName() const; //accessor
	int getId() const; //accessor
	string to_string() const; //accessor
	
	void set_name(Const String &S) ; //mutator, pass by reference
	void setId(int); //mutator, pass by value
	widget(); //constructor

	private:	//Data members(fields)
	string name; //non static
	int    id; 
	static int nextId; //static -- must be initiated in the constructor
};

//save in widget.h (aka header file)

//non static don't share the same memory, so each one is a instance
//static shares the same memory

//questions:
//what does the const do?
//difference between static and non-static for methods in java
//static and non static data members
//get ID, return ID? How does it know it is the ID and no "this." is needed?

//A source file *.cpp *.C
//A list of member functions -- no big brackets saying public 

//implement getId()
int Widget::getId() const
{
	return id; //this value must match the Data member definition in the header file
}

String Widget::getName() const
{
	return name;
}

String Widget::to_string() const
{
	return "ID:" + id + "names:" + name;
}

void Widget::setId(int i)
{
	id = i;
}

void Widget::setName(const string &s)
{
	name = s;
}

int Widget::nextId = 0;

int Widget::getNextId()
{
	return nextId++; //post increment
}
