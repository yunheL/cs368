#include <iostream>

using namespace std;

// Count the characters in this string
int strlen(const char* s) {
    int i = 0;
    while (s[i]!='\0')  
        i++;
    return i;
}

int main( int argc, char * argv[ ] ) {

    // A bad idea, but you may see this
    char * name = "deb";
    cout << "My name is " << name << endl;
    cout << "strlen(name) is " << strlen(name) << endl;

}
