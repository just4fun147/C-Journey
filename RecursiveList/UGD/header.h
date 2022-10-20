#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char string[100];
typedef struct node *addr;
typedef struct node *List;

typedef struct node{
	int resi,berat,harga;
	string nama,tujuan,status,bayar,jenis;
	addr next;
}Node;

void createEmpty(List *L);
int isOneElm(List L);
int isEmpty(List L);
addr findNode(List L,int resi);
addr alokasi(int resi,int berat,string nama,string tujuan,string jenis);
void insertFirst(List *L,addr newNode);
void insertLast(List *L,addr newNode);
void deleteFirst(List *L);
void deleteAt(List *L,addr delNode);
void deleteLast(List *L);
void printAll(List L);
void pembayaran(List *L,int resi);
void ubahStatus(List *L,int resi);