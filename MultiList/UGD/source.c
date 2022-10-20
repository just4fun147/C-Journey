#include "header.h"
//parent=cabang
//child=anggota
Cabang makeCabang(string kodeCabang,string negara){
	Cabang cabang;
	
	strcpy(cabang.kodeCabang,kodeCabang);
	strcpy(cabang.negara,negara);

	return cabang;
}
Anggota makeAnggota(string id,string nama){
	Anggota anggota;
	
	strcpy(anggota.id,id);
	strcpy(anggota.nama,nama);

	return anggota;
}

void createEmpty(ListParent *L){
	(*L).first=NULL;
}

int isEmpty(ListParent L){
	if(L.first==NULL){
		return 1;
	}else{
		return 0;
	}
}

int HaveChild(adrParent P){
	if(P->firstChild!=NULL){
		return 1;
	}else{
		return 0;
	}
}

adrParent AlokasiP(Cabang cabang){
	adrParent P;
	P=(adrParent)malloc(sizeof(Parent));
	P->cabang=cabang;
	P->firstChild=NULL;
	P->nextParent=NULL;
	return P;
}

adrParent FindParent(ListParent L, string negara){
	adrParent P=L.first;
	while(P!=NULL){
		if(strcmpi(P->cabang.negara,negara)!=0){
			P=P->nextParent;
		}else{
			return P;
		}
	}
	return P;
}
adrParent FindParent2(ListParent L, string kodeCabang){
	adrParent P=L.first;
	while(P!=NULL){
		if(strcmpi(P->cabang.kodeCabang,kodeCabang)!=0){
			P=P->nextParent;
		}else{
			return P;
		}
	}
	return P;
}

void printCabang(ListParent L,string negara){
	adrParent P;
	if(isEmpty(L)){
		printf("\nList Kosong");
	}else{
		P=L.first;
		while(P!=NULL){
			if(strcmp(P->cabang.negara,negara)==0){
				printf("\n\nKode cabang : %s",P->cabang.kodeCabang);
				printf("\nNegara : %s",P->cabang.negara);
			}
			P=P->nextParent;
		}
	}
}
void insertFirstParent(ListParent *L,Cabang databaru){
	adrParent P;
	P=AlokasiP(databaru);
	P->nextParent=(*L).first;
	(*L).first=P;
	printf("\nBERHASIL INSERT CABANG [first insert]");
}

void insertLastParent(ListParent *L,Cabang databaru){
	adrParent P,last;
	if(isEmpty(*L)){
		insertFirstParent(&(*L),databaru);
	}else{
		P=AlokasiP(databaru);
		last=(*L).first;
		while(last->nextParent!=NULL){
			last=last->nextParent;
		}
		last->nextParent=P;
		printf("\nBERHASIL INSERT CABANG [last insert]");
	}
}

void insertAfterParent(ListParent *L,string datasebelum,Cabang databaru){
	adrParent P,cari;
	cari=FindParent((*L),datasebelum);
	if(isEmpty(*L)){
		insertFirstParent(&(*L),databaru);
	}else if(cari==NULL){
		printf("Data tidak ditemukan");
	}else{
		P=AlokasiP(databaru);
		P->nextParent=cari->nextParent;
		cari->nextParent=P;
		printf("INSERTED");
	}
}

void deleteFirstParent(ListParent *L){
	adrParent del;
	if(isEmpty(*L)){
		printf("List Kosong");
	}else{
		del=(*L).first;
		(*L).first=(*L).first->nextParent;
		free(del);
		printf("DELETED CABANG PERTAMA");
	}
}

void deleteLastParent(ListParent *L){
	adrParent bantu,del;
	if(isEmpty(*L)){
		printf("List Kosong");
	}else{
		if((*L).first->nextParent==NULL){
			deleteFirstParent(&(*L));
		}else{
			bantu=(*L).first;
			while(bantu->nextParent->nextParent!=NULL){
				bantu=bantu->nextParent;
			}
			del=bantu->nextParent;
			bantu->nextParent=NULL;
			free(del);
			printf("DELETED CABANG TERAKHIR");
		}
	}
}

void deleteAfterParent(ListParent *L,string datasebelum){
	adrParent del,cari;
	cari=FindParent((*L),datasebelum);
	if(cari==NULL){
		printf("Data tidak ditemukan");
	}else{
		if(cari->nextParent==NULL){
			printf("Data sebelum terletak di akhir list");
		}else{
			del=cari->nextParent;
			cari->nextParent=cari->nextParent->nextParent;
			free(del);
			printf("DELETED");
		}
	}
}


adrChild AlokasiC(Anggota anggota){
	adrChild C;
	C=(adrChild)malloc(sizeof(Child));
	C->anggota=anggota;
	C->nextChild=NULL;
	return C;
}

void insertFirstChild(ListParent *L,string kodeCabang,Anggota anggotabaru){
	adrChild C;
	adrParent P;
	P=FindParent2((*L),kodeCabang);
	if(P==NULL){
		printf("Cabang tidak ada");
	}else{
		C=AlokasiC(anggotabaru);
		C->nextChild=P->firstChild;
		P->firstChild=C;
		printf("\nBERHASIL INSERT ANGGOTA %s KE CABANG %s",anggotabaru.nama,kodeCabang);
	}
	
}

void insertLastChild(ListParent *L,string kodeCabang,Anggota anggotabaru){
	adrChild C,lastChild;
	adrParent P;
	P=FindParent2((*L),kodeCabang);
	if(P==NULL){
		printf("Cabang tidak ada");
	}else if(!HaveChild(P)){
		insertFirstChild(&(*L),kodeCabang,anggotabaru);
	}else{
		C=AlokasiC(anggotabaru);
		lastChild=P->firstChild;
		while(lastChild->nextChild!=NULL){
			lastChild=lastChild->nextChild;
		}
		lastChild->nextChild=C;
		printf("\nBERHASIL INSERT ANGGOTA %s KE CABANG %s",anggotabaru.nama,kodeCabang);
	}
}

void deleteFirstChild(ListParent *L,string kodeCabang){
	adrChild del;
	adrParent P;
	P=FindParent2((*L),kodeCabang);
	if(P==NULL){
		printf("Parent tidak ada");
	}else if(!HaveChild(P)){
		printf("\nTidak ada anggota di cabang ini");
	}else{
		del=P->firstChild;
		P->firstChild=P->firstChild->nextChild;
		free(del);
		printf("DELETED FROM %s",kodeCabang);
	}
}

void deleteLastChild(ListParent *L,string kodeCabang){
	adrChild del,bantu;
	adrParent P,temp;
	P=FindParent2((*L),kodeCabang);
	if(P==NULL){
		printf("Parent tidak ada");
	}else if(!HaveChild(P)){
		printf("\nTidak ada anggota di cabang ini");
	}else if(P->firstChild->nextChild==NULL){
		deleteFirstChild(&(*L),kodeCabang);
	}else{
		bantu=P->firstChild;
		while(bantu->nextChild->nextChild!=NULL){
			bantu=bantu->nextChild;
		}
		del=bantu->nextChild;
		bantu->nextChild=NULL;
		free(del);
		printf("DELETED FROM %s",kodeCabang);
	}
}


void printAll(ListParent L){
	adrParent P;
	adrChild C;
	if(isEmpty(L)){
		printf("\nList Kosong");
	}else{
		P=L.first;
		while(P!=NULL){
			printf("\nKode cabang : %s",P->cabang.kodeCabang);
			printf("\nNegara : %s",P->cabang.negara);
			if(HaveChild(P)){
				C=P->firstChild;
				printChild(C);
			}else{
				printf("\n\tBELUM ADA ANGGOTA");
			}
			P=P->nextParent;
		}
	}
}

void printChild(adrChild C){
	if(C!=NULL){
		while(C!=NULL){
			printf("\n\t- %s,%s",C->anggota.id,C->anggota.nama);
			C=C->nextChild;
		}
	}
}

void bubarCabang(ListParent L,string kodeCabang){
	adrParent cari;
	if(isEmpty(L)){
		printf("List Kosong");
	}else{
		cari=FindParent2(L,kodeCabang);
		if(cari!=NULL){
			free(cari);
		}else{
			printf("\nTIDAK ADA CABANG SEPERTI ITU");
		}
	}
}
void printAnggota(ListParent L,string id){
	adrParent P;
	adrChild C;
	if(isEmpty(L)){
		printf("\nList Kosong");
	}else{
		P=L.first;
		while(P!=NULL){
			if(HaveChild(P)){
				C=P->firstChild;
				while(C!=NULL){
					if(strcmp(C->anggota.id,id)==0){
						printf("\n---------");
						printf("\nid agen : %s",C->anggota.id);
						printf("\nama agen : %s",C->anggota.nama);
						printf("\nnegara : %s",P->cabang.negara);
						break;
					}
				}
			}
			P=P->nextParent;
		}
	}
}
void deleteCabang(ListParent *L,string kodeCabang){
	adrParent P,del,cari;
	cari=FindParent2((*L),kodeCabang);
	if(cari==NULL){
		
	}else if(cari==(*L).first){
		del=(*L).first;
		(*L).first=(*L).first->nextParent;
		free(del);
		
	}else{
		P=(*L).first;
		while(P!=NULL){
			if(strcmp(P->nextParent->cabang.kodeCabang,kodeCabang)==0){
				del=P->nextParent;
				P->nextParent=P->nextParent->nextParent;
				free(del);
				break;
			}
			P=P->nextParent;
		}
	}
	
		

}

adrParent cekKode(ListParent L,string kode){
	adrParent P;
	int i=0,j=0;
	P=L.first;
	while(P!=NULL){
		if(strcmp(P->cabang.kodeCabang,kode)==0){
			return P;	
		}
		P=P->nextParent;
	}
	return P;
}

void transfer(ListParent *L,adrParent cek1,adrParent cek2){
	adrChild del,bantu,tambah;
	adrParent P,Z;
	Anggota A;
	string kode1,kode2;
	P=(*L).first;
	Z=(*L).first;
	while(P!=cek1){
		P=P->nextParent;
	}
	bantu=P->firstChild;
	while(bantu->nextChild!=NULL){
		bantu=bantu->nextChild;
	}
	while(Z!=cek2){
		Z=Z->nextParent;
	}
	strcpy(kode2,Z->cabang.kodeCabang);
	strcpy(A.id,bantu->anggota.id);
	strcpy(A.nama,bantu->anggota.nama);
	strcpy(kode1,P->cabang.kodeCabang);
	insertLastChildt(&(*L),kode2,A);
	deleteLastChildt(&(*L),kode1);
	printf("\nBERHASIL PINDAH");
}



void insertLastChildt(ListParent *L,string kodeCabang,Anggota anggotabaru){
	adrChild C,lastChild;
	adrParent P;
	P=FindParent2((*L),kodeCabang);
	if(P==NULL){
		printf("Cabang tidak ada");
	}else if(!HaveChild(P)){
		insertFirstChildt(&(*L),kodeCabang,anggotabaru);
	}else{
		C=AlokasiC(anggotabaru);
		lastChild=P->firstChild;
		while(lastChild->nextChild!=NULL){
			lastChild=lastChild->nextChild;
		}
		lastChild->nextChild=C;
	}
}		
	
void deleteLastChildt(ListParent *L,string kodeCabang){
	adrChild del,bantu;
	adrParent P,temp;
	P=FindParent2((*L),kodeCabang);
	if(P==NULL){
		printf("Parent tidak ada");
	}else if(!HaveChild(P)){
		printf("\nTidak ada anggota di cabang ini");
	}else if(P->firstChild->nextChild==NULL){
		deleteFirstChildt(&(*L),kodeCabang);
	}else{
		bantu=P->firstChild;
		while(bantu->nextChild->nextChild!=NULL){
			bantu=bantu->nextChild;
		}
		del=bantu->nextChild;
		bantu->nextChild=NULL;
		free(del);
		
	}
}	

void insertFirstChildt(ListParent *L,string kodeCabang,Anggota anggotabaru){
	adrChild C;
	adrParent P;
	P=FindParent2((*L),kodeCabang);
	if(P==NULL){
		printf("Cabang tidak ada");
	}else{
		C=AlokasiC(anggotabaru);
		C->nextChild=P->firstChild;
		P->firstChild=C;
	}
	
}


void deleteFirstChildt(ListParent *L,string kodeCabang){
	adrChild del;
	adrParent P;
	P=FindParent2((*L),kodeCabang);
	if(P==NULL){
		printf("Parent tidak ada");
	}else if(!HaveChild(P)){
		printf("\nTidak ada anggota di cabang ini");
	}else{
		del=P->firstChild;
		P->firstChild=P->firstChild->nextChild;
		free(del);
	}
}
	