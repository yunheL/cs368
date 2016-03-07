//cs368_week8

//intlist.h
#ifndef INTLIST_H
#define INTLIST_H

public:
	//methods

private:
	//data members

#endif

//intlist.cpp
#include <iostream>		//built in class
#include "IntList.h"	//user defined header

using namespace std;	//std::cout

//constructor
//...

delete [] items; //deallocate mem allocated to items[]

//Makefile
g++ main.cpp IntList.cpp IntList.h
g++ -c main.cpp						//compile main.o
g++ -c IntList.cpp IntList.h		//IntList.o

//To create execute, must link object files
g++ main.o IntList.o				//a.out
g++ -o main main.o IntList.o		//main (exe)

target: dependencies

/* Questions
 * 1) How does pointer reference arrays, e.g. int* int_array;
 * 2) INTLIST_H
 */