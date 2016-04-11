CC     = /s/gcc-5.1/bin/g++
DEBUG  =   
CFLAGS = -c -std=c++11 -pedantic $(DEBUG)
LFLAGS = -std=c++11 $(DEBUG)
 
main: Widget.o WidgetList.o
	$(CC) $(LFLAGS) stdafx.h Widget.o WidgetList.o main.cpp
	a.out

WidgetList.o: Widget.o WidgetList.h WidgetList.cpp
	$(CC) $(CFLAGS) WidgetList.h WidgetList.cpp

Widget.o: Widget.h Widget.cpp
	$(CC) $(CFLAGS) Widget.h Widget.cpp

guessing_game: guessing_game.cpp
	\rm -f guessing_game
	$(CC) $(LFLAGS) -o guessing_game guessing_game.cpp
	./guessing_game

memcheck:
	valgrind testWidget
	valgrind testlist

clean:
	\rm -f a.out
	\rm -f *.o
	\rm -f *.gch


