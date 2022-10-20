#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char string[100];

typedef struct{
	int npm;
	string nama;
}Data;

typedef struct Node *address;

typedef struct Node{
	Data D;
	address next;
}tNode;

typedef struct{
	address first;
}List;

void createEmpty(List *L);
Data makeData(int npm,string nama);
bool isEmpty(List L);
address alokasiData(Data D);
void dealokasiData(address P);
void insertFirst(List *L,Data D);
void insertLast(List *L,Data D);
void deleteFirst(List *L);
void deleteLast(List *L);
void showList(List L);