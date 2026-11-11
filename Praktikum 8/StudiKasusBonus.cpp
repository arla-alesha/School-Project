#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

struct Proyek {
    string nama;
    long long anggaran;
    int pekerja;
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

long long bacaAngka(const string& pesan, bool bolehNegatif = false) {
    long long x;
    cout << pesan;
    while (true) {
        cin >> x;
        bool valid = !cin.fail();
        if (valid && x < 0 && !bolehNegatif) {
            valid = false;
        }
        if (valid) {
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid (tidak boleh negatif/bukan angka). Ulangi: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
}

Proyek bacaProyek(int nomor) {
    Proyek p;
    cout << "Proyek " << nomor << endl;
    cout << "  Nama     : ";
    getline(cin, p.nama);
    p.anggaran = bacaAngka("  Anggaran : Rp ");
    p.pekerja = (int)bacaAngka("  Pekerja  : ");
    return p;
}

void tambahProyek(Proyek*& data, int& n, const Proyek& baru) {
    Proyek* temp = new Proyek[n + 1];
    for (int i = 0; i < n; i++) {
        temp[i] = data[i];
    }
    temp[n] = baru;
    delete[] data;
    data = temp;
    n++;
}

bool hapusProyek(Proyek*& data, int& n, int indeks) {
    if (n == 0) {
        cout << "Tidak ada proyek yang bisa dihapus." << endl;
        return false;
    }
    if (indeks < 0) {
        cout << "Indeks tidak valid." << endl;
        return false;
    }
    if (indeks >= n) {
        cout << "Indeks tidak valid." << endl;
        return false;
    }
    Proyek* temp = new Proyek[n - 1];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i != indeks) {
            temp[j] = data[i];
            j++;
        }
    }
    delete[] data;
    data = temp;
    n--;
    return true;
}

void tampilProyek(const Proyek* data, int n) {
    if (n == 0) {
        cout << "(Belum ada proyek)" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << "Proyek " << i + 1 << ": \"" << data[i].nama << "\", Anggaran: "
             << formatRupiah(data[i].anggaran) << ", Pekerja: " << data[i].pekerja << endl;
    }
}

void tampilRingkasan(const Proyek* data, int n) {
    if (n == 0) {
        cout << "Tidak ada proyek, ringkasan tidak dapat dihitung." << endl;
        return;
    }
    long long totalAnggaran = 0;
    long long totalPekerja = 0;
    int idxTerbesar = 0;
    for (int i = 0; i < n; i++) {
        totalAnggaran += data[i].anggaran;
        totalPekerja += data[i].pekerja;
        if (data[i].anggaran > data[idxTerbesar].anggaran) {
            idxTerbesar = i;
        }
    }
    long long rata100 = (long long)((double)totalPekerja / n * 100 + 0.5);

    cout << "Total anggaran seluruh proyek: " << formatRupiah(totalAnggaran) << endl;
    cout << "Rata-rata jumlah pekerja per proyek: " << rata100 / 100 << ","
         << setfill('0') << setw(2) << rata100 % 100 << setfill(' ') << endl;
    cout << "Proyek dengan anggaran terbesar: \"" << data[idxTerbesar].nama << "\" ("
         << formatRupiah(data[idxTerbesar].anggaran) << ")" << endl;
}

int main() {
    int n = (int)bacaAngka("Masukkan jumlah proyek: ");
    Proyek* data = new Proyek[n];
    if (n > 0) {
        cout << "Masukkan data proyek:" << endl;
    }
    for (int i = 0; i < n; i++) {
        data[i] = bacaProyek(i + 1);
    }

    int pilihan;
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Tampilkan daftar proyek" << endl;
        cout << "2. Tambah proyek baru" << endl;
        cout << "3. Hapus proyek (berdasarkan indeks, mulai dari 0)" << endl;
        cout << "4. Tampilkan ringkasan" << endl;
        cout << "0. Keluar" << endl;
        pilihan = (int)bacaAngka("Pilihan: ");

        if (pilihan == 1) {
            tampilProyek(data, n);
        } else if (pilihan == 2) {
            tambahProyek(data, n, bacaProyek(n + 1));
            cout << "Daftar proyek setelah penambahan:" << endl;
            tampilProyek(data, n);
        } else if (pilihan == 3) {
            int indeks = (int)bacaAngka("Indeks proyek yang dihapus: ", true);
            if (hapusProyek(data, n, indeks)) {
                cout << "Daftar proyek setelah penghapusan:" << endl;
                tampilProyek(data, n);
            }
        } else if (pilihan == 4) {
            tampilRingkasan(data, n);
        } else if (pilihan != 0) {
            cout << "Pilihan tidak tersedia." << endl;
        }
    } while (pilihan != 0);

    delete[] data;
    data = nullptr;
    return 0;
}