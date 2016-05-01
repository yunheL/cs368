/* 
 * Examples of a templated functions
 */
#ifndef FCTNTEMPLATES_H
#define FCTNTEMPLATES_H

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

#endif
