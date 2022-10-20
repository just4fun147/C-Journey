#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char string[100];

typedef struct{
	float nilai;
	string npm,nama,peran,gender;
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
Data makeData(string npm,string nama,string gender,string peran,float nilai);
bool isEmpty(List L);
address alokasiData(Data D);
void dealokasiData(address P);
void insertFirst(List *L,Data D);
void insertLast(List *L,Data D);
void deleteFirst(List *L);
void deleteLast(List *L);
void showList(List L);
int cekGender(string gender);
int cekNpm(string npm,List L);
void deleteGender(List *L,string gender);
int cekPeran(string peran);
void deleteFirst2(List *L);
void insertFirst2(List *L,Data D);