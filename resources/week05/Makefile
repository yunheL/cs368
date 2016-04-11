CC     = /s/gcc-5.1/bin/g++
DEBUG  =   
CFLAGS = -c -std=c++11 -pedantic $(DEBUG)
LFLAGS = -std=c++11 $(DEBUG)
  
make: Widget.o WidgetList.o
	$(CC) $(LFLAGS) stdafx.h Widget.o WidgetList.o main.cpp
	a.out

WidgetList.o:
	$(CC) $(CFLAGS) WidgetList.h WidgetList.cpp

Widget.o:
	$(CC) $(CFLAGS) Widget.h Widget.cpp

guessing_game: guessing_game.cpp
	\rm -f guessing_game
	$(CC) $(LFLAGS) -o guessing_game guessing_game.cpp
	./guessing_game

clean:
	\rm -f a.out
	\rm -f *.o
	\rm -f *.gch


