#include "header.h"



int main(int argc, char *argv[]) {
	int menu=-1,prevdata,resi,berat,bayar,total=0;
	string nama,tujuan,jenis;
	List L;
	addr delNode;
	
	createEmpty(&L);

	while(menu!=0){
		system("cls");
		puts("1. Catat Barang");
		puts("2. Bayar");
		puts("3. Cek Status");
		puts("4. Hapus Paket");
		puts("5. Tampil Paket");
		puts("");
		puts("MENU TUGAS");
		puts("6. Ubah Status Paket");
		puts("7. Hapus Paket TGS");
		puts("8. Total Pendapatan");
		puts("0. Keluar");
		printf("\n>>");scanf("%d", &menu);
		
		switch(menu){
			case 1:
				printf("\nNo Resi: ");scanf("%d",&resi);
				printf("Berat: ");scanf("%d",&berat);
				printf("Nama Barang: ");fflush(stdin);gets(nama);
				printf("Kota Tujuan: ");fflush(stdin);gets(tujuan);
				printf("Jenis Pengiriman[EXPRESS||REGULAR||BASIC]: ");fflush(stdin);gets(jenis);						
				delNode=alokasi(resi,berat,nama,tujuan,jenis);
				insertLast(&L,delNode);
				break;
			case 2:
				if(isEmpty(L)){
					printf("List Kosong");
					break;
				}
				printf("\nNo Resi: ");scanf("%d",&resi);
				delNode=findNode(L,resi);
				if(delNode==NULL){
					printf("No Resi Tidak Terdaftar");
					break;
				}
				if(strcmpi(delNode->bayar,"Sudah Dibayar")==0){
					printf("Paket sudah dibayar");
					break;
				}
				printf("Total Harga: %d",delNode->harga*delNode->berat);
				printf("\nJumlah Bayar: ");scanf("%d",&bayar);
				if(bayar<delNode->harga){
					printf("Uang Kurang");
					break;
				}
				printf("Kembalian: %d",bayar-delNode->harga*delNode->berat);
				total=total+delNode->harga*delNode->berat;
				
				pembayaran(&L,resi);
				break;
			case 3:
				if(isEmpty(L)){
					printf("List Kosong");
					break;
				}
				printf("\nNo Resi: ");scanf("%d",&resi);
				delNode=findNode(L,resi);
				if(delNode==NULL){
					printf("No Resi Tidak Terdaftar");
					break;
				}
				printf("Status Paket: %s",delNode->status);
				break;
			case 4:
				if(isEmpty(L)){
					printf("List Kosong");
					break;
				}
				printf("\nNo Resi: ");scanf("%d",&resi);
				delNode=findNode(L,resi);
				if(delNode==NULL){
					printf("No Resi Tidak Terdaftar");
					break;
				}
				deleteAt(&L,delNode);
				break;
			case 5:
				if(isEmpty(L)){
					printf("List Kosong");
					break;
				}
				printAll(L);
				break;
			case 6:
				if(isEmpty(L)){
					printf("List Kosong");
					break;
				}
				printf("\nNo Resi: ");scanf("%d",&resi);
				delNode=findNode(L,resi);
				if(delNode==NULL){
					printf("No Resi Tidak Terdaftar");
					break;
				}
				ubahStatus(&L,resi);
				break;
			case 7:
				if(isEmpty(L)){
					printf("List Kosong");
					break;
				}
				printf("\nNo Resi: ");scanf("%d",&resi);
				delNode=findNode(L,resi);
				if(delNode==NULL){
					printf("No Resi Tidak Terdaftar");
					break;
				}
				if(strcmpi(delNode->bayar,"Sudah Dibayar")==0){
					printf("Paket Sudah Dibayar");
					break;
				}
				deleteAt(&L,delNode);
				break;
				break;
			case 8:
				if(isEmpty(L)){
					printf("List Kosong");
					break;
				}
				printf("\nTotal Pendapatan: %d",total);
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