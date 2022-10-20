#include "header.h"

void createEmpty(List *L){
	(*L).first = NULL;
}


bool isEmpty(List L){
	return L.first == NULL;
}

bool isOneElement(List L){
	return !isEmpty(L) && L.first->next == NULL;
}

address alokasi(string mk,string deadline){
	address P;
	string kode,a,m,k,n,o;
	strcpy(a,"    ");
	strcpy(k,"   ");
	strncpy(kode,mk,3);
	strncpy(mk,a,4);
	strcpy(m,deadline);
	strncpy(n,m,2);//tanggal
	strncpy(m,k,3);
	
		
		
	
	P = (node*) malloc(sizeof(node));
	P->kode=atoi(kode);
	strcpy(P->mk,mk);
	strcpy(P->deadline,deadline);
	P->tanggal=atoi(n);//deadline tanggal
	P->bulan=atoi(m);//deadline bulan
	P->next = NULL;
	return P;
}

void insertFirst(List *L,address newNode){
	newNode->next=(*L).first;
	(*L).first=newNode;
}

void insertAfter(address before,address newNode){
	
	if(before!=NULL){
		newNode->next = before->next;
		before->next = newNode;
	}
}

void insertLast(List *L,address newNode){
	address P;
	if(isEmpty((*L))){
		insertFirst(&(*L),newNode);
	}else{
		for(P = (*L).first; P->next != NULL; P = P->next);
		P->next = newNode;
	}
}

void deleteFirst(List *L){
	if(!isEmpty((*L))){
		address del = (*L).first;
		(*L).first = (*L).first->next;
		free(del);
	}
}

void deleteAt(List *L,address del){
	address P;
	
	if(!isEmpty((*L))){
		if((*L).first == del){
			deleteFirst(L);
		}else{
			P = (*L).first;
			while(P->next != del){
				P = P->next;
			}
			P->next = del->next;
			free(del);
		}
	}
}

void deleteLast(List *L){
	address P;
	if(!isEmpty((*L))){
		if(isOneElement((*L))){
			deleteFirst(L);
		}else{
			for(P = (*L).first; P->next->next != NULL; P = P->next);
			free(P->next);
			P->next = NULL;
		}
	}
}

void printData(List L,string tanggal){
	address P;
	int a,z,x,k,l,deadline,hari,bulan;
	string b,c,m,n,o;
	strcpy(c,"   ");
	strncpy(b,tanggal,2);//tanggal sekarang
	strncpy(tanggal,c,3);//bulan sekarang
	z=atoi(tanggal);//sekarang bulan
	x=atoi(b);//sekarang tanggal
	
	printf("\n\t");
	for(P = L.first; P != NULL; P = P->next){
		a++;
		bulan=(P->bulan-z)*30;
		hari=P->tanggal-x;
		deadline=bulan+hari;
	
		

		
		printf("\n\tMata Kuliah ke-%d",a);
		printf("\n\t\tKode\t\t:    %d",P->kode);
		printf("\n\t\tMata Kuliah\t:%s",P->mk);
		printf("\n\t\tDeadline Tugas\t:    %s",P->deadline);
		printf("\n\t\tWaktu Tersisa\t:     %d hari",deadline);
	}
	
}


address findNode(List L,address temp){
	address P;
	
	P=L.first;

	while(P->next!=NULL){
		if(P->next->kode>temp->kode){
			return P;
		}
		P=P->next;
	}

	return NULL;
}
address findNode2_10755(List L){
	address P,temp;
	int bulan,hari,deadline,awal;
	P=L.first;
	awal=P->bulan*30+P->tanggal;
	temp=L.first;
	while(P!=NULL){
		bulan=P->bulan*30;
		hari=P->tanggal;
		deadline=bulan+hari;
			if(deadline<awal){
				awal=deadline;
				temp=P;
			}
			P=P->next;
	}
	
	return temp;
}


int cek_10755(List L,address temp){
	address P;
	P=L.first;
	if(P->next==NULL){
		if(P->kode>temp->kode){
			return 1;
		}
		return 0;
	}
}
