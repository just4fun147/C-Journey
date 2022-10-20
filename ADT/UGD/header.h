#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//isi struct,prosedur,fungsi(headernya aja)
typedef char string[100];

typedef struct{
	string nama;
	string jenis;
	float harga;
	int jumlah;
	
}Menu;

void init(Menu *m);

Menu tambahMenu(string nama,string jenis,float harga,int jumlah);

void tampilMenu(Menu m[],int coun);
void tampilMenu1(Menu m[],int coun);
void cari(Menu m[],string nama);
void tampilSebagian(Menu m[],int i);
void ubahJumlah(Menu *m[],int jumlah,int cek);

float hitungHarga(Menu m[],int i,int pesen);
float kembalian(float bayar,float hartot);

