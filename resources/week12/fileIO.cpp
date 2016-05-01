/*
 * fileIO.cpp
 *
 * Example showing file input and output
 *
 * Updated by Jim Skrentny for CS 368, Fall 2006
 * Written by Beck Hasti for CS 368, Spring 2004
 */
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*  
 * countLines
 *
 * Counts the number of lines in the file with the given name.
 * The lines are also echoed to standard output (along with the line number)
 * If the file cannot be opened, -1 is returned.
 */
int countLines(string & fileName) {

    ifstream myFile(fileName.c_str());
    // Note conversion of string library object to C-style string using c_str

    if (myFile) {       // if the file was successfully opened

        int count = 0;


        // VERSION 1: C style strings
        //     uses a char array and member function getline()
        //
        // TODO: fix infinite loop if line in file is too long for line var
        //char cline[100];
        //while (!myFile.getline(cline, 100).eof()) {
        //    count++;
        //    cout << "Line " << count << ": " << cline << endl;
        //}


        // VERSION 2: C++ style strings
        //     uses a string object and free function getline()
        //
        string line;
        while (!getline(myFile, line).eof()) {
            count++;
            cout << "Line " << count << ": " << line << endl;
        }
		
        myFile.close();   // close the file now that we're done with it
        return count;

    } else {
        cerr << "Unable to open " << fileName << " in countLines" << endl;
        myFile.close();
        return -1;
    }
}


int main() {

    // Open inFile.txt
    ifstream inFile("inFile.txt");
    if (!inFile) {
        cerr << "Unable to open inFile.txt for reading" << endl;
        return 1;
    }

    // Open outFile.txt
    ofstream outFile("outFile.txt");
    if (!outFile) {
        cerr << "Unable to open outFile.txt for writing" << endl;
        return 1;
    }

    // The following copies inFile.txt to outFile.txt, replacing each occurrence
    // of a vowel (a, e, i, o, u) with a *
    char ch;
    while (inFile.get(ch)) {
        switch (ch) {
          case 'a':  case 'A': 
          case 'e':  case 'E': 
          case 'i':  case 'I': 
          case 'o':  case 'O': 
          case 'u':  case 'U':
	      outFile << '*';
	      break;
          default:
	      outFile << ch;
        }
    }

    // Close files when finished with them
    inFile.close();
    outFile.close();

    // Now test the countLines function
    string name = "inFile.txt";
    int numLines = countLines(name);
    cout << "File " << name << " has " << numLines << " lines" << endl;
  
    return 0;
}
