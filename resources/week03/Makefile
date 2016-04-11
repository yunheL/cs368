CC     = /s/gcc-5.1/bin/g++
DEBUG  = 
CFLAGS = -c -std=c++11 -Wall -pedantic $(DEBUG)
LFLAGS = -Wall $(DEBUG)

pointer: pointer_demo.o
	$(CC) $(LFLAGS) -o pointer_demo $^
	./pointer_demo

pointer_demo.o: pointer_demo.cpp
	$(CC) $(CFLAGS) $^ 

array: array_demo.o
	$(CC) $(LFLAGS) -o array_demo $^
	./array_demo

array_demo.o: array_demo.cpp
	$(CC) $(CFLAGS) $^ 

cardExample: cardExample.o
	$(CC) $(LFLAGS) -o cardExample $^ 
	./cardExample

cardExample.o: cardExample.cpp
	$(CC) $(CFLAGS) $^

clean:
	rm -f *.o
	rm array_demo
	rm cardExample


