#include "header.h"

int main(int argc, char *argv[]) {
	Pegawai P[size];
	string nama;
	int menu,sisaArr=0,tempSisa=0,jumlahInput=0;
	int a,i=0,jumlahItem,target;
	
	initNama(P,size-1);
	srand((unsigned) time(&a));
	target=rand()%1500+500;
	
	do{
		system("cls");
		printf("\nTarget Bulan Ini: %d Item",target);
		printf("\n[1]. Input Pegawai");
		printf("\n[2]. Bekerja");
		printf("\n[3]. Pembayaran Gaji");
		printf("\n[0]. Keluar Perusahaan");
		printf("\n[6]. Set Target");
		printf("\n[7]. Bekerja(TUGAS)");
		printf("\n[8]. Pembayaran Gaji(TUGAS)");
		printf("\n[9]. Keluar Perusahaan(TUGAS)");
		printf("\nMasukan Menu: ");scanf("%d",&menu);
		
		switch(menu){
			case 1:
					inputNama(P,0);
				printf("\nSilahkan langsung bekerja");
				break;
			case 2:
				if(cekKosong(P,size-1)==size-1){
					printf("\nSilahkan melakukan open recruitment terlebih dahulu...");
					break;
				}
				printf("\nMasukan Nama Pegawai yang akan bekerja : ");fflush(stdin);gets(nama);
				
				bekerja(P,nama,target);
				
				break;
			case 3:
				if(cekKosong(P,size-1)==size-1){
					printf("\nSilahkan melakukan open recruitment terlebih dahulu...");
					break;
				}
				 tampilNama(P,size-1);
				break;
			case 0:
				if(cekKosong(P,size-1)==size-1){
					printf("\nSilahkan melakukan open recruitment terlebih dahulu...");
					break;
				}
				if(kluar(P,size-1,target)==-1){
					printf("\nTeman anda masih belum selesai bekerja, Anda tidak boleh keluar");
					break;
				}
				printf("\nPaulus Pandu Windito-E-200710755");
				return 0;
			case 6:
				printf("set target: ");scanf("%d",&target);
				break;
			case 7:
				if(cekKosong(P,size-1)==size-1){
					printf("\nSilahkan melakukan open recruitment terlebih dahulu...");
					break;
				}
				printf("\nMasukan Nama Pegawai yang akan bekerja : ");fflush(stdin);gets(nama);
				bekerja2(P,nama,target);
				break;
			case 8:
				if(cekKosong(P,size-1)==size-1){
					printf("\nSilahkan melakukan open recruitment terlebih dahulu...");
					break;
				}
				 tampilNama(P,size-1);
				break;
			case 9:
				if(cekKosong(P,size-1)==size-1){
					printf("\nSilahkan melakukan open recruitment terlebih dahulu...");
					break;
				}
				if(kluar2(P,size-1,target)>-1){
					printf("\nTeman anda masih belum selesai bekerja, Anda tidak boleh keluar");
					break;
				}
				printf("\nPaulus Pandu Windito-E-200710755");
				return 0;
			default:
				
				break;
		}
		getch();
	}while(menu!=11);
	return 0;
}