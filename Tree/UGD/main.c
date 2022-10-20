#include "header.h"



int main(int argc, char *argv[]) {
	BinaryTree BT;
	int menu=-1,jumlah;
	string nama,jenis;
	float harga;
	address P;
	createEmpty(&BT);
	
	while(menu!=0){
		system("cls");
		puts("- Restoran Pak Sutedjo- ");
		puts("1. Tambah Menu");
		puts("2. Tampil Menu");
		puts("3. Ubah Jumlah Menu");
		puts("[MENU TUGAS] ");
		puts("4. Hapus Menu");
		puts("0. Keluar");
		printf("\n>>");scanf("%d", &menu);
		
		switch(menu){
			case 1:
				input:
				printf("\nNama Menu : ");fflush(stdin);gets(nama);
				if(isFound(BT,nama)){
					printf("Nama Menu Harus Unik");
					goto input;
				}
				printf("\nJenis Menu : ");fflush(stdin);gets(jenis);
				printf("\nHarga Menu : ");scanf("%f",&harga);
				printf("\nJumlah Menu : ");scanf("%d",&jumlah);
				P=alokasi(nama,jenis,jumlah,harga);
				insTreeBST(&BT,P);
				break;
			case 2:
				if(isEmpty(BT)){
					printf("Tidak Ada Menu Untuk Ditampilkan");
					break;
				}
				inOrder(BT);
				break;
			case 3:
				if(isEmpty(BT)){
					printf("Menu Masih Kosong");
					break;
				}
				printf("Nama Menu : ");fflush(stdin);gets(nama);
				if(!isFound(BT,nama)){
					printf("Nama Menu Tidak Ditemukan!");
					break;
				}
				
				printf("Masukkan jumlah menu baru: ");scanf("%d",&jumlah);
				gantiJumlah(&BT,nama,jumlah);
				break;
			case 4:
				if(isEmpty(BT)){
					printf("Menu Masih Kosong");
					break;
				}
				printf("Nama Menu : ");fflush(stdin);gets(nama);
				if(!isFound(BT,nama)){
					printf("Nama Menu Tidak Ditemukan!");
					break;
				}
				deleteMenu(&BT,nama);
				break;
			case 0:
				printf("Paulus Pandu Windito-200710755");
				break;
			default:
				puts("invalid");
		}
		getch();	
	}
	return 0;
}