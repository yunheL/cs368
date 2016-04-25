CC = g++

all: ComplexNumber.o main.o
	$(CC) -o test $?

Student.o: ComplexNumber.cpp
	$(CC) -c $?

main.o: main.cpp
	$(CC) -c $?

clean:
	rm -f *.o test
