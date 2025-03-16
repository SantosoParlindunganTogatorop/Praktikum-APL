#include <iostream>
#include <cstdlib>

using namespace std;


// Menu pilihan yang tersedia
void menu(){
	cout<<"======== Menu ========"<<endl;
	cout<<"======================"<<endl;
	cout<<" 1. Setor Tunai "<<endl;
	cout<<" 2. Cek Saldo "<<endl;
	cout<<" 3. Tarik Tunai "<<endl;
	cout<<" 4. Keluar "<<endl;
	cout<<"======================"<<endl;
	cout<<"======================"<<endl;
}

void eksekusi(){
	
	double jawab,setor,tarik;
	double saldo = 0;
	char ketik;
	
/* Perulangan selalu dijalankan hingga user
	memilih untuk berhenti dari program*/
	
	while (true){
		system("cls");
		
		// Menampilkan dan memilih menu
		menu();
		cout<<"Pilih menu : ";
		cin>>jawab;
		
		// program akan dijalnkan sesuai menu pilihan
		if(jawab == 1){
			cout<<"Masukkan jumlah uang : Rp.";
			cin>>setor;
			saldo +=setor;
		}else if(jawab == 2){
			cout<<"Saldo anda saat ini"<<endl;
			cout<<"Rp."<<saldo<<endl;
			cout<<"======================"<<endl;
			cout<<"Ketik Y lalu enter untuk melanjutkan : ";
			cin>>ketik;
		}else if(jawab == 3){
			cout<<"Masukkan jumlah uang : Rp.";
			cin>>tarik;
			saldo-=tarik;
		}else if(jawab == 4){
			cout<<"Anda keluar dari program terimakasih"<<endl;
			break;
		}else{
			cout<<"======================"<<endl;
			cout<<"Pilihan anda tidak ada di opsi"<<endl;
			cout<<"Ketik Y lalu enter untuk melanjutkan : ";
			cin>>ketik;
		}
	}

}

int main(){
	
	int pin = 6052;
	int Pin,i;
	
	// perulangan untuk mencek pin yang benar dengan batas max 3 kali
	for (i=0; i<3; i++){
		
		// Memasukkan pin yang benar
		cout<<"Masukkan Pin anda : ";
		cin>>Pin;
		
		// system ("cls") digunakan untuk membersihkan terminal sehingga lebih rapi
		system("cls");	
		
		// comditional untuk mencek pin yang benar
		if(Pin==pin){
			eksekusi();
			break;
		}
		else if(i<2){
			cout<<"sandi salah! kesempatan anda "<<3-(i+1)<<" kali lagi"<<endl;
		}else {
			cout<<"Anda salah sandi 3 kali, akun anda terblokir !"<<endl;
		}
	}
	return 0;
}

