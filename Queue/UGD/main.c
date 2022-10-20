#include "header.h"

int main(int argc, char *argv[]) {
	Queue Q1,Q2;
	data d;
	int pil,umur,temp,cek,temp2=-1;
	float nilaiFrontend,nilaiBackend;
	string nama,opsi;
	
	createEmpty(&Q1);
	createEmpty(&Q2);
	
	do{
		system("cls");
		printf("=== UNGUIDED QUEUE - (PAKET E) ===");
		printf("\n[1] Tambah Antrian Pelamar Belum Seleksi Administrasi");
		printf("\n[2] Tampil Antrian Pelamar Belum Seleksi Administrasi");
		printf("\n[3] Seleksi Administrasi");
		printf("\n[4] Tampil Antrian Pelamar Lolos Administrasi");
		printf("\n[5] Mulai Interview");
		printf("\n[6] Tampil Detail Antrian Pelamar(Lolos Administrasi)(Bonus)");
		printf("\n[7] Edit Antrian Pelamar (Belum Seleksi Administrasi)(Bonus)");
		printf("\n[0] Keluar");
		printf("\n>>>>");scanf("%d",&pil);
		
		switch(pil){
			default:
				printf("\nMenu tidak tersedia");
			case 1:
				if(!isFull(Q1)){
					inputNama:
					printf("\nMasukan Nama : ");fflush(stdin);gets(nama);
					if(strcmpi(nama,"")==0){
						printf("[!] Nama tidak boleh kosong");
						goto inputNama;
					}
					temp = cekNama(Q1,Q2,nama);
					if(temp==1){
						printf("[!] Nama tidak boleh sama");
						goto inputNama;
					}
					inputUmur:
					printf("Masukan Umur : ");scanf("%d",&umur);
					if(umur<=0){
						printf("[!] Umur tidak boleh kosong\n");
						goto inputUmur;
					}
					inputFront:
					printf("Masukan Nilai Front End : ");scanf("%f",&nilaiFrontend);
					if(nilaiFrontend<=0){
						printf("[!] Nilai Frontend tidak boleh kosong\n");
						goto inputFront;
					}
					inputBack:
					printf("Masukan Nilai Back End : ");scanf("%f",&nilaiBackend);
					if(nilaiBackend<=0){
						printf("[!] Nilai Backend tidak boleh kosong\n");
						goto inputBack;
					}
					d = makeData(nama, umur, nilaiFrontend, nilaiBackend);
					enqueue(&Q1, d);
					printf("\nBerhasil menabahkan data!");
				}else{
					printf("\n[!] Antrian sudah penuh!");
				}
				break;
			case 2:
				if(!isEmpty(Q1)){
					Print(Q1);
				}else{
					printf("\n[!] Antrian masih kosong!");
				}
				break;
			case 3:
				if(!isFull(Q2)){
				
				if(!isEmpty(Q1)){
					if(cekPelamar(Q1)==1){
						printf("Nama Pelamar [%s] Ditolak, tidak memenuhi syarat",Q1.d[Q1.head].nama);
						dequeue(&Q1);
					}else{
						printf("Nama Pelamar [%s] Lolos Administrasi",Q1.d[Q1.head].nama);
						d = Q1.d[Q1.head];
						enqueue(&Q2,d);
						dequeue(&Q1);
					}
				}else{
					printf("\n[!] Antrian masih kosong!");
				}
			}else{
				printf("\n[!]Antrian sudah penuh!");
			}
				break;
			case 4:
				if(!isEmpty(Q2)){
					Print(Q2);
				}else{
					printf("\n[!] Antrian masih kosong!");
				}
				break;
			case 5:
				if(!isEmpty(Q2)){
					printf("Mulai interview untuk [%s] sekarang(y/t) : ",Q2.d[Q2.head].nama);fflush(stdin);gets(opsi);
				if(strcmpi(opsi,"y")==0){
					dequeue(&Q2);
					printf("[*] Berhasil mulai interview !");
					}
				}else{
					printf("\n[!]Antrian Masih Kosong");
				}
				
				break;
			case 6:
				if(!isEmpty(Q2)){
				printf("Masukan Nama : ");fflush(stdin);gets(nama);
				temp = isFound(Q2,nama);
				if(temp!=-1){
					show(Q2,temp);
					
				}else if(temp=-1){
					printf("Data tidak ditemukan");
				}
					}else{
					printf("\n[!]Antrian Masih Kosong");
				}
				break;
			case 7:
				if(!isEmpty(Q1)){
				printf("Masukan Nama : ");fflush(stdin);gets(nama);
				temp2 = isFound(Q1,nama);
				if(temp2!=-1){
					show(Q1,temp2);
					inputNama1:
					printf("\nMasukan Nama : ");fflush(stdin);gets(nama);
					if(strcmpi(nama,"")==0){
						printf("[!] Nama tidak boleh kosong");
						goto inputNama1;
					}
					temp = cekNama(Q1,Q2,nama);
					if(temp==1){
						printf("[!] Nama tidak boleh sama");
						goto inputNama1;
					}
					inputUmur1:
					printf("Masukan Umur : ");scanf("%d",&umur);
					if(umur<=0){
						printf("[!] Umur tidak boleh kosong\n");
						goto inputUmur1;
					}
					inputFront1:
					printf("Masukan Nilai Front End : ");scanf("%f",&nilaiFrontend);
					if(nilaiFrontend<=0){
						printf("[!] Nilai Frontend tidak boleh kosong\n");
						goto inputFront1;
					}
					inputBack1:
					printf("Masukan Nilai Back End : ");scanf("%f",&nilaiBackend);
					if(nilaiBackend<=0){
						printf("[!] Nilai Backend tidak boleh kosong\n");
						goto inputBack1;
					}
					d = makeData(nama, Q1.d[temp].umur, nilaiFrontend, nilaiBackend);
					edit(&Q1,d,temp2);
					printf("Berhasil mengedit data!");
				}else{
					printf("Data tidak ditemukan");
				}
				}else{
					printf("\n[!]Antrian Masih Kosong");
				}
				break;
			case 0:
				printf("\nPaulus Pandu Windito-200710755");
				break;
		}
		getch();	
	}while(pil!=0);
	
	return 0;
}