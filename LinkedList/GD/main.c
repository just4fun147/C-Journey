#include "header.h"


int main(int argc, char *argv[]) {
	List L;
	Data D;
	int npm,menu;
	string nama;
	
	createEmpty(&L);
	
	do{
		system("cls");
		printf("Guided Linked List");
		printf("\n [1] Insert First");
		printf("\n [2] Insert Last");
		printf("\n [3] Delete First");
		printf("\n [4] Delete Last");
		printf("\n [5] Show List");
		printf("\n [0] Keluar");
		printf("\n\nPilih Menu : ");scanf("%d",&menu);
		
		switch(menu){
			case 1:
				printf("\nMasukan NPM\t: -");scanf("%d",&npm);
				printf("\nMasukan Nama\t: ");fflush(stdin);gets(nama);
				D=makeData(npm,nama);
				insertFirst(&L,D);
				break;
			case 2:
				printf("\nMasukan NPM\t: ");scanf("%d",&npm);
				printf("\nMasukan Nama\t: ");fflush(stdin);gets(nama);
				D=makeData(npm,nama);
				insertLast(&L,D);
				break;
			case 3:
				deleteFirst(&L);
				break;
			case 4:
				deleteLast(&L);
				break;
			case 5:
				showList(L);
				break;
			case 0:
				printf("\n\t[!] Terima Kasih [!]\n");
				break;
			default:
				printf("\n\t[!] Menu tidak ada [!]\n");
				break;
		}
		getch();
	}while(menu!=0);
	return 0;
}