#include <iostream>
using namespace std;

int main() {
    char str[] = "Hello, World!";
    char *ptr = str;

    cout << "String: ";
    while (*ptr) {
        cout << *ptr;
        ptr++;
    }
cout << endl;
return 0;
}