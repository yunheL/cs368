/* 
 * Examples of a templated functions
 */
#ifndef FCTNTEMPLATES_H
#define FCTNTEMPLATES_H

#include <iostream>
#include <vector>
using namespace std;

// Templated function: minimum
// Requires < to be defined for type T
template <typename T>
const T & minimum(const T & x, const T & y) {
    return (x < y) ? x : y;
}


// Templated function: swapIt
// Requires operator= to be defined for type T
template <typename T>
void swapIt(T & x, T & y) {
    T temp;
    temp = x;
    x = y;
    y = temp;
}

// Templated function: swapCast (from class example)
// Requires operator= to be defined for type T
// Requires type T and V to be compatible types
// must be able to cast from one to the other
template <typename T, typename V>
void swapCast(T & x, V & y) {
    V t;       // new var of type V
    t = (V) x; // cast x to type V
    x = (T) y; // cast y to type T
    y = t;
}

#endif
