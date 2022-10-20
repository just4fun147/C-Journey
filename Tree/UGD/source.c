#include "header.h"

void createEmpty(BinaryTree *BT){
	(*BT)=NULL;
}

bool isEmpty(BinaryTree BT){
	return (BT==NULL);
}

bool isLeaf(BinaryTree BT){
	return(isEmpty(BT->Left)&&isEmpty(BT->Right));
}

bool isSubTree(BinaryTree parent,BinaryTree child){
	return((child==parent->Left)||(child==parent->Right));
}

bool isSuperTree(BinaryTree child,BinaryTree parent){
	return(isSubTree(parent,child));	
}

bool isFound(BinaryTree BT,string nama){
	if(isEmpty(BT)){
		return false;
	}else{
		return(strcmpi(BT->nama,nama)==0||isFound(BT->Left,nama)||isFound(BT->Right,nama));
	}
}

int maksimum(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int height(BinaryTree BT){
	if(isEmpty(BT)){
		return (-1);
	}else if(isLeaf(BT)){
		return 0;
	}else{
		return(1+maksimum(height(BT->Left),height(BT->Right)));
	}
}


address addressOf(BinaryTree BT,string nama){
	if(isEmpty(BT)){
		return NULL;
	}else if(strcmp(BT->nama,nama)==0){
		return BT;
	}else{
		if(isFound(BT->Left,nama)){
			return(addressOf(BT->Left,nama));
		}else if(isFound(BT->Right,nama)){
			return(addressOf(BT->Right,nama));
		}else{
			return NULL;
		}
	}
}
void gantiJumlah(BinaryTree *BT,string nama,int jumlah){
	if(strcmp((*BT)->nama,nama)==0){
		(*BT)->jumlah=jumlah;
		printf("\nBerhasil Ubah Jumlah Menu!");
	}else{
		gantiJumlah(&(*BT)->Left,nama,jumlah);
		gantiJumlah(&(*BT)->Right,nama,jumlah);
	}
}

address alokasi(string nama,string jenis,int jumlah, float harga){
	address P=NULL;
	P=(Node*)malloc(sizeof(Node));
	
	if(P==NULL){
		return NULL;
	}else{
		strcpy(P->nama,nama);
		strcpy(P->jenis,jenis);
		P->harga=harga;
		P->jumlah=jumlah;
		P->Left=P->Right=NULL;
		return P;
	}
}

void insTreeBST(BinaryTree *BT,address P){

	if(isEmpty((*BT))){
		(*BT)=P;
		printf("\nBerhasil Tambah Menu!");
	}else{
		if(strcmp((*BT)->nama,P->nama)>0){
			insTreeBST(&(*BT)->Left,P);
		}else{
			insTreeBST(&(*BT)->Right,P);
		}
	}
}

void inOrder(BinaryTree BT){
	if(!isEmpty(BT)){
		inOrder(BT->Left);
		printf("\nNama : %s",BT->nama);
		printf("\nJenis : %s",BT->jenis);
		printf("\nHarga : %.0f",BT->harga);
		printf("\nJumlah : %d",BT->jumlah);
		printf("\n-------------------");
		inOrder(BT->Right);
		}
		
}
void deleteLeaf(address *P){
	address A=(*P);
	(*P)=NULL;
	free(A);
}
void deleteMenu(BinaryTree *BT,string nama){
	address A;
	if((*BT)!=NULL){
			if(strcmpi((*BT)->nama,nama)!=0){
			deleteMenu(&(*BT)->Left,nama);
			deleteMenu(&(*BT)->Right,nama);
		}else{
		
			if((*BT)->Right!=NULL){
				if((*BT)->Left!=NULL){
					(*BT)->Right->Left=(*BT)->Left;
				}
				A=(*BT);
				(*BT)=(*BT)->Right;
				free(A);
				
			}else{
				if((*BT)->Left!=NULL){
					A=(*BT);
					(*BT)->Left;
					free(A);
				}else{
					A=(*BT);
					(*BT)=NULL;
					free(A);
				}
				
			}
			
	
			printf("\nMenu Berhasil Dihapus!");
		}
	}
	
}