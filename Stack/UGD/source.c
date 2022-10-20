#include "header.h"


void init(Inventory *inven){
	(*inven).s[0].top = -1;
	(*inven).s[1].top = -1;
	(*inven).s[2].top = -1;
	(*inven).top=-1;
}

void push(Inventory *inven, Kartu k,int g){
	(*inven).s[g].top++;
	(*inven).s[g].k[(*inven).s[g].top] = k;
	(*inven).top++;
}

Kartu pop(Inventory *inven,int g){
	Kartu temp;
	
	temp = (*inven).s[g].k[(*inven).s[g].top];
	(*inven).s[g].top--;
}

int gacha(){
	int i= rand()%3;
	return i;
}

char simbol(int g){
	
}
int isFull(Inventory inven,int g){
	return inven.s[g].top == max_stack - 1;
}

int isEmpty(Inventory inven, int g){
	return inven.s[g].top == -1;
}

Kartu inputKartu(string nama,int id,int g){
	Kartu a;
	strcpy(a.nama,nama);
	a.id=id;
	if(g==0){
		a.slotSkill=0;
		strcpy(a.simbol,"*");
	}
	if(g==1){
		a.slotSkill=1;
		strcpy(a.simbol,"**");
	}
	if(g==2){
		a.slotSkill=2;
		strcpy(a.simbol,"***");
	}

	
	return a;
}

void show(Inventory inven){
	int i,j;
	printf("\n\tInventory");
	for(i=0;i<3;i++){
		for(j=0;j<=inven.s[i].top;j++){
		printf("\n[%d] (%s) - %s -%d Skill",inven.s[i].k[j].id,inven.s[i].k[j].simbol,inven.s[i].k[j].nama,inven.s[i].k[j].slotSkill);
		}
	}
}

int cekNama(string nama){
	if(strcmpi(nama,"Common")==0){
		return 0;
	}
	if(strcmpi(nama,"Uncommon")==0){
		return 1;
	}
	if(strcmpi(nama,"Rare")==0){
		return 2;
	}
	return 3;
}

void showSebagian(Inventory inven, int g){
	int i;
	for(i=inven.s[g].top;i>=0;i--){
		printf("\n[%d] (%s) - %s -%d Skill",inven.s[g].k[i].id,inven.s[g].k[i].simbol,inven.s[g].k[i].nama,inven.s[g].k[i].slotSkill);
	}
}


void printKartu(Inventory inven,int g){
	printf("\nKartu [%d] - %s - %d Skill Berhasil di Hapus [!]",inven.s[g].k[inven.s[g].top].id,inven.s[g].k[inven.s[g].top].nama,inven.s[g].k[inven.s[g].top].slotSkill);
}

int isEmpty1(Inventory inven){
	return inven.top == -1;
}

int cekI(string nama,Inventory inven){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<max_stack;j++){
			if(strcmp(nama,inven.s[i].k[j].nama)==0){
				return i;
			}
		}
	}
}

int cekJ(string nama,Inventory inven){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<max_stack;j++){
			if(strcmp(nama,inven.s[i].k[j].nama)==0){
				return j;
			}
		}
	}
}
int cek(string nama,Inventory inven){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<max_stack;j++){
			if(strcmp(nama,inven.s[i].k[j].nama)==0){
				return 0;
			}
		}
	}
}
Kartu popSatu(Inventory *inven,int i,int j){
	int l;
	Kartu temp;
	
	temp = (*inven).s[i].k[(*inven).s[j].top];
	for(l=j;l<max_stack;l++){
		(*inven).s[i].k[l]=(*inven).s[i].k[l+1];
	}
	(*inven).s[i].top--;
}
void printKartu1(Inventory inven,int i,int j){
	printf("\nKartu [%d] - %s - %d Skill Berhasil di Hapus [!]",inven.s[i].k[j].id,inven.s[i].k[j].nama,inven.s[i].k[j].slotSkill);
}