/* 
 * Example showing the use of static local (function) variables.
 */
#include <iostream>

using namespace std;

int fib(int n);   // forward declaration

int main() {
   int answer = fib(5);
   cout << "fib(5) = " << answer << endl;
   return 0;
}

// Computes and returns the n-th Fibonacci number using recursion.
// The function also keeps track of the total number of calls to the fib 
// function and at the beginning of each call to fib, the value of n and 
// the number of this call to fib is printed out (which allows us to trace 
// the recursive calls to fib).
int fib(int n) {
  static int count = 0;  // static variable to keep track of number of time
                         // this function has been called
  count++;
  cout << "n = " << n << " count = " << count << endl;

  if (n <= 0)
     return -1;

  else if (n == 1 || n == 2)
     return 1;

  else 
     return fib(n-1) + fib(n-2);
}
