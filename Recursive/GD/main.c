#include "header.h"

int main(int argc, char *argv[]) {
	string nama[size];
	int menu,sisaArr=0,tempSisa=0,jumlahInput=0;
	
	initNama(nama,size-1);
	
	do{
		system("cls");
		printf("\nGUIDED MODUL 9 - Rekursif");
		printf("\n[1]. Input");
		printf("\n[2]. Tampil");
		printf("\n[0]. Keluar");
		printf("\nMasukan Menu: ");scanf("%d",&menu);
		
		switch(menu){
			case 1:
				sisaArr=cekSisa(nama,size-1,tempSisa);
				if(sisaArr==0){
					printf("\nArray Penuh!");
				}else{
					do{
						printf("\nMasukkan Jumlah Input: ");scanf("%d",&jumlahInput);
						if(jumlahInput>sisaArr){
							printf("\nArray Penuh");
						}
					}while(jumlahInput<-0||jumlahInput>sisaArr);
					inputNama(nama,jumlahInput);
				}
				break;
			case 2:
				tampilNama(nama,size-1);
				break;
			case 0:
				printf("\nTerima Kasih!");
		}
		getch();
	}while(menu!=0);
	return 0;
}