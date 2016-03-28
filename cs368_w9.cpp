/*
 * CS368 Week9 notes
 */
 
//Other operators that you can overload

//Why? - So user defined types can take advantage (use) build-in operator
//Polynomial: y = 4x^4 + 2x^3 - 3x^2 + x + 11;
//coefficient [4.0, 2.0, -3.0, 1.0, 11.0]

//Cannot be overloaded: . .*   ? :  ::
//Can but should not overload: && || , & |
//arithmatic: + - * / %
//assignment: += -= *= /= %=
//bit: ~(not) ^(xor)
//relational: == != > < <= >=
//unary: + - ++(prefix) (postfix)(++) --
//shift: << >>
//function: ()
//access by index: []
//new: new [] 
//delete: delete[]

// Note - We cannot change operator precedence
//		- We cannot change operator associativity (left to right)

// Do not overload just because you can 
// 		- JBYCDMYS (Just because you can does means you should)
// Member function vs non-member function free function

list.equals(otherlist)	   //Java: member function
equals(mylist, otherlist)  //Java: non-member functions

//lhs + rhs
//-------------------------
//Polynomial.h

//assignment operator overloading
const Polynomial & operator = (const Polynomial & rhs);
const Polynomial & operator += (const Polynomial & rhs);

//Polynomial.cpp
Polynomial & Polynomial::operator +=(const Polynomial& rhs)
{
	//represent result of adding 2 polynomials together
	//(x^2 - 1) + (3x^2 - x + 10) 

}

//supported code
Polynomial p1 ([-3, 0 , 10]);
Polynomial p2 ([1, 0, -1]);

p1 += p2; //only works if operator += is defined correctly

//Equality - as a non-member function
//(Polynomial.cpp)
bool operator == (const Polynomial & lhs, const Polynomial & rhs)
{
	if(lhs.size != rhs.size) return false;
	
	for(int i =  0; i < lhs.size; i++)
	{
		if(lhs.coefs[i] != rhs.coefs[i])
	    {
	      return false;
	    }
	}
	return true;
}

//Polynomial.h
class Polynomial
{
	friend bool operator == (const Polynomial &, const Polynomial &);
	
	ostream & operator << (ostream & out, const Polynomial & p);
}

//Polynomial.cpp
//Define in Polynomial.cpp
ostream & operator << (ostream & out, const Polynomial &p)
{
  p.print(out);
  return out;
}

void Polynomial::print(ostream & out) const
{
  if(size == 0) return;
  //for ... notes continues
}