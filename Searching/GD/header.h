#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

typedef int infoType;
typedef infoType keyType;
typedef infoType arrayType[N];

int isEmpty(arrayType a);
int isFull(arrayType a);
void createEmpty(arrayType a);
void swapElement(keyType *first,keyType *second);
void bubbleSort(arrayType a);
int binarySearch(arrayType a,int lef,int right,infoType find);
int sequentialSearch(arrayType a,infoType find);
void printArray(arrayType a);
void historyPencarian(arrayType a,infoType find);
int cekUnique(arrayType a,infoType input);
void copyArray(arrayType a,arrayType b);
