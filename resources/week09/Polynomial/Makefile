# Makefile for Polynomial example

runPoly: testPolynomial.o Polynomial.o
	g++ -g testPolynomial.o Polynomial.o -o runPoly

Polynomial.o: Polynomial.cpp Polynomial.h
	g++ -g -c Polynomial.cpp

testPolynomial.o: testPolynomial.cpp Polynomial.h
	g++ -g -c testPolynomial.cpp

vg: testPolynomial.o Polynomial.o
	valgrind g++ -g testPolynomial.o Polynomial.o -o runPolyPurify

clean:
	rm *.o

