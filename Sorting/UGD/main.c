#include "header.h"



int main(int argc, char *argv[]) {
	int n=-1,pilih,lama;
	string nama,warna,ukuran;
	array a;
	createEmpty(&a);
	
	do{
		system("cls");
		printf("\tSewa Tenda Pak Supardjo");
		printf("\n1. Input Data Array");
		printf("\n2. Tampil Data Array");
		printf("\n3. Sorting Lama Sewa");
		printf("\n4. Sorting Nama Penyewa");
		printf("\n0. Exit");
		printf("\n[Menu Tugas]");
		printf("\n5. Quick Sort");
		printf("\nMasukkan pilihan menu : ");scanf("%d",&pilih);
		
		switch(pilih){
			case 1:
				if(n!=4){
					n++;
					setArray(&a,n);
				}else{
					printf("Array sudah penuh!");
				}
				
				break;
			
			case 2:
				if(isEmpty(a)){
					printf("Data Kosong");
					break;
				}
				printInfo(a);
				break;
			
			case 3:
				if(isEmpty(a)){
					printf("Data Kosong");
					break;
				}
				mergeSort(&a);
				printf("\nBerhasil sorting berdasarkan lama sewa!");
				break;
			case 4:
				if(isEmpty(a)){
					printf("Data Kosong");
					break;
				}
				bubbleSort(&a);
				printf("\nBerhasil sorting berdasarkan nama penyewa!");
				break;
			case 5:
				if(isEmpty(a)){
					printf("Data Kosong");
					break;
				}
				quickSort(&a,0,a.last);
				printf("\nBerhasil sorting berdasarkan warna tenda!");
				break;
			case 0:
				printf("\nPaulus Pandu Windito-E-200710755");
				break;
			default:
				printf("\nTidak ada pilihan!");
				break;
		}
		getch();
	}while(pilih!=0);
	return 0;
}