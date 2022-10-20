#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef char string[100];

typedef struct node *address;

typedef struct node{
	string mk,deadline;
	int kode,tanggal,bulan;
	address next;
}node;

typedef struct{
	address first;
}List;

void createEmpty(List *L);
bool isEmpty(List L);
bool isOneElement(List L);
address alokasi(string mk,string deadline);
void insertFirst(List *L,address newNode);
void insertAfter(address before,address newNode);
void insertLast(List *L,address newNode);
void deleteFirst(List *L);
void deleteAt(List *L,address del);
void deleteLast(List *L);
void printData(List L,string tanggal);
address findNode(List L,address temp);

address findNode2_10755(List L);

int cek_10755(List L,address temp);


