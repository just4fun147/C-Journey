#include "header.h"

int main(int argc, char *argv[]) {
	int a,coun=0,i,cek,cekHapus=0,cekMenu,pesen;
	Menu m[5];
	string nama,jenis;
	float harga,hartot,bayar;
	int jumlah;
	
	init(&m);
	menu:
	system("cls");
	printf("- Restoran Pak Sutedjo -");
	printf("\n1. Tambah Menu");
	printf("\n2. Tampil Menu");
	printf("\n3. Ubah Jumlah Menu");
	printf("\n4. Hapus Menu");
	printf("\n0. Keluar Program");
	printf("\n[MENU TUGAS]");
	printf("\n5. Tambah Menu(Nama Menu Unik)");
	printf("\n6. Transaksi Pembelian");
	printf("\n>>>> ");scanf("%d",&a);
	switch(a){
		case 1:
			if(coun==5){
				printf("\nMenu sudah penuh!");
				getch();
				goto menu;
			}
			printf("Nama Menu: ");fflush(stdin);gets(nama);
			printf("Jenis Menu: ");fflush(stdin);gets(jenis);
			printf("Harga Menu: ");scanf("%f",&harga);
			printf("Jumlah Menu: ");scanf("%d",&jumlah);
			printf("Berhasil tambah menu!");
			m[coun]=tambahMenu(nama,jenis,harga,jumlah);
			coun++;
			getch();
			goto menu;
		case 2:	
			if(coun==0){
				printf("\nTidak ada menu untuk ditampilkan");
				getch();
				goto menu;
			} 
			
			if(cekHapus==1){
				tampilMenu1(m,coun);
				getch();
				goto menu;
			}
			tampilMenu(m,coun);
			getch();
			goto menu;
			
		case 3:
			if(coun==0){
				printf("\nMenu masih kosong");
				getch();
				goto menu;
			}
			
			printf("Nama Makanan : ");fflush(stdin);gets(nama);
			
			for(i=0;i<5;i++){
				if(strcmp(m[i].nama,nama)==0){
					tampilSebagian(m,i);
					cek=i;
					break;
				}else{
					printf("Nama tidak ditemukan!");
					getch();
					goto menu;
				}
			}
			printf("\nMasukan jumlah menu baru: ");scanf("%d",&jumlah);
			m[cek].jumlah=jumlah;
			printf("Berhasil ubah jumlah menu!");
			getch();
			goto menu;
		case 4:
			if(coun==0){
				printf("\nMenu masih kosong");
				getch();
				goto menu;
			}
			printf("Nama Makanan : ");fflush(stdin);gets(nama);
			for(i=0;i<5;i++){
				if(strcmp(m[i].nama,nama)==0){
					m[i]= tambahMenu("-","-",0,0);
					printf("Menu berhasil dihapus!");
					coun=coun-1;
					cekHapus=1;
					goto bener;
				}
			}
					printf("Nama tidak ditemukan!");
					getch();
					goto menu;
			bener:
			getch();
			goto menu;
		case 0:
			printf("\nTerima Kasih");
			printf("\n- Paulus Pandu Windito 200710755");
			return 0;
		case 5:
			if(coun==5){
				printf("\nMenu sudah penuh!");
				getch();
				goto menu;
			}
			nama:
			printf("Nama Menu: ");fflush(stdin);gets(nama);
			for(i=0;i<coun;i++){
				if(strcmp(nama,m[i].nama)==0){
					printf("Nama Menu Sudah Digunakan!\n");
					goto nama;
				}
			}
			printf("Jenis Menu: ");fflush(stdin);gets(jenis);
			printf("Harga Menu: ");scanf("%f",&harga);
			printf("Jumlah Menu: ");scanf("%d",&jumlah);
			printf("Berhasil tambah menu!");
			m[coun]=tambahMenu(nama,jenis,harga,jumlah);
			coun++;
			getch();
			goto menu;
		case 6:
			cekMenu=0;
			if(coun==0){
				printf("\nTidak ada menu untuk ditampilkan");
				getch();
				goto menu;
			} 
			for(i=0;i<coun;i++){
				if(m[i].jumlah==0){
					cekMenu++;
				}
			}
			if(cekMenu==coun){
				printf("Semua Menu Habis!");
				getch();
				goto menu;
			}
			tampilMenu(m,coun);
			printf("\nSilahkan masukan jumlah menu yang ingin dipesan");
			for(i=0;i<coun;i++){
				if(m[i].jumlah>0){
					pesen:
					printf("\n%s: ",m[i].nama);scanf("%d",&pesen);
					if(m[i].jumlah<pesen){
						printf("Jumlah %s yang tersedia tidak cukup!",m[i].nama);
						goto pesen;
					}else if(pesen<0){
						printf("Inputan tidak boleh negatif!");
						goto pesen;
					}
					m[i].jumlah=m[i].jumlah-pesen;
					hartot = hartot + hitungHarga(m,i,pesen);
				}
				
			}
			printf("\nTotal Harga: %.0f",hartot);
			bayar:
			printf("\nJumlah Pembayaran : ");scanf("%f",&bayar);
			if(bayar<hartot){
				printf("Jumlah Pembayaran Kurang!");
				goto bayar;
			}
			printf("\nKembalian : %.0f",kembalian(bayar,hartot));
			printf("\nTransaksi berhasil");
			getch();
			goto menu;
		default:
			printf("\nTidak ada pilihan!");
			getch();
			goto menu;
			
	}
	
	return 0;
}