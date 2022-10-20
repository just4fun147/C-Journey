#include "header.h"



int main(int argc, char *argv[]) {
	int menu=-1,data,prevdata;
	List L;
	addr delNode;
	
	createEmpty(&L);
	
	while(menu!=0){
		system("cls");
		puts("1. Insert first");
		puts("2. Insert after");
		puts("3. Insert last");
		puts("4. Delete first");
		puts("5. Delete at");
		puts("6. Delete last");
		puts("7. Find data");
		puts("8. Print all");
		puts("0. Keluar");
		printf("\n>>");scanf("%d", &menu);
		
		switch(menu){
			case 1:
				printf("data: ");scanf("%d",&data);
				insertFirst(&L,alokasi(data));
				break;
			case 2:
				printf("data: ");scanf("%d",&data);
				printf("masukkan setelah data: ");scanf("%d",&prevdata);
				insertAfter(&L,alokasi(data),prevdata);
				break;
			case 3:
				printf("data: ");scanf("%d",&data);
				insertLast(&L,alokasi(data));
				break;
			case 4:
				deleteFirst(&L);
				break;
			case 5:
				printf("data yang ingin dihapus: ");scanf("%d",&data);
				delNode=findNode(L,data);
				deleteAt(&L,delNode);
				break;
			case 6:
				deleteLast(&L);
				break;
			case 7:
				printf("data yang ingin dicari: ");scanf("%d",&data);
				
				if(findNode(L,data)==NULL){
					puts("data tidak ada");
				}else{
					puts("data ada");
				}
				break;
			case 8:
				printAll(L);
				break;
			case 0:
				break;
			default:
				puts("invalid");
		}
		puts("");
		system("pause");
		
	}
	return 0;
}