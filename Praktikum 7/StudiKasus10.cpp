#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    int oddCount = 0;

    for (int i = 0; i < 5; i++) {
        if (*(ptr + i) % 2 != 0) {
            oddCount++;
        }
    }
    cout << "Jumlah bilangan ganjil: " << oddCount << endl;
}