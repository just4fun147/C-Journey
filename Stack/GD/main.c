#include "header.h"


int main(int argc, char *argv[]) {
	int pil;
	infoType data;
	Stack s;
	
	init(&s);
	
	do{
		system("cls");
		printf("\t---MODUL 3 STACK ARRAY---");
		printf("\n[1]. PUSH");
		printf("\n[2]. POP");
		printf("\n[3]. SHOW");
		printf("\n[0]. BYE");
		printf("\n>>> "); scanf("%d",&pil);
		
		switch(pil){
			default:
				printf("Pilihan tidak tersedia [!]");
				break;
			
			case 1:
				if(!isFull(s)){
					printf("\n Masukan Data Angka : "); scanf("%d",&data);
					push(&s,data);
				}else{
					printf("\n Stack Penuh [!]");
				}
				break;
			case 2:
				if(!isEmpty(s)){
					printf("\nData %d berhasil dikeluarkan",pop(&s)); 
				}else{
					printf("\n Stack Kosong [!]");
				}
				break;
			case 3:
				if(!isEmpty(s)){
					show(s);
				}else{
					printf("\n Stack Kosong [!]");
				}
				break;
			case 0:
				printf("Paulus Pandu Windito-200710755");
				break;
		}
		getch();
	}while(pil!=0);
	return 0;
}