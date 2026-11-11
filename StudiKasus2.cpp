
#include <iostream>
using namespace std;

int main() {

    int barisA, kolomA;
    int barisB, kolomB;

    cout << "Masukkan jumlah baris Matriks A: ";
    cin >> barisA;

    cout << "Masukkan jumlah kolom Matriks A: ";
    cin >> kolomA;

    cout << "\nMasukkan jumlah baris Matriks B: ";
    cin >> barisB;

    cout << "Masukkan jumlah kolom Matriks B: ";
    cin >> kolomB;

    if (barisA <= 0 || kolomA <= 0 ||
        barisB <= 0 || kolomB <= 0) {

        cout << "\nError: Ukuran matriks harus lebih dari 0!" << endl;
        return 0;
    }

    if (kolomA != barisB) {
        cout << "\nError: Matriks tidak dapat dikalikan!" << endl;
        cout << "Jumlah kolom Matriks A harus sama dengan ";
        cout << "jumlah baris Matriks B." << endl;
        return 0;
    }

    int** A = new int*[barisA];

    for (int i = 0; i < barisA; i++) {
        A[i] = new int[kolomA];
    }

    int** B = new int*[barisB];

    for (int i = 0; i < barisB; i++) {
        B[i] = new int[kolomB];
    }

    int** C = new int*[barisA];

    for (int i = 0; i < barisA; i++) {
        C[i] = new int[kolomB];
    }

    cout << "\nMasukkan elemen Matriks A:" << endl;

    for (int i = 0; i < barisA; i++) {
        for (int j = 0; j < kolomA; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> *(*(A + i) + j);
        }
    }

    cout << "\nMasukkan elemen Matriks B:" << endl;

    for (int i = 0; i < barisB; i++) {
        for (int j = 0; j < kolomB; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> *(*(B + i) + j);
        }
    }

    for (int i = 0; i < barisA; i++) {

        for (int j = 0; j < kolomB; j++) {

            *(*(C + i) + j) = 0;

            for (int k = 0; k < kolomA; k++) {

                *(*(C + i) + j) +=
                    (*(*(A + i) + k)) * (*(*(B + k) + j));

            }
        }
    }

    cout << "\nHasil perkalian Matriks A dan B:" << endl;

    for (int i = 0; i < barisA; i++) {

        for (int j = 0; j < kolomB; j++) {
            cout << *(*(C + i) + j) << "\t";
        }

        cout << endl;
    }

    for (int i = 0; i < barisA; i++) {
        delete[] A[i];
    }
    delete[] A;

    for (int i = 0; i < barisB; i++) {
        delete[] B[i];
    }
    delete[] B;

    for (int i = 0; i < barisA; i++) {
        delete[] C[i];
    }
    delete[] C;

    return 0;
}
