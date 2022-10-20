#include "header.h"



int main(int argc, char *argv[]) {
	int indexI,indexJ,pil,i,n;
	Matriks myMatriks;
	int id,tahunTerbit;
	string judul,namaPenulis;
	Buku b;
	
	do{
		system("cls");
		printf("1. Init Data Buku");
		printf("\n2. Isi Data Buku");
		printf("\n3. Print Matriks Buku");
		printf("\nInput: ");scanf("%d",&pil);
		switch(pil){
			case 1:
				init(&myMatriks);
				break;
			case 2:
				printf("\nJumlah buku yang akan dimasukan: ");scanf("%d",&n);
				
				for(i=0;i<n;i++){
					printf("\n\t\t[Buku %d]\n",i+1);
					printf("\nID : ");scanf("%d",&id);
					printf("\nJudul Buku : ");fflush(stdin);gets(judul);
					printf("\nTahun Terbit : ");scanf("%d",&tahunTerbit);
					printf("\nNama Penulis : ");fflush(stdin);gets(namaPenulis);
					printf("\nPosisi Data Buku Pada Matriks");
					printf("\nIndex I : ");scanf("%d",&indexI);
					printf("\nIndex J : ");scanf("%d",&indexJ);
					
					b=makeBuku(id,judul,tahunTerbit,namaPenulis);
					myMatriks[indexI][indexJ]=b;
				}
				break;
			case 3:
				printMatriks(myMatriks);
				break;
		}
		getch();
	}while(pil!=0);
	return 0;
}