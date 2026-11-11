#include <iostream>
#include <string>
using namespace std;

// Seleksi kondisi: menentukan persentase diskon berdasarkan harga
int persenDiskon(long long harga) {
    if (harga > 500000)       return 10;  // lebih dari 500.000 -> 10%
    else if (harga >= 200000) return 5;   // 200.000 - 500.000 -> 5%
    else                      return 0;   // di bawah 200.000 -> tidak ada diskon
}

// Format angka dengan titik pemisah ribuan (contoh: 1250000 -> 1.250.000)
string formatRupiah(long long angka) {
    string s = to_string(angka);
    for (int i = (int)s.length() - 3; i > 0; i -= 3)
        s.insert(i, ".");
    return s;
}

// Fungsi rekursif: hitung diskon tiap barang & akumulasi total harga setelah diskon
long long hitungTotal(long long *harga, int n, int i, int &jumlahDiskon) {
    if (i == n) return 0;                       // basis rekursi

    int persen = persenDiskon(harga[i]);
    long long hargaAkhir = harga[i] - (harga[i] * persen / 100);

    cout << "Diskon untuk barang " << i + 1 << ": ";
    if (persen == 0) cout << "Tidak ada diskon" << endl;
    else {
        cout << persen << "%" << endl;
        jumlahDiskon++;
    }

    return hargaAkhir + hitungTotal(harga, n, i + 1, jumlahDiskon);
}

int main() {
    int n;
    cout << "Masukkan jumlah barang: ";
    cin >> n;

    // Array dinamis untuk menyimpan harga barang
    long long *harga = new long long[n];
    for (int i = 0; i < n; i++) {
        cout << "Masukkan harga barang " << i + 1 << ": ";
        cin >> harga[i]; 
    }

    cout << endl;
    int jumlahDiskon = 0;
    long long total = hitungTotal(harga, n, 0, jumlahDiskon);

    cout << "\nTotal harga setelah diskon: " << formatRupiah(total) << endl;
    if (jumlahDiskon > 0)
        cout << "Pesan: Diskon sudah diterapkan pada " << jumlahDiskon << " barang." << endl;
    else
        cout << "Pesan: Diskon belum diterapkan." << endl;

    delete[] harga;   // dealokasi memori
}