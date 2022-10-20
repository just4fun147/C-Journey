#include "header.h"

void main(){
	List L;
	address temp,before;
	infotype bil;
	int menu;
	
	createEmpty(&L);
	
	do{
	system("cls");
	printf("\n\n\t GUIDED LINKED LIST 2\n");
	printf("\n\t 1. Insert First");
	printf("\n\t 2. Insert After");
	printf("\n\t 3. Insert Last");
	printf("\n\t 4. Delete First");
	printf("\n\t 5. Delete At");
	printf("\n\t 6. Delete Last");
	printf("\n\t 7. Print Data");
	printf("\n\t 0. EXIT");
	printf("\n\t Masukkan Pilihan\t: ");
	scanf("%d",&menu);
	printf("\n\t -------------------------------------\n");
	
	switch(menu){
		case 1:
			printf("\n\t Masukkan bilangan bulat\t: ");
			scanf("%d",&bil);
			temp = alokasi(bil);
			insertFirst(&L,temp);
			printf("\n\t Insert berhasil");
			break;
		
		case 2:
			printf("\n\t Bilangan yang baru ingin dimasukkan setelah bilangan berapa? ");
			scanf("%d",&bil);
			before = findNode(L,bil);
			if(before==NULL){
				printf("\n\t [!] Bilangan tersebut tidak ditemukan");
				break;
			}
			printf("\n\t Masukkan bilangan bulat\t: ");
			scanf("%d",&bil);
			temp = alokasi(bil);
			insertAfter(before,temp);
			printf("\n\t Insert berhasil");
			break;
			
		case 3:
			printf("\n\t Masukkan bilangan bulat\t: ");
			scanf("%d",&bil);
			temp = alokasi(bil);
			insertLast(&L,temp);
			printf("\n\t Insert berhasil");
			break;
			
		case 4:
			if(isEmpty(L)){
				printf("\n\t [!] List kosong!");
				break;
			}
			deleteFirst(&L);
			printf("\n\t Delete berhasil");
			break;
			
		case 5:
			if(isEmpty(L)){
				printf("\n\t [!] List kosong!");
				break;
			}
			printf("\n\t Masukkan bilangan bulat yang ingin dihapus\t:");
			scanf("%d",&bil);
			temp = findNode(L,bil);
			if(temp==NULL){
				printf("\n\t [!] Bilangan tersebut tidak ditemukan");
				break;
			}
			deleteAt(&L,temp);
			printf("\n\t Delete berhasil");
			break;
			
		case 6:
			if(isEmpty(L)){
				printf("\n\t [!] List kosong!");
				break;
			}
			deleteLast(&L);
			printf("\n\t Delete berhasil");
			break;
			
		case 7:
			if(isEmpty(L)){
				printf("\n\t [!] List kosong!");
				break;
			}
			printData(L);
			break;
			
		case 0:
			printf("\n\t Exit");
			break;
		default :
			printf("\n\t [!] Pilihan tersebut tidak valid");
			break;
	}
	getch();
	}while(menu!=0);
}