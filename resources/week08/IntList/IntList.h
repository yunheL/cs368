/*
 * IntList.h
 * 
 * A simple integer list class implemented using an array.  
 * Originally written by Beck Hasti for CS 368, Spring 2004
 */

#ifndef INTLIST_H
#define INTLIST_H

class IntList {

  public:
    // Constructors
    IntList();
    IntList(int size);

    IntList(const IntList &L);              // copy constructor
    ~IntList();                             // destructor
    IntList & operator=(const IntList &L);  // assignment

    // Other public member functions
    void addToEnd(int k);   // adds value k to the end of the list
    void print() const;     // prints out the list (using cout)

  private:
    static const int SIZE = 10;  // default initial size of array
    int *items;                  // dynamically allocated array of ints
    int numItems;                // number of items currently in the list
    int arraySize;               // current size of the array
};

#endif
