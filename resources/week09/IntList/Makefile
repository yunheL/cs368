main: IntList.o main.o
	g++ IntList.o main.o

debug: main.o IntList.o
	g++ -g main.o IntList.o
	gdb a.out

vg: main.o IntList.o 
	g++ -g main.o IntList.o
	valgrind a.out > mem_out.txt

main.o: main.cpp
	g++ -c main.cpp

IntList.o: IntList.cpp IntList.h
	g++ -c IntList.cpp

clean:
	rm *.o
