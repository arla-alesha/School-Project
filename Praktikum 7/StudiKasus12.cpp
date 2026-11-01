#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int *ptr;
    ptr = &num;

    cout << "Nilai: " << *ptr << endl;
    return 0;
}