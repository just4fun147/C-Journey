#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 5

typedef char string[50];

void initNama(string nama[],int index);
int cekKosong(string nama[],int index);
int cekSisa(string nama[],int index,int sisa);
void inputNama(string nama[],int jumlahInput);
void tampilNama(string nama[],int index);