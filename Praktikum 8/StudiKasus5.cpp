#include <iostream>
#include <string>
using namespace std;

struct Produk {
    string nama;
    long long harga;
    int terjual;
};

string formatRupiah(long long angka) {
    string s = to_string(angka);
    string hasil = "";
    int hitung = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        hasil = s[i] + hasil;
        hitung++;
        if (hitung % 3 == 0 && i != 0) {
            hasil = "." + hasil;
        }
    }
    return "Rp " + hasil;
}

int main() {
    int n;
    cout << "Masukkan jumlah produk: ";
    cin >> n;

    if (n <= 0) {
        cout << "Tidak ada produk yang dimasukkan." << endl;
        return 0;
    }

    Produk* produk = new Produk[n];
    cin.ignore();
    cout << "Masukkan data produk (nama produk, harga satuan, jumlah terjual):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Produk " << i + 1 << " - Nama    : ";
        getline(cin, produk[i].nama);
        cout << "           Harga   : Rp ";
        cin >> produk[i].harga;
        cout << "           Terjual : ";
        cin >> produk[i].terjual;
        cin.ignore();
    }

    long long total = 0;
    long long tertinggi = -1;
    for (int i = 0; i < n; i++) {
        long long pendapatan = produk[i].harga * produk[i].terjual;
        total += pendapatan;
        if (pendapatan > tertinggi) {
            tertinggi = pendapatan;
        }
    }
    double rata = (double)total / n;

    cout << "\nTotal pendapatan: " << formatRupiah(total) << endl;
    cout << "Rata-rata pendapatan per produk: " << formatRupiah((long long)(rata + 0.5)) << endl;
    cout << "Produk dengan pendapatan tertinggi:" << endl;
    for (int i = 0; i < n; i++) {
        if (produk[i].harga * produk[i].terjual == tertinggi) {
            cout << "\"" << produk[i].nama << "\" (" << formatRupiah(tertinggi) << ")" << endl;
        }
    }

    delete[] produk;
    produk = nullptr;
    return 0;
}