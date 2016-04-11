# Makefile for WidgetList example
# See IntList/Makefile for another example

CC     = /s/gcc-5.1/bin/g++
DEBUG  = -g        # -g for debugging
CFLAGS = -c -std=c++11 -pedantic $(DEBUG)
LFLAGS = -std=c++11 $(DEBUG)
 
main: main.o Widget.o WidgetList.o
	$(CC) $(LFLAGS) main.o Widget.o WidgetList.o

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp stdafx.h

WidgetList.o: Widget.o WidgetList.cpp WidgetList.h 
	$(CC) $(CFLAGS) WidgetList.cpp

Widget.o: Widget.h Widget.cpp
	$(CC) $(CFLAGS) Widget.cpp

memcheck:
	valgrind testWidget
	valgrind testlist

clean:
	\rm -f a.out
	\rm -f *.o
	\rm -f *.gch


