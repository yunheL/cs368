#include "stdafx.h"
using namespace std;

int main() {
    int lo = 1, hi = 1000;
    int target = 576;
    int guess  = -1;
    int count  = 0;

    cout << (count+1) << ". Pick a number between " << lo << " and " << hi << ": " ;
    cin >> guess;
    count++;

    while ( guess != target ) {
      if ( guess < target ) {
        lo = guess;
        cout << (count+1) << ". Too  low! Guess higher than " << guess << " and lower than " << hi << ": " ;
      } else if ( guess > target ) {
        hi = guess;
        cout << (count+1) << ". Too high! Guess higher than " << lo << " and lower than " << guess << ": " ;
      } 
      cin >> guess;
      count++;
    }

    cout << "That's Correct! " << count << " guesses. Nice work." << endl << endl;
};
