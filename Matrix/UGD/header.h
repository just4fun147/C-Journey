#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define X 3
#define Y 3

typedef char string[100];

typedef struct{
	string nama;
	string no;
	int jangkaSewa;
}Penyewa;

typedef struct{
	int idKamar;
	string tipeKamar;
	Penyewa p;
	
}Kamar;

typedef Kamar Matriks[3][3];


Kamar inputKamar(int idKamar,string tipeKamar,string nama,string no,int jangkaSewa);


void init(Matriks *M);
int cekTipe(string tipeKamar);
int cekID(int idKamar,int i);
void tampilMatriks(Matriks M);
int cekKosong(int i, int j,Matriks Mat);
int cekNama(string nama,Matriks Mat);
int cariI(string nama,Matriks Mat);
int cariJ(string nama,Matriks Mat);
void show(int i,int j,Matriks Mat);
Kamar editKamar(string nama,string no,int jangkaSewa,Matriks *Mat,int i,int j);
void tampilSebagian(int i,int j,Matriks Mat);
float biayaSewa(Matriks Mat,int i,int j);