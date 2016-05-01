# Makefile for WidgetList example
# See IntList/Makefile for another example

CC     = /s/gcc-5.1/bin/g++
DEBUG  = -g        # -g for debugging
CFLAGS = -c -std=c++11 -pedantic $(DEBUG)
LFLAGS = -std=c++11 $(DEBUG)
 
main: main.cpp Point.cpp Point.h
	g++ main.cpp Point.cpp Point.h

main11: main.cpp Point.o 
	$(CC) $(LFLAGS) main.cpp Point.cpp Point.h

Cpp_IO: Cpp_IO.cpp 
	$(CC) $(LFLAGS) Cpp_IO.cpp 
	a.out

manip: manip.cpp 
	$(CC) $(LFLAGS) manip.cpp 
	a.out

point.o: Point.cpp Point.h
	$(CC) $(CFLAGS) Point.cpp
 
file: fileIO.cpp 
	$(CC) $(LFLAGS) fileIO.cpp
	a.out
 
stdlib: main.cpp std_lib_facilities.h
	$(CC) $(LFLAGS) main.cpp -Wno-deprecated std_lib_facilities.h

memcheck: main
	valgrind a.out

clean:
	\rm -f a.out
	\rm -f *.o
	\rm -f *.gch


