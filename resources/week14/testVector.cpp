/*
 * This program gives examples of how vectors are instantiated and used.
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>   // needed for sort()
using namespace std;

template <typename T>
void print_container(const T&);

//*
template <typename T>
void print(const std::vector<T>& v) { print_container(v); }

template <typename T>
void print(const std::list<T>& l) { print_container(l); }
//*/

template <typename T>
void print(const T& e) { cout << e; }

template <typename T>
void print_container(const T & v) {

    cout << "v.empty() = " << v.empty() ;
    cout << " , v.size() = " << v.size();
    cout << " , v.capacity() = " << v.capacity() << endl;
    if ( v.empty() ) return;

    cout << "standard for loop:   " ;
    for ( int i=0; i < v.size() ; i++ ) {
        cout << " " << v.at(i) ;
    }
    cout << endl;

    cout << "for loop w/iterator: " ;
    for (auto iter = v.begin(); iter != v.end(); iter++ ) {
       cout << " " << *iter ;
    }
    cout << endl;

}

int main() {

    cout << "====== TEST VECTOR EXAMPLES ======" << endl;

    // Create an empty vector
    vector<string> v;
    print(v);

    v.push_back("3.14");
    cout << "\nafter v.push_back(\"3.14\") " << endl ;
    print(v);

    v.push_back("1.7");
    cout << "\nafter v.push_back(\"1.7\") " << endl ;
    print(v);

    v.push_back("-4.5");
    cout << "\nafter v.push_back(\"-4.5\") " << endl ;
    print(v);

    v.push_back("-3.85");
    v.push_back("3.85");
    cout << "\nafter v.push_back(\"-3.85\" and \"3.85\" ) " << endl ;
    print(v);

    sort(v.begin(),v.end());
    cout << "\nafter sort(v.begin(),v.end()) " << endl;
    print(v);

    return 0;
}
