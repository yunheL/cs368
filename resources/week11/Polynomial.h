#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

class Polynomial {

    friend bool operator==(const Polynomial & lhs, const Polynomial & rhs);

    public:

        // constructors
        Polynomial();
        Polynomial(double coefficients[], int number);
        Polynomial(const Polynomial & rhs);
        //explicit Polynomial(double const_term);
        Polynomial(double const_term);

        // destructor
        ~Polynomial();

        // named member functions
        int degree() const { return size - 1; }
        void print(ostream & out = cout) const;

        // assignment operators
        Polynomial & operator= (const Polynomial & rhs);
        Polynomial & operator+= (const Polynomial & rhs);
        Polynomial & operator*= (double rhs);

	// Overload Unary negation
	Polynomial operator-() const;

        // Overload ++ 
        // If you do either, do both prefix and postfix versions
        const Polynomial & operator++(); // preincrement
        Polynomial operator++(int);      // postincrement

        // Overload -- 
        // If you do either, do both prefix and postfix versions
        const Polynomial & operator--(); // predecrement
        Polynomial operator--(int);      // postdecrement

    private:
        int size;       // size of the coefs array ( = degree + 1)
        double * coefs; // coefs will be an array
};

// NON-MEMBER FUNCTIONS TO ENSURE CONSISTENCY
// if polynomial is the first operand or the second

// p1 + p2
Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs);

// p1 * scalar
Polynomial operator*(const Polynomial & lhs, double rhs);

// scalar * p1
Polynomial operator*(double lhs, const Polynomial & rhs);

// overloaded << for convenient output
ostream & operator<<(ostream & out, const Polynomial & p);

#endif
