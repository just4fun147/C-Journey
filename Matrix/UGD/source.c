#include "header.h"
Kamar inputKamar(int idKamar, string tipeKamar,string nama,string no,int jangkaSewa){
	Kamar a;
	
	 a.idKamar = idKamar;
	 strcpy(a.tipeKamar, tipeKamar);
	 strcpy(a.p.nama, nama);
	 strcpy(a.p.no, no);
	 a.p.jangkaSewa = jangkaSewa;
	 
	return a;
}

void init(Matriks *M){
	int i,j;
	Kamar a;
	a = inputKamar(0,"-","-","-",0);
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			(*M)[i][j] = a;
		}
	}
}


int cekTipe(string tipeKamar){
	if(strcmp(tipeKamar,"Super Eksklusif")==0){
		return 0;
	} if(strcmp(tipeKamar,"Eksklusif")==0){
		return 1;
	} if(strcmp(tipeKamar,"Regular")==0){
		return 2;
	}
		return 4;

}

int cekID(int idKamar,int i){
	if(i==0){
		if(idKamar==1||idKamar==2||idKamar==3){
			return idKamar;
		}
	} 
	if(i==1){
		if(idKamar==4||idKamar==5||idKamar==6){
			return idKamar-3;
		}
	} 
	if(i==2){
		if(idKamar==7||idKamar==8||idKamar==9){
			return idKamar-6;
		}
	}if(i!=0||i!=1||i!=2){
		return 0;
	}
}

void tampilMatriks(Matriks M){
	int k=0,l=3;
	int i,j;
	for(i=0;i<3;i++){
		printf("Tingkat %d\n",l);
		for(j=0;j<3;j++){
			k=k+1;
			printf ("[%d |%s ]\t\t",k,M[i][j].p.nama);
			
		}
		printf("\n--------------------------------------\n");
		l--;
	}
}

int cekKosong(int i,int j,Matriks Mat){
	if(strcmp(Mat[i][j-1].p.nama,"-")==0){
		return 2;
	}
		return 3;
}

int cekNama(string nama,Matriks Mat){
	int i,j;
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			if(strcmp(Mat[i][j].p.nama,nama)==0){
				return 1;
			}
		}
	}
	return 2;
}

int cariI(string nama,Matriks Mat){
	int i,j;
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			if(strcmp(Mat[i][j].p.nama,nama)==0){
				return i;
			}
		}
	}
}

int cariJ(string nama,Matriks Mat){
	int i,j;
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			if(strcmp(Mat[i][j].p.nama,nama)==0){
				return j;
			}
		}
	}
}

void show(int i,int j,Matriks Mat){
	printf("\n[Data Penyewa Lama]");
	printf("\nNama : %s",Mat[i][j].p.nama);
	printf("\nNo Telepon : %s",Mat[i][j].p.nama);
	printf("\nJangka Sewa : %d",Mat[i][j].p.jangkaSewa);
	
	
}
Kamar editKamar(string nama,string no,int jangkaSewa,Matriks *Mat,int i,int j){
	strcpy((*Mat)[i][j].p.nama,nama);
	strcpy((*Mat)[i][j].p.no,no);
	(*Mat)[i][j].p.jangkaSewa;
}

void tampilSebagian(int i, int j,Matriks Mat){
	printf("\n[Data Kamar]");
	printf("\nTipe : %s",Mat[i][j].tipeKamar);
	printf("\nID : %d",Mat[i][j].idKamar);
	printf("\n\nNama : %s",Mat[i][j].p.nama);
	printf("\nNo Telepon : %s",Mat[i][j].p.nama);
	printf("\nJangka Sewa : %d",Mat[i][j].p.jangkaSewa);
	
}

float biayaSewa(Matriks Mat,int i,int j){
	if(strcmp(Mat[i][j].tipeKamar,"Super Eksklusif")==0){
		return Mat[i][j].p.jangkaSewa*1500000;
	}else if(strcmp(Mat[i][j].tipeKamar,"Eksklusif")==0){
		return Mat[i][j].p.jangkaSewa*1000000;
	}else if(strcmp(Mat[i][j].tipeKamar,"Regular")==0){
		return Mat[i][j].p.jangkaSewa*750000;
	}
}