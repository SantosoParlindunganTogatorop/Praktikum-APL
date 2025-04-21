#include <iostream>
using namespace std;

struct Alamat {
    string jalan;
    string kota;
};

struct Pendonor {
    string nama;
    string golongan;
    int stok;
    Alamat alamat;
};

#define MAX 100

string jenis[4] = {"A", "B", "AB", "O"};
Pendonor data[MAX];
Pendonor* donor[MAX]; // Array of pointer
int jumlah = 0, stokA = 0, stokB = 0, stokAB = 0, stokO = 0;

int golongan() {
    cout << "Golongan " << jenis[0] << " : " << stokA << endl;
    cout << "Golongan " << jenis[1] << " : " << stokB << endl;
    cout << "Golongan " << jenis[2] << " : " << stokAB << endl;
    cout << "Golongan " << jenis[3] << " : " << stokO << endl;
    return stokA + stokB + stokAB + stokO;
}

void tampilData(Pendonor* donor[], int jumlah) {
    if (jumlah == 0) {
        cout << "____Data Kosong____" << endl;
        return;
    }

    cout << "No\t|\tNama\t|\tGolongan\t|Jumlah\t|\tAlamat\t|\tKota\t|" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << "\t|\t" << donor[i]->nama << "\t|\t" << donor[i]->golongan << "\t\t|"
             << donor[i]->stok << "\t|\t" << donor[i]->alamat.jalan << "\t|\t"
             << donor[i]->alamat.kota << "\t|" << endl;
    }
    system("pause");
}

void tambahData(Pendonor* donor[], int& ) {
    if (jumlah >= MAX) {
        cout << "_____Data Penuh_____" << endl;
        return;
    }

    donor[jumlah] = &data[jumlah]; // Hubungkan pointer dengan struct asli

    cout << "Nama Pendonor: ";
    cin.ignore();
    getline(cin, donor[jumlah]->nama);

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". Golongan: " << jenis[i] << endl;
    }

    cout << "Golongan Darah: ";
    getline(cin, donor[jumlah]->golongan);

    cout << "Jumlah stok darah: ";
    cin >> donor[jumlah]->stok;

    if (donor[jumlah]->golongan == "A") stokA += donor[jumlah]->stok;
    else if (donor[jumlah]->golongan == "B") stokB += donor[jumlah]->stok;
    else if (donor[jumlah]->golongan == "AB") stokAB += donor[jumlah]->stok;
    else if (donor[jumlah]->golongan == "O") stokO += donor[jumlah]->stok;

    cin.ignore();
    cout << "Alamat: ";
    getline(cin, donor[jumlah]->alamat.jalan);

    cout << "Kota: ";
    getline(cin, donor[jumlah]->alamat.kota);

    jumlah++;
    system("cls||clear");
    cout << "Data berhasil ditambahkan!" << endl;
}

void ubahData(Pendonor* donor[], int*) {
    tampilData(donor, jumlah);
    if (jumlah == 0) return;

    int pilih;
    cout << "Pilih data ke-berapa yang ingin diubah: ";
    cin >> pilih;
    pilih--;

    cin.ignore();
    cout << "Nama Baru: ";
    getline(cin, donor[pilih]->nama);

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". Golongan: " << jenis[i] << endl;
    }
    cout << "Golongan Baru: ";
    getline(cin, donor[pilih]->golongan);

    cout << "Stok Baru: ";
    cin >> donor[pilih]->stok;
    cin.ignore();

    cout << "Alamat Baru: ";
    getline(cin, donor[pilih]->alamat.jalan);

    cout << "Kota Baru: ";
    getline(cin, donor[pilih]->alamat.kota);

    system("cls||clear");
    cout << "Data berhasil diubah!" << endl;
}

void hapusData(Pendonor* donor[], int& jumlah) {
    tampilData(donor, jumlah);
    if (jumlah == 0) return;

    int pilih;
    cout << "Pilih data ke-berapa yang ingin dihapus: ";
    cin >> pilih;
    pilih--;

    if (donor[pilih]->golongan == "A") stokA -= donor[pilih]->stok;
    else if (donor[pilih]->golongan == "B") stokB -= donor[pilih]->stok;
    else if (donor[pilih]->golongan == "AB") stokAB -= donor[pilih]->stok;
    else if (donor[pilih]->golongan == "O") stokO -= donor[pilih]->stok;

    for (int i = pilih; i < jumlah - 1; i++) {
        donor[i] = donor[i + 1];
    }
    jumlah--;

    system("cls||clear");
    cout << "Data berhasil dihapus!" << endl;
}

int main() {
    string username = "santoso";
    int password = 6052;
    string nama;
    int sandi, pilih;

    for (int i = 0; i < 3; i++) {
        cout << "Masukkan Username: ";
        cin >> nama;
        cout << "Masukkan Password: ";
        cin >> sandi;
        system("cls||clear");

        if (nama == username && sandi == password) {
            do {
                cout << "===========================" << endl;
                cout << "SISTEM STOK KANTUNG DARAH" << endl;
                cout << "===========================" << endl;
                cout << "1. Tambah Data\n2. Lihat Data\n3. Ubah Data\n4. Hapus Data\n5. Keluar\n";
                cout << "Pilih: ";
                cin >> pilih;
                system("cls||clear");

                switch (pilih) {
                    case 1: tambahData(donor, jumlah); break;
                    case 2: {
                        int subpilih;
                        cout << "1. Lihat Jumlah Stok\n2. Detail Pendonor\nPilih: ";
                        cin >> subpilih;
                        if (subpilih == 1)
                            cout << "Total: " << golongan() << endl;
                        else
                            tampilData(donor, jumlah);
                        break;
                    }
                    case 3: ubahData(donor, &jumlah); 
						break;
                    case 4: hapusData(donor, jumlah); 
						break;
                    case 5: cout << "Keluar dari program..." << endl; 
						break;
                    default: cout << "Pilihan tidak valid" << endl;
                }
            } while (pilih != 5);
            break;
        } else {
            cout << "Login gagal! Kesempatan tersisa " << 2 - i << endl;
        }
    }

    return 0;
}

