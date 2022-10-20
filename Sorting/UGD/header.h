#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 100

typedef int infoType;
typedef int address;
typedef char string[100];

typedef struct{
	address first;
	address last;
	infoType t[5];
	string nama[5],warna[5],ukuran[5];
	int lama[5];
}array;

int isEmpty(array a);
void createEmpty(array *a);
void add(array *a,string nama,string warna,string ukuran,int lama);
infoType getElementAt(array a,int i);
int lenght(array a);
void printInfo(array a);
void setArray(array *a,int n);
void swap(int *a,int *b);
void bubbleSort(array *a);
array clone(array a);
void breakIntoTwo(array *a,array *a2);
void merge(array *a,array b);
void mergeSort(array *a);
void quickSort(array *a,int first,int last);
void swapString(string *a,string *b);