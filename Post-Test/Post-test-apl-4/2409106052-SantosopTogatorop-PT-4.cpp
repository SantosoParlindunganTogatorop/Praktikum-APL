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
Pendonor donor[MAX];
int jumlah = 0, stokA = 0, stokB = 0, stokAB = 0, stokO = 0;


void golongan(int stokA, int stokB, int stokAB, int stokO) {
    cout << "Golongan " << jenis[0] << " : " << stokA << endl;
    cout << "Golongan " << jenis[1] << " : " << stokB << endl;
    cout << "Golongan " << jenis[2] << " : " << stokAB << endl;
    cout << "Golongan " << jenis[3] << " : " << stokO << endl;
}

void tampilData(Pendonor donor[], int jumlah) {
	if (jumlah == 0){
		cout<<"____Data Kosong____"<<endl;
		return;
	}else{
	cout<<"No\t"<<"|\tNama\t\t|\tGolongan\t|Jumlah darah\t|\tAlamat\t\t|\tKota\t\t|"<<endl;
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout<<i+1<<"\t|\t"<<donor[i].nama<<"\t|\t"<<donor[i].golongan<<"\t\t|\t"<<donor[i].stok<<"\t|\t"
		<<donor[i].alamat.jalan<<"\t|\t"<<donor[i].alamat.kota<<"\t|"<<endl;
    }
    system("Pause");
	}
   
}


void tambahData() {
    if (jumlah >= MAX) {
        cout << "_____Data Penuh_____" << endl;
        return ;
    }

    cout << "Nama Pendonor: ";
    cin.ignore();
    getline(cin, donor[jumlah].nama);

    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". Golongan: " << jenis[i] << endl;
    }
    cout << "Golongan Darah: ";
    getline(cin, donor[jumlah].golongan);

    cout << "Jumlah stok darah: ";
    cin >> donor[jumlah].stok;

    if (donor[jumlah].golongan == "A") stokA += donor[jumlah].stok;
    else if (donor[jumlah].golongan == "B") stokB += donor[jumlah].stok;
    else if (donor[jumlah].golongan == "AB") stokAB += donor[jumlah].stok;
    else if (donor[jumlah].golongan == "O") stokO += donor[jumlah].stok;

    cin.ignore();
    cout << "Alamat: ";
    getline(cin, donor[jumlah].alamat.jalan);

    cout << "Kota: ";
    getline(cin, donor[jumlah].alamat.kota);

    jumlah++;
    system("cls||clear");
    cout << "Data berhasil ditambahkan!" << endl;
    
}


void ubahData() {
    tampilData(donor, jumlah);
    if (jumlah!=0){
    	int pilih;
	    cout << "Pilih data ke-berapa yang ingin diubah: ";
	    cin >> pilih;
	    pilih--;
	
	    cin.ignore();
	    cout << "Nama Baru: ";
	    getline(cin, donor[pilih].nama);
	
	    for (int i = 0; i < 4; i++) {
	        cout << i + 1 << ". Golongan: " << jenis[i] << endl;
	    }
	    cout << "Golongan Baru: ";
	    getline(cin, donor[pilih].golongan);
	
	    cout << "Stok Baru: ";
	    cin >> donor[pilih].stok;
	    cin.ignore();
	
	    cout << "Alamat Baru: ";
	    getline(cin, donor[pilih].alamat.jalan);
	
	    cout << "Kota Baru: ";
	    getline(cin, donor[pilih].alamat.kota);
	    
	    system("cls||clear");
	    cout << "Data berhasil diubah!" << endl;
		}
}


void hapusData() {
    tampilData(donor, jumlah);
    if(jumlah!=0){
    	int pilih;
	    cout << "Pilih data ke-berapa yang ingin dihapus: ";
	    cin >> pilih;
	    pilih--;
	
	    if (donor[pilih].golongan == "A") stokA -= donor[pilih].stok;
	    else if (donor[pilih].golongan == "B") stokB -= donor[pilih].stok;
	    else if (donor[pilih].golongan == "AB") stokAB -= donor[pilih].stok;
	    else if (donor[pilih].golongan == "O") stokO -= donor[pilih].stok;
	
	    for (int i = pilih; i < jumlah - 1; i++) {
	        donor[i] = donor[i + 1];
	    }
	    jumlah--;
	    
		system("cls||clear");
	    cout << "Data berhasil dihapus!" << endl;
	}

}

int main() {
    string username = "santoso";
    int password = 6052;
    string nama;
    int pilih,sandi;


    for (int i = 0; i < 3; i++) {
        cout << "Masukkan Username: ";
        cin >> nama;
        cout << "Masukkan Password: ";
        cin >> sandi;
        system("cls||clear");

        if (nama==username && sandi==password) {
		    do {
		    	cout << "======================================" << endl;
		        cout << "SISTEM PENGELOLAAN STOK KANTUNG DARAH" << endl;
		        cout << "======================================" << endl;
		        cout << "1. Tambah Data" << endl;
		        cout << "2. Lihat Data" << endl;
		        cout << "3. Ubah Data" << endl;
		        cout << "4. Hapus Data" << endl;
		        cout << "5. Keluar" << endl;
		        cout << "======================================" << endl;
		        cout << "Pilih: ";
		        cin >> pilih;
		        system("cls||clear");
		
		        switch (pilih) {
		            case 1:
		                tambahData();
		                break;
		            case 2: {
		                int pilih;
		                cout << "1. Lihat Jumlah Stok Darah\n2. Detail Pendonor\nPilih: ";
		                cin >> pilih;
		                if (pilih == 1) golongan(stokA, stokB, stokAB, stokO);
		                else tampilData(donor, jumlah);
		                break;
		            }
		            case 3:
		                ubahData();
		                break;
		            case 4:
		                hapusData();
		                break;
		            case 5:
		                cout << "Anda Keluar dari program" << endl;
		                break;
		            default:
		                cout << "Pilihan tidak valid!" << endl;
		        }
		    } while (pilih != 5);
            
        } else {
            cout << "Login gagal! Kesempatan tersisa " << 2 - i <<" kali" <<endl;
        }
    }

    return 0;
}

