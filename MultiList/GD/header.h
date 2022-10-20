#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include <string.h>

typedef char string[100];
typedef struct tChild* adrChild;
typedef struct tParent* adrParent;

typedef struct{
	string name;
	int age;
}Person;

typedef struct tChild{
	int id;
	adrChild nextChild;
}Child;

typedef struct tParent{
	Person person;
	adrParent nextParent;
	adrChild firstChild;
}Parent;

typedef struct{
	int index;
	int NIM;
}DataMhs;

typedef struct{
	int index;
	int tahun;
	address DataMhs;
}IndexTahun;
typedef struct{
	adrParent first;
}ListParent;

void creatEmpty(ListParent *L);
int isEmpty(ListParent L);
Person makePerson(string name, int age);
int HaveChild(adrParent P);
adrParent AlokasiP(Person person);
adrParent FindParent(ListParent L,string name);
void insertFirstParent(ListParent *L,Person databaru);
void insertLastParent(ListParent *L,Person databaru);
void insertAfterParent(ListParent *L,string datasebelum,Person databaru);
void deleteFirstParent(ListParent *L);
void deleteLastParent(ListParent *L);
void AfterParent(ListParent *L,string datasebelum);
void printAll(ListParent L);

adrChild AlokasiC(char id);
void printChild(adrChild C);
void insertFirstChild(ListParent *L,string name,char idC);
void insertLastChild(ListParent *L,string name,char idC);
void deleteFirstChild(ListParent *L,string name);
void deletLastChild(ListParent *L,string name);
void printChildByParent(ListParent L,string name);