#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define X 3
#define Y 3

typedef char string [20];

typedef struct{
	int id,tahunTerbit;
	string judul,namaPenulis;
}Buku;

typedef Buku Matriks[3][3];

Buku makeBuku(int id, string judul,int tahunTerbit, string namaPenulis);
void init(Matriks *M);
void printMatriks(Matriks M);
void cariMatriks(Matriks M);