#include "header.h"

void main(){
	List L;
	address temp,before;
	int menu,jumlah=0,ceki;
	string mk,deadline,tanggal,opsi;

	createEmpty(&L);
	
	do{
	system("cls");
	printf("\n\n\t DAFTAR TUGAS\n");
	printf("\n\t 1. Input Data");
	printf("\n\t 2. Tampil Data");
	printf("\n\t 3. TUGAS");
	printf("\n\t 0. EXIT");
	printf("\n\t >>>");
	scanf("%d",&menu);

	
	switch(menu){
		case 1:
			printf("\n\t Total Tugas Sekarang : %d",jumlah);
			printf("\n\t ---------------------------------");
			printf("\n\t Kode dan Mata Kuliah [Kode:MK] : ");fflush(stdin);gets(mk);
			printf("\n\t Tanggal Deadline Tugas[DD-MM] : ");fflush(stdin);gets(deadline);
			temp=alokasi(mk,deadline);
			if(isEmpty(L)){
				insertFirst(&L,temp);
			}else{
				ceki=cek_10755(L,temp);
				if(ceki==1){
					insertFirst(&L,temp);
				}else{
					before=findNode(L,temp);
					if(before!=NULL){
						before=findNode(L,temp);
						insertAfter(before,temp);
					}else{
						insertLast(&L,temp);
					}
				}
				
			}
			jumlah++;
			break;
		
		case 2:
			if(isEmpty(L)){
				printf("\n\t [!] List kosong!");
				break;
			}
			printf("\n\tInput Tanggal Sekarang(DD-MM): ");fflush(stdin);gets(tanggal);
			printData(L,tanggal);
			break;
		case 3:
			if(isEmpty(L)){
				printf("\n\t [!] List kosong!");
				break;
			}
			before=findNode2_10755(L);
			printf("\n\t\tMata Kuliah\t: %s",before->mk);
			printf("\n\t\tDeadline Tugas\t:    %s",before->deadline);
			printf("\n\tApakah %s sudah selesai dikerjakan?[y/n]",before->mk);fflush(stdin);gets(opsi);
			if(strcmp(opsi,"y")==0){
				deleteAt(&L,before);
				jumlah--;
			}
			
			break;
			
		case 0:
			printf("\n\t Paulus Pandu Windito-E-200710755");
			break;
		default :
			printf("\n\t [!] Pilihan tersebut tidak valid");
			break;
	}
	getch();
	}while(menu!=0);
}