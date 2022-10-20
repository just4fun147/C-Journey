#include "header.h"

void initNama(string nama[],int index){
	if(index<0){
		return;
	}else{
		strcpy(nama[index],"-");
		initNama(nama,index-1);
	}
}

int cekKosong(string nama[],int index){
	if(index==-1){
		return -1;
	}else if(strcmpi(nama[index],"-")==0){
		return index;
	}else{
		return cekKosong(nama,index-1);
	}
}

int cekSisa(string nama[],int index,int sisa){
	if(index<0){
		return sisa;
	}else{
		if(strcmpi(nama[index],"-")==0){
			sisa+=1;
		}
		return cekSisa(nama,index-1,sisa);
	}
}

void inputNama(string nama[],int jumlahInput){
	string temp;
	if(jumlahInput>0){
		printf("\nNama: ");fflush(stdin);gets(temp);
		strcpy(nama[cekKosong(nama,size-1)],temp);
		inputNama(nama,jumlahInput-1);
	}
}

void tampilNama(string nama[],int index){
	if(index<0){
		return;
	}else{
		printf("\n%s",nama[index]);
		tampilNama(nama,index-1);
	}
}