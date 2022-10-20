#include "header.h"

void createEmpty(List *L){
	(*L)=NULL;
}

int isOneElm(List L){
	return L->next==NULL;
}

int isEmpty(List L){
	return L==NULL;
}

addr findNode(List L,int resi){
	if(isEmpty(L)){
		return NULL;
	}else{
		if(L->resi!=resi){
			return findNode(L->next,resi);
		}
		return L;
	}
}

addr alokasi(int resi,int berat,string nama,string tujuan,string jenis){
	addr N=(Node*)malloc(sizeof(Node));
	
	N->next=NULL;
	N->resi=resi;
	N->berat=berat;
	strcpy(N->nama,nama);
	strcpy(N->tujuan,tujuan);
	strcpy(N->status,"Belum Sampai");
	strcpy(N->bayar,"Belum Bayar");
	strcpy(N->jenis,jenis);
	if(strcmpi(jenis,"express")==0){
		N->harga=100000;
	}else if(strcmpi(jenis,"regular")==0){
		N->harga=50000;
	}else{
		N->harga=10000;
	}
	return N;
}

void insertFirst(List *L,addr newNode){
	newNode->next=(*L);
	(*L)=newNode;
	printf("Berhasil Input Data");
}

void insertLast(List *L,addr newNode){
	if(isEmpty(*L)){
		insertFirst(L,newNode);
	}else{
		insertLast(&(*L)->next,newNode);
	}
}

void deleteFirst(List *L){
	addr del=(*L);
	
	(*L)=(*L)->next;
	free(del);
}

void deleteAt(List *L,addr delNode){
	if((*L)!=delNode){
		deleteAt(&(*L)->next,delNode);
	}else{
		deleteFirst(L);
		printf("Berhasil Hapus Paket");
	}
}

void deleteLast(List *L){
	if(!isOneElm(*L)){
		deleteLast(&(*L)->next);
	}else{
		deleteFirst(L);
	}
}

void printAll(List L){
	if(!isEmpty(L)){
		printf("\n\nNo Resi: %d",L->resi);
		printf("\nBerat: %d",L->berat);
		printf("\nNama Barang: %s",L->nama);
		printf("\nKota Tujuan: %s",L->tujuan);
		printf("\nStatus Paket: %s",L->status);
		printf("\nStatus Bayar: %s",L->bayar);
		printf("\nJenis: %s",L->jenis);
		printAll(L->next);
	}
}

void pembayaran(List *L,int resi){
	if(!isEmpty((*L))){
		if((*L)->resi==resi){
			strcpy((*L)->bayar,"Sudah Dibayar");
			printf("\nBerhasil Ubah Status Paket");
		}else{
			pembayaran(&(*L)->next,resi);
		}
	}
}
void ubahStatus(List *L,int resi){
		if(!isEmpty((*L))){
		if((*L)->resi==resi){
			strcpy((*L)->status,"Sudah Sampai");
			printf("\nBerhasil Ubah Status Paket");
		}else{
			pembayaran(&(*L)->next,resi);
		}
	}
}