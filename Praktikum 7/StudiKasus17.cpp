#include <iostream>
using namespace std;

int* findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return &max;
}
int main() {
    int arr[] = {3, 5, 2, 9, 6};
    int *max = findMax(arr, 5);
    cout << "Nilai maksimum dalam array adalah: " << *max << endl;
}