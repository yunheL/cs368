#include <fstream>   // for input from a file
#include <ostream>   // for output to file
#include <iostream>  // for cout cin cerr
#include <string>

using namespace std;


int main(int argc, char* argv[]) {

  if (argc == 1) {
      cerr << "Invalid file\n";
      return -1;
  }

      
  char* filename = argv[1] ; // "input.dat";
  ifstream inFile(filename);  // * inFile fopen(filename,"r");
  if (!inFile) {
      cerr << "unable to open file " 
           << filename << " for reading\n" ;
      return -1;
  }

  // TRACK THE FILE PARSING
  int count = 0;
  string line; 

  // ECHO FILE TO SCREEN ONE LINE AT A TIME
  // (uncomment loop to try this option)
  // while ( !getline(inFile,line).eof() ) {
  //     count++;
  //     cout << "Line " << count << ": " << line << endl;
  // }

  // ECHO FILE TO SCREEN ONE TOKEN AT A TIME
  // Can be modified to read int string etc
  // (uncomment loop to try this option)
  // while ( inFile >> line ) {
  //    count++;
  //    cout << "Line " << count << ": " << line << endl;
  // }
 
  return 0;


}
