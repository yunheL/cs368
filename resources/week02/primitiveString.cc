#include <iostream>
#include <cstring>

using namespace std;

int main( int argc, char * argv[ ] ) {

    // A bad idea, but you may see this
    char * name = "deb";
    cout << "My name is " << name << endl;
    cout << "strlen(name) is " << strlen(name) << endl;

}
