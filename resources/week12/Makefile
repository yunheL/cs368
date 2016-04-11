# Makefile for WidgetList example
# See IntList/Makefile for another example

CC     = /s/gcc-5.1/bin/g++
DEBUG  = -g        # -g for debugging
CFLAGS = -c -std=c++11 -pedantic $(DEBUG)
LFLAGS = -std=c++11 $(DEBUG)
 
main: main.cpp 
	$(CC) $(LFLAGS) main.cpp 
 
stdlib: main.cpp std_lib_facilities.h
	$(CC) $(LFLAGS) main.cpp -Wno-deprecated std_lib_facilities.h

memcheck:
	valgrind a.out

clean:
	\rm -f a.out
	\rm -f *.o
	\rm -f *.gch


