#include <iostream>
using namespace std;

int main() {
    int arr[5] = {15, 8, 23, 42, 16};
    int *ptr = arr;
    int maxVal = *ptr;

    for (int i = 1; i < 5; i++) {
        if (*(ptr + i) > maxVal) {
        maxVal = *(ptr + i);
        }
    }
cout << "Nilai terbesar: " << maxVal << endl;
}