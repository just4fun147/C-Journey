#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10
#define M 5
typedef char string[100];
typedef int infoType;
typedef infoType keyType;
typedef infoType arrayType[N];

typedef struct{
	string nama[M],npm[M];
}Mahasiswa;

int isEmpty(arrayType a);
int isFull(arrayType a);
void createEmpty(arrayType a);
void initMaha(Mahasiswa maha);
void bubbleSort(Mahasiswa *maha);
void swapElement(Mahasiswa *maha,int i,int j);
int binarySearch(Mahasiswa maha,int left,int right,string npm);
int sequentialSearch(arrayType a,infoType find);
void printArray(arrayType a);
void historyPencarian(arrayType a,infoType find);
int cekUnique(arrayType a,infoType input);
void copyArray(arrayType a,arrayType b);
void insertRandom(arrayType a);
int cekNama(Mahasiswa maha,string nama);
int cekNpm(Mahasiswa maha,string npm);
void printMahasiswa(Mahasiswa maha);
int cek(Mahasiswa maha,string npm);
void cariProdi(string npm);
