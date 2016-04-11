#include <iostream>

using namespace std;

int main() {

   int* ptr = nullptr;
   ptr = new int;

   cout << "ptr = " << ptr << endl;
   cout << "*ptr = " << *ptr << endl;
   cout << "&ptr = " << &ptr << endl;
}
