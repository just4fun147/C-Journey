#include "header.h"

void initNama(Pegawai P[],int index){
	if(index<0){
		return;
	}else{
		strcpy(P[index].nama,"-");
		P[index].jumlahItem=0;
		initNama(P,index-1);
	}
}

int cekKosong(Pegawai P[],int index){
	if(index==-1){
		return -1;
	}else if(strcmpi(P[index].nama,"-")==0){
		return index;
	}else{
		return cekKosong(P,index-1);
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

void inputNama(Pegawai P[],int index){
	string nama;
	
	if(index<5){
		printf("\nMasukan Nama : ");fflush(stdin);gets(nama);
		strcpy(P[index].nama,nama);
		inputNama(P,index+1);
	}
}

void bekerja(Pegawai P[],string nama,int target){
	int i,k;
	i=1;
	k=cekPegawai(P,4,nama);
	if(k==-1){
		printf("\nNama tidak ditemukan");
	}else{
		PrintKerja(P,k,i,target);
	}
	
}
int cekPegawai(Pegawai P[],int index,string nama){
	int i;
	i=index;
	if(i<0){
		return -1;
	}else if(strcmp(P[i].nama,nama)==0){
		return i;		
	}else{
		return cekPegawai(P,i-1,nama);	
	}
}

void PrintKerja(Pegawai P[],int index,int hari,int target){
	int k,kerja;

	if(P[index].jumlahItem<target){
		kerja=rand()%50+50;
		printf("\nHari %d - %d",hari,kerja);
		P[index].jumlahItem=P[index].jumlahItem+kerja;
		PrintKerja(P,index,hari+1,target);
	}else{
		printf("\nJumlah Item sudah memenuhi target!");
	}
}

void tampilNama(Pegawai P[],int index){
	float gaji;
	if(index<0){
		return;
	}else{
		if(P[index].jumlahItem==-1){
			
		}else{
			tampilNama(P,index-1);
			gaji=P[index].jumlahItem*5000;
			if(P[index].jumlahItem!=0){
				printf("\n%s - Rp.%.2f",P[index].nama,gaji);
			}
		}
		
		
	}
}

int kluar(Pegawai P[],int index,int target){
	int i;
	i=index;
	if(i!=0){
		if(P[i].jumlahItem<target){
			
				kluar(P,i-1,target);
				return -1;

		}
	}
}



void bekerja2(Pegawai P[],string nama,int target){
	int i,k;
	i=1;
	k=cekPegawai(P,4,nama);
	if(k==-1){
		printf("\nNama tidak ditemukan");
	}else{
		PrintKerja2(P,k,i,target);
	}
	
}
void PrintKerja2(Pegawai P[],int index,int hari,int target){
	int k,kerja;
	
	if(P[index].jumlahItem<target&&P[index].jumlahItem!=-1){
		if(hari==23){
		printf("\nLebih dari 22 hari");
		P[index].jumlahItem=-1;
		return;
		}
		kerja=rand()%50+50;
		printf("\nHari %d - %d",hari,kerja);
		P[index].jumlahItem=P[index].jumlahItem+kerja;
		PrintKerja2(P,index,hari+1,target);
	}else{
		printf("\nJumlah Item sudah memenuhi target!");
	}
	if(hari==23){
		P[index].jumlahItem=-1;
	}
	
}

int kluar2(Pegawai P[],int index,int target){
	int i;
	i=index;
	if(i!=0){
		if(P[i].jumlahItem<target){
			if(P[i].jumlahItem>-1){
				return i+kluar2(P,i-1,target);
			}
			kluar(P,i-1,target);
		}
	
	}
}
