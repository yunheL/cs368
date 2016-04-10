CC = g++

all: Student.o SortedList.o main.o
	$(CC) -o test $?

Student.o: Student.cpp
	$(CC) -c $?

SortedList.o: SortedList.cpp
	$(CC) -c $?

main.o: main.cpp
	$(CC) -c $?

clean:
	rm -f *.o test
