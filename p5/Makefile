CC = g++

all: findWord.o
	$(CC) -o findWord $?

findWord.o: findWord.cpp
	$(CC) -c $?

clean:
	rm -f *.o findWord
