#include "header.h"

Buku makeBuku(int id,string judul,int tahunTerbit,string namaPenulis){
	Buku b;
	
	b.id=id;
	strcpy(b.judul,judul);
	b.tahunTerbit=tahunTerbit;
	strcpy(b.namaPenulis,namaPenulis);
	
	return b;
}

void init(Matriks *M){
	int i,j;
	
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			(*M)[i][j]=makeBuku(0,"-",0,"-");
		}
	}
}

void printMatriks(Matriks M){
	int i,j;
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			printf("[%s | %s]\t\t",M[i][j].judul,M[i][j].namaPenulis);
		}
		printf("\n\n");
	}
}

