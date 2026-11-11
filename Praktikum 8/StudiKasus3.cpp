#include <iostream>
using namespace std;

// Fungsi rekursif: menampilkan matriks satu baris per pemanggilan
void tampilMatriks(int **m, int baris, int kolom, int i = 0) {
    if (i == baris) return;            // basis rekursi
    for (int j = 0; j < kolom; j++) {
        cout << m[i][j] << " ";
    }
    cout << endl;
    tampilMatriks(m, baris, kolom, i + 1); // lanjut ke baris berikutnya
}

int main() {
    int baris, kolom;

    cout << "Jumlah baris : ";
    cin >> baris;
    cout << "Jumlah kolom : ";
    cin >> kolom;

    // Alokasi array dinamis 2D untuk matriks asli
    int **matriks = new int*[baris];
    for (int i = 0; i < baris; i++)
        matriks[i] = new int[kolom];

    // Alokasi matriks transpose (ukuran kolom x baris)
    int **transpose = new int*[kolom];
    for (int i = 0; i < kolom; i++)
        transpose[i] = new int[baris];

    // Input matriks
    cout << "Matriks:" << endl;
    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
            cin >> matriks[i][j];

    // Proses transpose
    for (int i = 0; i < baris; i++)
        for (int j = 0; j < kolom; j++)
            transpose[j][i] = matriks[i][j];

    // Output
    cout << "\nMatriks asli:" << endl;
    tampilMatriks(matriks, baris, kolom);

    cout << "\nMatriks transpose:" << endl;
    tampilMatriks(transpose, kolom, baris);

    // Dealokasi memori
    for (int i = 0; i < baris; i++) delete[] matriks[i];
    delete[] matriks;
    for (int i = 0; i < kolom; i++) delete[] transpose[i];
    delete[] transpose;

    return 0;
}