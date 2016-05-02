# Makefile for WidgetList example
# See IntList/Makefile for another example

CC     = /s/gcc-5.1/bin/g++
DEBUG  = -g        # -g for debugging
CFLAGS = -c -std=c++11 -pedantic $(DEBUG)
LFLAGS = -std=c++11 $(DEBUG)
 
main: student vector
	testVector
	testStudent

vector: testVector.cpp 
	$(CC) $(LFLAGS) -o testVector testVector.cpp 

student: testSortStudent.cpp 
	$(CC) $(LFLAGS) -o testStudent testSortStudent.cpp 

memcheck:
	valgrind a.out

clean:
	\rm -f a.out
	\rm -f *.o
	\rm -f *.gch


