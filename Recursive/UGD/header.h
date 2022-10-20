//Paulus Pandu Windito/200710755/E
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 5

typedef char string[50];
typedef struct{
	string nama;
	int jumlahItem;
}Pegawai;

void initNama(Pegawai P[],int index);
int cekKosong(Pegawai P[],int index);
int cekSisa(string nama[],int index,int sisa);
void inputNama(Pegawai P[],int index);
void tampilNama(Pegawai P[],int index);
void bekerja(Pegawai P[],string nama,int target);
int cekPegawai(Pegawai P[],int index,string nama);
void PrintKerja(Pegawai P[],int index,int hari,int target);
int kluar(Pegawai P[],int index,int target);
void bekerja2(Pegawai P[],string nama,int target);
void PrintKerja(Pegawai P[],int index,int hari,int target);
int kluar2(Pegawai P[],int index,int target);