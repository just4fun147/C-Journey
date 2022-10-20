#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include <string.h>
//parent=cabang
//child=anggota
typedef char string[100];
typedef struct tChild* adrChild;
typedef struct tParent* adrParent;

typedef struct{
	string kodeCabang,negara;

}Cabang;

typedef struct{
	string nama,id;
}Anggota;

typedef struct tChild{
	Anggota anggota;
	adrChild nextChild;
}Child;

typedef struct tParent{
	Cabang cabang;
	adrParent nextParent;
	adrChild firstChild;
}Parent;

typedef struct{
	adrParent first;
}ListParent;

void creatEmpty(ListParent *L);
int isEmpty(ListParent L);
Cabang makeCabang(string kodeCabang,string negara);
int HaveChild(adrParent P);
adrParent AlokasiP(Cabang cabang);
adrParent FindParent(ListParent L,string negara);
adrParent FindParent(ListParent L,string kodeCabang);
void insertFirstParent(ListParent *L,Cabang databaru);
void insertLastParent(ListParent *L,Cabang databaru);
void insertAfterParent(ListParent *L,string datasebelum,Cabang databaru);
void deleteFirstParent(ListParent *L);
void deleteLastParent(ListParent *L);
void AfterParent(ListParent *L,string datasebelum);
void printAll(ListParent L);
void printCabang(ListParent L,string negara);
void bubarCabang(ListParent L,string kodeCabang);

Anggota makeAnggota(string id,string nama);
adrChild AlokasiC(Anggota anggota);
void printChild(adrChild C);
void insertFirstChild(ListParent *L,string kodeCabang,Anggota anggotabaru);
void insertLastChild(ListParent *L,string kodeCabang,Anggota anggotabaru);
void deleteFirstChild(ListParent *L,string kodeCabang);
void deletLastChild(ListParent *L,string kodeCabang);
void printChildByParent(ListParent L,string name);
void printAnggota(ListParent L,string id);
void deleteCabang(ListParent *L,string kodeCabang);

adrParent cekKode(ListParent L,string kode1);
void transfer(ListParent *L,adrParent cek1,adrParent cek2);
void insertFirstChildt(ListParent *L,string kodeCabang,Anggota anggotabaru);
void deleteFirstChildt(ListParent *L,string kodeCabang);