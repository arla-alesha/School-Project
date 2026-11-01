#include <iostream>
using namespace std;

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int *ptr = arr; // Pointer ke array
    
    cout << "Elemen genap: ";
    for (int i = 0; i < 6; i++) {
        if (*(ptr + i) % 2 == 0) {
            cout << *(ptr + i) << " ";
        }
    }
    cout << endl;
}