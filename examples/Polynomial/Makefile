# Makefile for Polynomial example

runPoly: testPolynomial.o Polynomial.o
	g++ -g testPolynomial.o Polynomial.o -o runPoly

testImplicitTypeConversion: testImplicitTypeConversion.o Polynomial.o
	g++ -g testImplicitTypeConversion.cpp Polynomial.o
	a.out

Polynomial.o: Polynomial.cpp Polynomial.h
	g++ -g -c Polynomial.cpp

testPolynomial.o: testPolynomial.cpp Polynomial.o
	g++ -g -c testPolynomial.cpp

testImplicitTypeConversion.o: testImplicitTypeConversion.cpp Polynomial.o
	g++ -g -c testImplicitTypeConversion.cpp

valgrind: testPolynomial.o Polynomial.o
	g++ -g testPolynomial.o Polynomial.o -o runPoly
	valgrind runPoly

clean:
	rm *.o

