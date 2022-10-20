#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 100

typedef int infoType;
typedef int address;

typedef struct{
	address first;
	address last;
	infoType t[MAX];
}array;

int isEmpty(array a);
void createEmpty(array *a);
void add(array *a,infoType x);
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