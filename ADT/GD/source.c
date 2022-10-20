#include "header.h"

void initMahasiswa(Mahasiswa *m){
	strcpy(m->nama,"-");
	strcpy(m->npm,"-");
}

Mahasiswa makeMahasiswa(string nama,string npm){
	Mahasiswa m;
	strcpy(m.nama,nama);
	strcpy(m.npm,npm);
	
	return m;
}

void tampilMahasiswa(Mahasiswa m){
	printf("\nNama : %s",m.nama);
	printf("\nNPM : %s",m.npm);
}