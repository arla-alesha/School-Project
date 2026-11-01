#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr + 4;

    cout << "Elemen array terbalik: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr - i) << " ";
    }
    cout << endl;
    return 0;
}