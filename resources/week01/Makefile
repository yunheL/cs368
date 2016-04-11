C: hello.C
	gcc hello.C
	./a.out

c: hello.c
	gcc -o helloC hello.c
	./helloC

cc: hello.cc
	g++ -o helloCC hello.cc
	./helloCC

cpp: hello.cpp
	g++ -o helloCPP hello.cpp
	./helloCPP

c11: std_lib_facilities.h helloC11.cpp
	g++ -o helloC11 -Wno-deprecated std_lib_facilities.h helloC11.cpp
	./helloC11

cli: hello_args.cpp
	g++ -o hello_args hello_args.cpp
	./hello_args deb

java: Hello.java
	javac Hello.java
	java Hello

python: hello.py
	./hello.py

clean:
	rm *.o
	rm *.class
	rm helloC
	rm helloCPP
	rm helloC11


