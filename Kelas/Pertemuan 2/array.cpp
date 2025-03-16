#include <iostream>
using namespace std;

int main(){
	
string nama[5] = {"Dimas","Harahap","santoso","kalingga","ucup"};
	
//int angka[3];
//angka[0] = 1;
//angka[1] = 2;
//angka[2] = 3;


//cout<<"nama "<<nama[1]<<endl;
//cout<<"angka "<<angka[2]<<endl;

//int panjang1 =sizeof(angka)/sizeof (angka[0]);
//int panjang2 = sizeof(angka)/sizeof(int);
//
//cout<<"panjang 1 : "<<panjang1<<endl;
//cout<<"panjang 2 : "<<panjang2<<endl;
//
//cout<<sizeof(angka);

int angka[5] = {1,2,3,4,5};
int panjang1 =sizeof(angka)/sizeof (angka[0]);
angka[1]=6;

//Perulangan

//cout<<angka<<endl;
//for (int i=0; i<panjang1; i++){
//	cout<<&angka[i]<<endl;
//}

for(int i= 0; i<panjang1; i++){
	cout<<angka[i]<<endl;
}

//for(int item:angka){
//	cout<<item<<endl;
//}

return 0;
}
