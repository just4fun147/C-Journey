#include "header.h"


int main(int argc, char *argv[]) {
	Inventory inven;
	int pil,g,id,pil2,pil3,i,j;
	string nama,stack;
	Kartu k;
	init(&inven);

	menu:
	system("cls");
	printf("\t---UGD 3 Stack Array (A---)");
	printf("\n[1] Gacha Get Card");
	printf("\n[2] Show Card");
	printf("\n[3] Delete Card");
	printf("\n[4] Exit");
	printf("\n>>> ");scanf("%d",&pil);
	
	switch(pil){
		default:
			printf("Pilihan tidak tersedia [!]");
			getch();
			goto menu;
		case 1:
			if(!isFull(inven,1)||!isFull(inven,2)||!isFull(inven,3)){
				printf("\n\t---Special Banner--- ");
				printf("\nTry Your Luck");
				printf("\nPress Enter to Summon...");
				getch();
				g = gacha();
				if(g==0){
					printf("\nCongratulation You Got Common Card! (*)");
					}
				if(g==1){
					printf("\nCongratulation You Got Uncommon Card! (**)");
					}
				if(g==2){
					printf("\nCongratulation You Got Rare Card! (***)");
					}		
				inputNama:
				printf("\n\nCard Name : ");fflush(stdin);gets(nama);
				if(strcmpi(nama,"-")==0||strlen(nama)<=0){
					printf("[!] Nama Tidak Boleh Kosong");
					goto inputNama;
					}
				inputID:
				printf("ID Card : ");scanf("%d",&id);
				if(id==0){
					printf("[!] ID Tidak Boleh Kosong");	
					goto inputID;
				}
				
				k = inputKartu(nama,id,g);
				push(&inven,k,g);


				printf("\nCard Saved[!]");	
			}else{
				printf("\nKartu Penuh [!]");
			}
			getch();
			goto menu;
		case 2:
			printf("\n\n[1] Show All Cards");
			printf("\n[2] Show Card by Rarity");
			printf("\n>>> ");scanf("%d",&pil2);
			switch(pil2){
				default:
					printf("\n Menu tidak tersedia [!]");
					getch();
					goto menu;
				case 1:
					show(inven);
					getch();
					goto menu;
				case 2:
					printf("\n\n(Common/Uncommon/Rare)");
					printf("\nJenis Kartu : ");fflush(stdin);gets(nama);
					
					g = cekNama(nama);
					if(g==3){
						printf("Card Rarity not found [!]");
						getch();
						goto menu;
					}
					showSebagian(inven,g);
				getch();
				goto menu;
			}
		case 3:
			if(!isEmpty1(inven)){
				
					printf("\n[1] Delete Top");
					printf("\n[2] Delete by name [Bonus]");
					printf("\n>>>");scanf("%d",&pil3);
				switch(pil3){
					printf("Pilihan tidak tersedia [!]");
					getch();
					goto menu;
				case 1:	
					printf("\n\n(Common/Uncommon/Rare)");
					printf("\nJenis Kartu : ");fflush(stdin);gets(nama);
					
					g = cekNama(nama);
					if(g==3){
						printf("Card Rarity not found [!]");
						getch();
						goto menu;
					}
					if(!isEmpty(inven,g)){
						printKartu(inven,g);
						pop(&inven,g);
						inven.top--;
						
						
					}else{
						printf("Empty [!]");
					}
				case 2:
					printf("\nCard Name : ");fflush(stdin);gets(nama);
					i= cekI(nama,inven);
					j= cekJ(nama,inven);
					if(cek(nama,inven)==0){
						printKartu1(inven,i,j);
						popSatu(&inven,i,j);
					}else{
						printf("\nName not found [!]");
					}
				}
			}else{
				printf("\n All Inventory Empty !");	
			}
				getch();
				goto menu;
		case 4:
			printf("Paulus Pandu Windito|200710755|");
			getch();
			return 0;
	}
	return 0;
}