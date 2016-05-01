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
        explicit Polynomial(double const_term);
        //Polynomial(double const_term);

        // destructor
        ~Polynomial();

        // named member functions
        int degree() const { return size - 1; }
        void print(ostream & out = cout) const;

        // assignment operators
        Polynomial & operator= (const Polynomial & rhs);
        Polynomial & operator+= (const Polynomial & rhs);
        Polynomial & operator*= (double rhs);

    private:
        int size;       // size of the coefs array ( = degree + 1)
        double * coefs; // coefs will be an array
};

Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs);

Polynomial operator*(const Polynomial & lhs, double rhs);
Polynomial operator*(double lhs, const Polynomial & rhs);

ostream & operator<<(ostream & out, const Polynomial & p);

#endif
