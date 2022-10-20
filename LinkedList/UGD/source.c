#include "header.h"

void createEmpty(List *L){
	(*L).first=NULL;
}

Data makeData(string npm,string nama,string gender,string peran,float nilai){
	Data temp;
	
	strcpy(temp.npm,npm);
	strcpy(temp.nama,nama);
	strcpy(temp.gender,gender);
	strcpy(temp.peran,peran);
	temp.nilai=nilai;
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
	printf("\n[!] Anggota Berhasil Dimasukan [!]");
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
		printf("\n[!] Anggota Berasil Dimasukan [!]");
	}
}

void deleteFirst(List *L){
	address P;
	
	if(isEmpty(*L)){
		printf("\n[!] Kelompok Masih Kosong [!]\n");
	}else{
		P=(*L).first;
		(*L).first=(*L).first->next;
		printf("\n[!] Anggota %s Berhasil dihapus [!]",P->D.nama);
		dealokasiData(P);
		
		
	}
}

void deleteLast(List *L){
	address P,last;
	if(isEmpty(*L)){
		printf("\n[!] Kelompok Masih Kosong [!]\n");
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
			printf("\n[!] Anggota %s Berhasil dihapus [!]",last->D.nama);
		}
	}
}
void showList(List L){
	address P;
	int i=0;
	float rerata=0;
	if(isEmpty(L)){
		printf("\n[!] Kelompok Masih Kosong [!]\n");
	}else{
		P=L.first;
		while(P!=NULL){
			printf("\n--- DAFTAR ANGGOTA ---");
			printf("\nNama\t: %s",P->D.nama);
			printf("\nNPM\t: %s",P->D.npm);
			printf("\nGender\t: %s",P->D.gender);
			printf("\nPeran\t: %s",P->D.peran);
			printf("\nNilai\t: %.2f",P->D.nilai);
			i++;
			rerata=rerata+P->D.nilai;
			P=P->next;
		}
		printf("\n-----------------");
		printf("\nJumlah Anggota : %d",i);
		printf("\n-----------------");
		printf("\nRerata nilai : %.2f",rerata/i);
	}
}

int cekGender(string gender){
	if(strcmpi(gender,"L")==0){
		return 1;
	}
	if(strcmpi(gender,"P")==0){
		return 2;
	}
	return 3;
}

int cekNpm(string npm,List L){
	address P;
	P=L.first;
	if(isEmpty(L)){
		return 1;
	}else{
		while(P!=NULL){
			if(strcmpi(P->D.npm,npm)==0){
				return -1;
			}
			P=P->next;
		}
	}
	return 1;
}
void deleteGender(List *L,string gender){
	address P;
	P=(*L).first;
	while(P->next->next!=NULL){
		

	}
	
}
int cekPeran(string peran){
	if(strcmpi(peran,"ketua")==0){
		return 1;	
	}
	if(strcmpi(peran,"anggota")==0){
		return 2;
	}
	return 3;
}

void deleteFirst2(List *L){
	address P;
	
	if(isEmpty(*L)){
		printf("\n[!] Kelompok Masih Kosong [!]\n");
	}else{
		P=(*L).first;
		(*L).first=(*L).first->next;
		dealokasiData(P);
		
		
	}
}
void insertFirst2(List *L,Data D){
	address P;
	
	P=alokasiData(D);
	P->next=(*L).first;
	(*L).first=P;

}
