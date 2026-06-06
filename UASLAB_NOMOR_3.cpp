#include <iostream>
#include <vector>
using namespace std;

struct Barang {
    string kodeBarang;
    string namaBarang;
    double harga;
    int stok;
};

void tambahBarang(vector<Barang> &data) {
    Barang b;

    cout << "\nKode Barang : ";
    cin >> b.kodeBarang;

    cin.ignore();
    cout << "Nama Barang : ";
    getline(cin, b.namaBarang);

    do {
        cout << "Harga : ";
        cin >> b.harga;

        if (b.harga < 0)
            cout << "Harga tidak boleh negatif!\n";

    } while (b.harga < 0);

    do {
        cout << "Stok : ";
        cin >> b.stok;

        if (b.stok < 0)
            cout << "Stok tidak boleh negatif!\n";

    } while (b.stok < 0);

    data.push_back(b);
    cout << "Barang berhasil ditambahkan!\n";
}

void tampilkanBarang(vector<Barang> data) {
    if (data.empty()) {
        cout << "Data kosong!\n";
        return;
    }

    cout << "\nDaftar Barang\n";

    for (Barang b : data) {
        cout << "Kode  : " << b.kodeBarang << endl;
        cout << "Nama  : " << b.namaBarang << endl;
        cout << "Harga : " << b.harga << endl;
        cout << "Stok  : " << b.stok << endl;
        cout << "------------------\n";
    }
}

void cariBarangTermahal(vector<Barang> data) {
    if (data.empty()) {
        cout << "Data kosong!\n";
        return;
    }

    Barang termahal = data[0];

    for (Barang b : data) {
        if (b.harga > termahal.harga)
            termahal = b;
    }

    cout << "\nBarang Termahal\n";
    cout << "Kode  : " << termahal.kodeBarang << endl;
    cout << "Nama  : " << termahal.namaBarang << endl;
    cout << "Harga : " << termahal.harga << endl;
    cout << "Stok  : " << termahal.stok << endl;
}

void hitungTotalInventaris(vector<Barang> data) {
    double total = 0;

    for (Barang b : data) {
        total += b.harga * b.stok;
    }

    cout << "\nTotal Nilai Inventaris : " << total << endl;
}

void cekRestock(vector<Barang> data) {
    cout << "\nBarang yang perlu restock:\n";

    bool ada = false;

    for (Barang b : data) {
        if (b.stok < 5) {
            cout << b.namaBarang << " (Stok: " << b.stok << ")\n";
            ada = true;
        }
    }

    if (!ada)
        cout << "Tidak ada barang yang perlu restock.\n";
}

void updateStok(vector<Barang> &data) {
    string kode;
    cout << "\nMasukkan kode barang : ";
    cin >> kode;

    for (Barang &b : data) {
        if (b.kodeBarang == kode) {

            int *ptrStok = &b.stok;

            cout << "Stok saat ini : " << *ptrStok << endl;

            cout << "Masukkan stok baru : ";
            cin >> *ptrStok;

            if (*ptrStok < 0) {
                cout << "Stok tidak boleh negatif!\n";
                *ptrStok = 0;
            }

            cout << "Stok berhasil diperbarui!\n";
            return;
        }
    }

    cout << "Barang tidak ditemukan!\n";
}

int main() {
    vector<Barang> inventaris;
    int pilihan;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Semua Barang\n";
        cout << "3. Cari Barang Termahal\n";
        cout << "4. Hitung Total Nilai Inventaris\n";
        cout << "5. Cek Restock\n";
        cout << "6. Update Stok\n";
        cout << "7. Keluar\n";
        cout << "Pilih : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahBarang(inventaris);
                break;
            case 2:
                tampilkanBarang(inventaris);
                break;
            case 3:
                cariBarangTermahal(inventaris);
                break;
            case 4:
                hitungTotalInventaris(inventaris);
                break;
            case 5:
                cekRestock(inventaris);
                break;
            case 6:
                updateStok(inventaris);
                break;
            case 7:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 7);

    return 0;
}