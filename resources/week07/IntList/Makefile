# Makefile for the IntList example
# (all this goes in a file named 'Makefile')
#
# Notes: 
#
# - comments start with a # and go to the end of the line
#   (so the # is line // in Java or C++)
#
# - a makefile consists of rules of the form:
#      <target>: <files the target depends on>
#      <tab><command for making target>
#   It is important that the second line start with a <tab> 
#   (and not just spaces).

main: testIntList.o IntList.o
	g++ testIntList.o IntList.o

testIntList.o: testIntList.cpp IntList.h
	g++ -c testIntList.cpp

IntList.o: IntList.cpp IntList.h
	g++ -c IntList.cpp

clean:
	rm *.o
