#include "header.h"


int main(int argc, char *argv[]) {
	Queue Q;
	data D;
	int pil,umur,temp=0;
	string confirm,nama;
	
	createEmpty(&Q);
	
	do{
		system("cls");
		puts("=== GUIDED QUEUE ===\n");
		puts("[1] Add Queue");
		puts("[2] Del Queue");
		puts("[3] Printf Queue");
		puts("[4] Found Queue");
		puts("[0] Keluar\n");
		printf("Masukan Pilihan [1-4] : ");scanf("%d",&pil);
		
		switch(pil){
			case 1:
				if(!isFull(Q)){
					printf("\nMasukan Nama : ");fflush(stdin);gets(nama);
					printf("\nMasukan Umur : ");scanf("%d",&umur);
					D = makeData(nama,umur);
					enqueue(&Q,D);
				}else{
					printf("\n[!] Antrian sudah penuh !");
				}
				break;
			case 2:
				if(!isEmpty(Q)){
					printf("\nYakin ingin menghapus elemen [%s] (y/t) : ",Q.D[Q.head].nama);fflush(stdin);gets(confirm);
					
					if(strcmpi(confirm,"y")==0){
						dequeue(&Q);
					}
				}else{
					printf("\n[!] Antrian masih kosong !");
				}
				break;
			
			case 3:
				if(!isEmpty(Q)){
					Print(Q);
				}else{
					printf("\n[!] Antrian masih kosong !");
				}
				break;
			case 4:
				if(!isEmpty(Q)){
					printf("\nMasukan Nama : ");fflush(stdin);gets(nama);
					temp = isFound(Q,nama);
					if(temp!=-1){
						printf("Nama : %s\n",Q.D[temp].nama);
						printf("Umur : %d\n",Q.D[temp].umur);
					}else{
						printf("\n[!] Data tidak ditemukan !");
					}
					
				}else{
					printf("\n[!] Antrian masih kosong !");
				}
				break;
			case 0:
				printf("\n[*] keluar Program");
				break;
			default:
				printf("\n[!] Menu tidak tersedia\n");
		}
		getch();
	}while(pil!=0);
	return 0;
}