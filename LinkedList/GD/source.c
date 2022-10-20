#include "header.h"

void createEmpty(List *L){
	(*L).first=NULL;
}

Data makeData(int npm,string nama){
	Data temp;
	temp.npm=npm;
	strcpy(temp.nama,nama);
	return temp;
}

bool isEmpty(List L){
	return L.first==NULL;
}

address alokasiData(Data D){
	address P;
	P= (tNode *)malloc(sizeof(tNode));
	P->D =D;
	P->next=NULL;
	return P;
}

void dealokasiData(address P){
	free(P);
}
void insertFirst(List *L,Data D){
	address P;
	
	P=alokasiData(D);
	P->next=(*L).first;
	(*L).first=P;
	printf("\n[!] Inserted [!]");
}

void insertLast(List *L,Data D){
	address P,last;
	
	if(isEmpty(*L)){
		insertFirst(&(*L),D);
	}else{
		P=alokasiData(D);
		last=(*L).first;
		while(last->next != NULL){
			last=last->next;
		}
		last->next=P;
		printf("\n[!] Inserted [!]");
	}
}

void deleteFirst(List *L){
	address P;
	
	if(isEmpty(*L)){
		printf("\n[!] List Kosong [!]\n");
	}else{
		P=(*L).first;
		(*L).first=(*L).first->next;
		
		dealokasiData(P);
		
		printf("\n[!] Deleted [!]");
	}
}

void deleteLast(List *L){
	address P,last;
	if(isEmpty(*L)){
		printf("\n[!] List Kosong [!]\n");
	}else{
		if((*L).first->next==NULL){
			deleteFirst(&(*L));
		}else{
			P=(*L).first;
			while(P->next->next!=NULL){
				P=P->next;
			}
			last=P->next;
			P->next=NULL;
			dealokasiData(last);
			printf("\n[!] Deleted [!]");
		}
	}
}
void showList(List L){
	address P;
	if(isEmpty(L)){
		printf("\n[!] List Kosong [!]\n");
	}else{
		P=L.first;
		while(P!=NULL){
			printf("\n%d - %s",P->D.npm,P->D.nama);
			P=P->next;
		}
	}
}