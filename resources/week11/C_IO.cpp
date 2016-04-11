/*
 * Example showing C style I/O.  This example does the same thing that 
 * the manipulator example shows.
 */
#include <cstdio>

using namespace std;

int main() {
    int x = 1234;
    double y = 8763.1415;
    char str[20] = "cs368";

    printf("x is %d, y is %f, str is %s\n", x, y, str);

    printf("%-20d %11.6f %s\n", x, y, str);

    printf("%-20d %11.6f %s\n", 97215, 12.34, "November");

    printf("Enter a number and a string: ");

    scanf("%d %s", &x, str);

    printf("x is %d, str is %s\n", x, str);
}
