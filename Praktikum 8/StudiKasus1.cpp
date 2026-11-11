#include <iostream>
using namespace std;

int hitungTotalRekursif(int nilai[], int jumlah, int indeks = 0) {

    if (indeks == jumlah) {
        return 0;
    }

    return nilai[indeks] + hitungTotalRekursif(nilai, jumlah, indeks + 1);
}

double hitungRataRata(int nilai[], int jumlah) {
    return static_cast<double>(hitungTotalRekursif(nilai, jumlah)) / jumlah;
}

int main() {

    int jumlahMahasiswa;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMahasiswa;

    if (jumlahMahasiswa <= 0) {
        cout << "Jumlah mahasiswa harus lebih dari 0!" << endl;
        return 0;
    }

    int* nilai = new int[jumlahMahasiswa];

    cout << "\nMasukkan nilai mahasiswa:" << endl;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Mahasiswa " << i + 1 << ": ";
        cin >> nilai[i];
    }

    int terbesar = nilai[0];
    int terkecil = nilai[0];

    for (int i = 1; i < jumlahMahasiswa; i++) {

        if (nilai[i] > terbesar) {
            terbesar = nilai[i];
        }

        if (nilai[i] < terkecil) {
            terkecil = nilai[i];
        }
    }

    double rataRata = hitungRataRata(nilai, jumlahMahasiswa);

    cout << "\n===== HASIL PENGELOLAAN NILAI =====" << endl;
    cout << "Nilai terbesar : " << terbesar << endl;
    cout << "Nilai terkecil : " << terkecil << endl;
    cout << "Rata-rata nilai: " << rataRata << endl;

    delete[] nilai;

    return 0;
}
