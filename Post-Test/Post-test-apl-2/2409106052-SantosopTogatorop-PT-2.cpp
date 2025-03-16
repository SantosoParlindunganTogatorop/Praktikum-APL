#include <iostream>
using namespace std;

#define MAX 100

int main(){
	
	string nama = "santoso";
	int pin = 6052;
	string name;
	int nim;
	
	
	for (int i=0; i<3; i++){
		cout<<"======================================="<<endl;
		cout<<"              Menu Login             "<<endl;
		cout<<"=======================================\n"<<endl;
		
		cout<<"Masukkan username : ";
		cin>>name;
		cout<<"Masukkan password : ";
		cin>>nim;
		system("cls||clear");
		if (name==nama && nim==pin){
			
			string pendonor[MAX];
			string golongan[MAX];
			string jenis[4] = {"A","B","AB","O"};
			int stok[MAX];
			int pilih;
			int jumlah = 0,stokA = 0, stokB = 0, stokAB = 0, stokO = 0;
			
			
			do{
			cout<<"======================================="<<endl;
			cout<<" Sistem Pengelolaan Stok Kantong Darah "<<endl;
			cout<<"=======================================\n"<<endl;
			cout<<"1. Tambah stok darah\n";
			cout<<"2. Baca Data\n";
			cout<<"3. Ubah Data\n";
			cout<<"4. Hapus Data\n";
			cout<<"5. Keluar dari Program\n";
			cout<<"======================================="<<endl;
			cout<<"Pilih Program : ";
			cin>>pilih;
			
			switch(pilih){
				case 1:
					system("cls||clear");
					if(jumlah>=MAX){
						cout<<"Data sudah Penuh, Tidak dapat menambah data lagi"<<endl;
					}else{
						cout<<"======================================="<<endl;
						cout<<"              Tambah data              "<<endl;
						cout<<"=======================================\n"<<endl;
						cout<<"Nama Pendonor : ";
						cin.ignore();
						getline(cin,pendonor[jumlah]);
						for (int i=0; i<4; i++){
							cout<<i+1<<".golongan : "<<jenis[i]<<endl;
						}
						cout<<"Golongan Darah : ";
						getline(cin,golongan[jumlah]);
						cout<<"Jumlah stok darah : ";
						cin>>stok[jumlah];
						if (golongan[jumlah] == "A") {stokA += stok[jumlah];}
						else if (golongan[jumlah] == "B") {stokB += stok[jumlah];}
						else if (golongan[jumlah] == "AB") {stokAB += stok[jumlah];}
						else if (golongan[jumlah] == "O") {stokO += stok[jumlah];}
						jumlah++;
						cout<<"Data Berhasil di Tambah"<<endl;
					}			
					break;
					
				case 2:
					system("cls||clear");
					cout<<"======================================="<<endl;
					cout<<"               Lihat Data              "<<endl;
					cout<<"=======================================\n"<<endl;
					cout<<"1. Lihat Jumlah stok Darah"<<endl;
					cout<<"2. Lihat Detail data pendonor"<<endl;
					cout<<"======================================="<<endl;
					cout<<"PIlihan : ";
					cin>>pilih;
					if (pilih == 1){
						cout<<"Golongan "<<jenis[0]<<"	: "<<stokA<<endl;
						cout<<"Golongan "<<jenis[1]<<"	: "<<stokB<<endl;
						cout<<"Golongan "<<jenis[2]<<"	: "<<stokAB<<endl;
						cout<<"Golongan "<<jenis[3]<<"	: "<<stokO<<endl;
						}
					
					else if(pilih ==2){
						if(jumlah<=0){
						cout<<"___Data Kosong___"<<endl;
						}
						else{
						cout<<"======================================="<<endl;
						cout<<"        Data Stok Kantong Darah          "<<endl;
						cout<<"=======================================\n"<<endl;\
						cout<<"No"<<"|	   Nama		|	Golongan	|	Jumlah darah	|"<<endl;
						for (int i=0; i<jumlah; i++){
						cout<<i+1<<" |	"<<pendonor[i]<<"		|	"<<golongan[i]<<"		|	"<<stok[i]<<"		|"<<endl;
							}
						cout<<"======================================="<<endl;
					
						}
					}else{
						cout<<"pilihan tidak Valid"<<endl;
					}
					
					break;
					
				case 3:
					system("cls||clear");
					if(jumlah<=0){
						cout<<"____Data kosong____";
					}
					else{
						cout<<"======================================="<<endl;
						cout<<"               Ubah Data               "<<endl;
						cout<<"=======================================\n"<<endl;
						cout<<"No"<<"|	   Nama		|	Golongan	|	Jumlah darah	|"<<endl;
						for (int i=0; i<jumlah; i++){
						cout<<i+1<<" |	"<<pendonor[i]<<"		|	"<<golongan[i]<<"		|	"<<stok[i]<<"		|"<<endl;
							}
						cout<<"======================================="<<endl;
					}
					cout<<"ubah data ke-: ";
					cin>>pilih;
					cout<<"Nama Pendonor : ";
					cin.ignore();
					getline(cin,pendonor[pilih-1]);
					cout<<"Golongan Darah : ";
					getline(cin,golongan[pilih-1]);
					cout<<"Jumlah stok darah : ";
					cin>>stok[pilih-1];
					
					cout<<"Data berhasil diubah"<<endl;
					break;
				
				case 4:
					system("cls||clear");
					if(jumlah<=0){
						cout<<"___Data Kosong___";
					}
					else{
						cout<<"======================================="<<endl;
						cout<<"               Hapus Data               "<<endl;
						cout<<"=======================================\n"<<endl;
						cout<<"No"<<"|	   Nama		|	Golongan	|	Jumlah darah	|"<<endl;
						for (int i=0; i<jumlah; i++){
						cout<<i+1<<" |	"<<pendonor[i]<<"		|	"<<golongan[i]<<"		|	"<<stok[i]<<"		|"<<endl;
							}
						cout<<"pilihan : ";
						cin>>pilih;
						for (int i=pilih-1; i<jumlah-1; i++){
							pendonor[i]=pendonor[i+1];
							golongan[i]=golongan[i+1];
							stok[i]    =stok[i+1];
						}
						if (golongan[pilih-1] == "A") {stokA -= stok[pilih-1];}
						else if (golongan[pilih-1] == "B") {stokB -= stok[pilih-1];}
						else if (golongan[pilih-1] == "AB") {stokAB -= stok[pilih-1];}
						else if (golongan[pilih-1] == "O") {stokO -= stok[pilih-1];}
						
						jumlah--;
						cout<<"Data berhasil di hapus"<<endl;	
					}
					
					break;
				
				case 5:
					system("cls||clear");
					cout<<"Anda keluar dari Program. Terimakasih"<<endl;
				break;
				
				default:
					system("cls||clear");
					cout<<"Pilihan Tidak Valid. Pilih dengan Benar"<<endl;
				break;
				}
				
			}while(pilih !=5);
		break;
			
		}else if(i<2){
			cout<<"Username atau Password salah!! Silahkan Login ulang"<<endl;
			cout<<"Kesempatan anda "<<3-(i+1)<<" kali lagi"<<endl;
		}
		else{
			cout<<"Gagal login akun Anda terblokir!!"<<endl;
			break;
		}
		
	}
	
	return 0;
}
