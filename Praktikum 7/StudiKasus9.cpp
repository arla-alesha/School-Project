#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    cout << "Indeks dan nilai: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Indeks " << i << ": " << *(ptr + i) << endl;
    }   
}
