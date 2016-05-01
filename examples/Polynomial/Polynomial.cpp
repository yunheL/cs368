#include <iostream>
#include "Polynomial.h"

using namespace std;

// Constructor
// Creates a default polynomial p of the form p(x) = 0.0
Polynomial::Polynomial() : size(1), coefs(new double[1]) { 
    coefs[0] = 0.0;
}


// Constructor
// Given an array of coefficients C (and it's size N) creates a polynomial
// p(x) = C[N-1]x^(N-1) + ... + C[2]x^2 + C[1]x + C[0] 
Polynomial::Polynomial(double coefficients[], int number) : 
  size(number), coefs(new double[number]) {
    for (int i = 0; i < size; i++) {
        coefs[i] = coefficients[i];
    }
}


// Copy constructor
// Creates a polynomial from the given polynomial
Polynomial::Polynomial(const Polynomial & rhs) : 
  size(rhs.size), coefs(new double[rhs.size]) {
    for (int i = 0; i < size; i++) {
        coefs[i] = rhs.coefs[i];
    }
}


// Constructor
// Given a constant term A, creates the polynomial p(x) = A
Polynomial::Polynomial(double const_term) : size(1), coefs(new double[1]) {
    coefs[0] = const_term;
}


// Destructor
Polynomial::~Polynomial() {
    delete [] coefs;
}


// Prints the polynomial to the given ostream.  If no ostream is given,
// the polynomial is printed to cout
void Polynomial::print(ostream & out) const {
    if (size == 0) {
        return;
    }

    for (int i = size - 1; i > 0; i--)
        out << coefs[i] << "x^" << i << " + ";
    out << coefs[0];
}


// Overload assignment =
Polynomial & Polynomial::operator=(const Polynomial & rhs) {
    if (this == &rhs) {
        return *this;
    }

    else {
        delete [] coefs;
        coefs = new double[rhs.size];
        size = rhs.size;
        for (int i = 0; i < size; i++) {
            coefs[i] = rhs.coefs[i];
        }
    }
    return *this;
}


// Overload assignment +=
Polynomial & Polynomial::operator+=(const Polynomial & rhs) {
    int newSize = (rhs.size > size) ? rhs.size : size;
    double *newCoef = new double [newSize]; 

    for (int i = 0; i < newSize; i++) {
        newCoef[i] = 0;
    }
    for (int i = 0; i < rhs.size; i++) {
        newCoef[i] += rhs.coefs[i];
    }
    for (int i = 0; i < size; i++) {
        newCoef[i] += coefs[i];
    }
    delete [] coefs; 
    coefs = newCoef;
    size = newSize;
    return *this;
}


// Overload assignment *= so it supports scalar multiplication
Polynomial & Polynomial::operator*=(double rhs) {
    for (int i = 0; i < size; i++) {
        coefs[i] *= rhs;
    }
    return *this;
}


// Overload ==
bool operator==(const Polynomial & lhs, const Polynomial & rhs) {
    if (lhs.size != rhs.size) {
        return false;
    }

    for (int i = 0; i < lhs.size; i++) {
        if (lhs.coefs[i] != rhs.coefs[i]) {
            return false;
        }
    }
    return true;
}


// Overload +
Polynomial operator+(const Polynomial & lhs, const Polynomial & rhs) {
    Polynomial answer(lhs);
    answer += rhs;
    return answer;
}


// Overload * so it supports scalar multiplication.  Note that
// we overload it twice so we can do either:
//    polynomial * scalar
// or
//    scalar * polynomial

Polynomial operator*(const Polynomial & lhs, double rhs) {
    Polynomial answer(lhs);
    answer *= rhs;
    return answer;
}

Polynomial operator*(double lhs, const Polynomial & rhs) {
    Polynomial answer(rhs);
    answer *= lhs;
    return answer;
}


// Overload << for output
ostream & operator<<(ostream & out, const Polynomial & p) {
    p.print(out);
    return out;
}
