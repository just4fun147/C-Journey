#include "header.h"

void init(Menu *m){
	strcpy(m->nama,"-");
	strcpy(m->jenis,"-");
	m->harga=0;
	m->jumlah=0;
}
Menu tambahMenu(string nama,string jenis,float harga,int jumlah){
	Menu m;
	strcpy(m.nama,nama);
	strcpy(m.jenis,jenis);
	m.harga=harga;
	m.jumlah=jumlah;
	return m;
}
void tampilMenu(Menu m[],int coun){
	int i;

	for(i=0;i<coun;i++){
		if(strcmp(m[i].nama,"-")==0){
			printf(" ");
		}else{
			printf("\n\nNama Menu : %s",m[i].nama);
			printf("\nJenis Menu : %s",m[i].jenis);
			printf("\nHarga Menu : %.0f",m[i].harga);
			printf("\nJumlah Menu : %d",m[i].jumlah);
			printf("\n-------------------------");
		}
		
		}

}
void tampilMenu1(Menu m[],int coun){
	int i;

	for(i=0;i<=coun;i++){
		if(strcmp(m[i].nama,"-")==0){
			printf(" ");
		}else{
			printf("\n\nNama Menu : %s",m[i].nama);
			printf("\nJenis Menu : %s",m[i].jenis);
			printf("\nHarga Menu : %.0f",m[i].harga);
			printf("\nJumlah Menu : %d",m[i].jumlah);
			printf("\n-------------------------");
		}
		
		}

}
void tampilSebagian(Menu m[],int i){
		printf("\n\nNama Menu : %s",m[i].nama);
		printf("\nJenis Menu : %s",m[i].jenis);
		printf("\nHarga Menu : %.0f",m[i].harga);
		printf("\nJumlah Menu : %d",m[i].jumlah);
		printf("\n-------------------------");
}

void ubahJumlah(Menu *m[],int jumlah,int cek){
	m[cek]->jumlah=jumlah;
}

float hitungHarga(Menu m[],int i,int pesen){
	
	
	return pesen*m[i].harga;
}

float kembalian(float bayar,float hartot){
	return 	bayar-hartot;
}
