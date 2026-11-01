#include <iostream>
using namespace std;

int main() {
    char source[] = "Hello";
    char destination[6];
    char *srcPtr = source;
    char *destPtr = destination;

    while (*srcPtr) {
        *destPtr = *srcPtr;
        srcPtr++;
        destPtr++;
    }

    *destPtr = '\0';
    cout << "String tujuan: " << destination << endl;
}