#include <iostream>
using namespace std;

int main() {
    char str[] = "Programming";
    char *ptr = str;
    int count = 0;

    while (*ptr) {
        count++;
        ptr++;
    }
    cout << "Jumlah karakter: " << count << endl;
    return 0;
}