#include "header.h"

int main(int argc, char *argv[]) {
	Mahasiswa m;
	string nama,npm;
	
	initMahasiswa(&m);
	
	printf("\n- Data Mahasiswa Setelah Inisialisasi -");
	tampilMahasiswa(m);
	
	printf("\n\n- Input Data Baru -");
	printf("\nMasukan Nama Anda : ");fflush(stdin);gets(nama);
	printf("\nMasukan NPM Anda : ");fflush(stdin);gets(npm);
	
	m = makeMahasiswa(nama,npm);
	
	printf("\n- Data Mahasiswa Setelah Input -");
	tampilMahasiswa(m);
	
	getch();
	return 0;
}