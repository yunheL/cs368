CC     = /s/gcc-5.1/bin/g++
DEBUG  = 
CFLAGS = -c -std=c++11 -Wall -pedantic $(DEBUG)
LFLAGS = -Wall $(DEBUG)

params: params_demo.cpp
	$(CC) $(LFLAGS) -o params_demo $^
	./params_demo

pointerBasics: pointerBasics.cpp
	$(CC) $(LFLAGS) -o pointerBasics $^
	./pointerBasics

pointer: pointer_demo.cpp
	$(CC) $(LFLAGS) -o pointer_demo $^
	./pointer_demo

vector: vector_demo.cpp
	$(CC) $(LFLAGS) -o vector_demo $^
	./vector_demo

rand_demo: rand_demo.o
	$(CC) $(LFLAGS) -o rand_demo $^
	./rand_demo

rand_demo.o: rand_demo.cpp
	$(CC) $(CFLAGS) $^

cardExample: cardExample.cpp
	$(CC) $(LFLAGS) -o cardExample $^ 
	./cardExample

clean:
	rm -f *.o
	rm params_demo
	rm pointerBasics
	rm pointer_demo
	rm vector_demo
	rm rand_demo
	rm cardExample


