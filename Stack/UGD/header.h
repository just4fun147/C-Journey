#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_stack 5
typedef char string[100];


typedef struct{
	string nama,simbol;
	int id;
	int slotSkill;
}Kartu;

typedef struct{
	int top;
	Kartu k[max_stack];
}Stack;

typedef struct{
	Stack s[3];
	int top;
}Inventory;

void init(Inventory *inven);
void push(Inventory *inven,Kartu k,int g);
Kartu pop(Inventory *inven,int g);
void show(Inventory inven);
void delete(Inventory *inven);
int gacha();
int isFull(Inventory inven,int g);
int isEmpty(Inventory inven,int g);
Kartu inputKartu(string nama, int id,int g);
int cekNama(string nama);
void showSebagian(Inventory inven, int g);
void printKartu(Inventory inven,int g);
int isEmpty1(Inventory inven);
int cek(string nama,Inventory inven);
int cekI(string nama,Inventory inven);
int cekJ(string nama,Inventory inven);
Kartu popSatu(Inventory *inven, int i,int j);
void printKartu1(Inventory inven,int i,int j);