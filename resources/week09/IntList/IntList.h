/*
 * IntList.h
 * 
 * A simple integer list class implemented using an array.  
 * Originally written by Beck Hasti for CS 368, Spring 2004
 */

#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>

class IntList {

    // declare free functions as "friend" so that they can access numItems
    friend IntList & operator+(IntList &,const IntList &);   // addition 
    friend std::ostream & operator<<(const IntList &,const IntList &) ;

  public:
    // Constructors
    IntList();
    IntList(int size);

    IntList(const IntList &L);              // copy constructor
    ~IntList();                             // destructor
    IntList & operator=(const IntList &L);  // assignment

    //OPERATOR OVERLOADING
    void operator+=(int);                   // addition assignment
    int operator[](int) const;              // indexed access
    bool operator==(const IntList &) const; // equality comparison
    IntList & operator+(const IntList &);   // addition 


    // Other public member functions
    void addToEnd(int k);   // adds value k to the end of the list
    void print() const;     // prints out the list (using cout)
    //int size() const;       // return the number of items in this list
    void print(std::ostream &) const; // prints the list to the given output stream

  private:
    static const int SIZE = 10;  // default initial size of array
    int *items;                  // dynamically allocated array of ints
    int numItems;                // number of items currently in the list
    int arraySize;               // current size of the array
};

#endif
