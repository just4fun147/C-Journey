#include "header.h"

int isEmpty(array a){
	if(a.first==-1 && a.last==-1){
		return 1;
	}else{
		return 0;
	}
}

void createEmpty(array *a){
	a->first=-1;
	a->last=-1;
}

void add(array *a,string nama,string warna,string ukuran,int lama){
	
	a->lama[a->last+1]=lama;
	strcpy(a->nama[a->last+1],nama);
	strcpy(a->warna[a->last+1],warna);
	strcpy(a->ukuran[a->last+1],ukuran);
	a->last++;
}

infoType getElementAt(array a,int i){
	return a.t[i];
}

int lenght(array a){
	
	return a.last+1;
}

void printInfo(array a){
	int i;
	for(i=0;i<=a.last;i++){
		printf("\n[%d]",i+1);
		printf("\nNama Penyewa : %s",a.nama[i]);
		printf("\nWarna Tenda : %s",a.warna[i]);
		printf("\nUkuran Tenda : %s",a.ukuran[i]);
		printf("\nLama Sewa : %d\n",a.lama[i]);
	}
}

void setArray(array *a,int i){
	int lama;
	string nama,warna,ukuran;
	createEmpty(a);
		printf("\n[%d]",i+1);
			do{
				printf("\nNama Penyewa : ");fflush(stdin);gets(a->nama[i]);
			}while(strcmpi(a->nama[i],"")==0);				
		
			do{
				printf("\nWarna Tenda : ");fflush(stdin);gets(a->warna[i]);
			}while(strcmpi(a->warna[i],"")==0);
			
			do{
				printf("\nUkuran Tenda : ");fflush(stdin);gets(a->ukuran[i]);
			}while(strcmpi(a->ukuran[i],"")==0);
			
			do{
				printf("\nLama Sewa : ");scanf("%d",&(a->lama[i]));
			}while(a->lama[i]<=0);
			printf("\nInput Data Berhasil!");
	a->t[i]=i;
	a->last=i;
}

void swap(int *a,int *b){
	int temp =*a;
	*a=*b;
	*b=temp;
}

void swapString(string *a,string *b){
	string temp;
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}

void bubbleSort(array *a){
	int i,j;
	string temp;
	for(i=0;i<=a->last-1;i++){
		for(j=i+1;j<=a->last;j++){
			if(strcmp(a->nama[i],a->nama[j])>0){
				swap(&(a->lama[i]),&(a->lama[j]));
				swapString(&(a->nama[i]),&(a->nama[j]));
				swapString(&(a->ukuran[i]),&(a->ukuran[j]));
				swapString(&(a->warna[i]),&(a->warna[j]));
			}
		}
	}
}

array clone(array a){
	int i;
	array temp;
	for(i=0;i<=a.last;i++){
		temp.lama[i]=a.lama[i];
		strcpy(temp.nama[i],a.nama[i]);
		strcpy(temp.ukuran[i],a.ukuran[i]);
		strcpy(temp.warna[i],a.warna[i]);
		temp.t[i]=a.t[i];
	}
	temp.first=a.first;
	temp.last=a.last;
	return temp;
}

void breakIntoTwo(array *a,array *a2){
	int i,len=lenght(*a);
	
	a->first=0;
	a->last=(len/2)+(len%2)-1;
	a2->first=0;
	a2->last=len-lenght(*a)-1;
	for(i=0;i<=a2->last;i++){
		a2->lama[i]=a->lama[i+lenght(*a)];
		strcpy(a2->nama[i],a->nama[i+lenght(*a)]);
		strcpy(a2->ukuran[i],a->ukuran[i+lenght(*a)]);
		strcpy(a2->warna[i],a->warna[i+lenght(*a)]);
	}
}

void merge(array *a,array b){
	int i=0,j=0,k;
	array temp;
	createEmpty(&temp);
	while(i<=a->last&&j<=b.last){
		if(a->lama[i]<b.lama[j]){
			add(&temp,a->nama[i],a->warna[i],a->ukuran[i],a->lama[i]);
			i++;
		}else{
			add(&temp,b.nama[j],b.warna[j],b.ukuran[j],b.lama[j]);
			j++;
		}
	}
	
	if(i>a->last){
		for(k=j;k<=b.last;k++){
			add(&temp,b.nama[k],b.warna[k],b.ukuran[k],b.lama[k]);
		}
	}else{
		for(k=i;k<=a->last;k++){
			add(&temp,a->nama[k],a->warna[k],a->ukuran[k],a->lama[k]);
		}
	}
	*a=clone(temp);
}

void mergeSort(array *a){
	array b;
	if(lenght(*a)>1){
		breakIntoTwo(&(*a),&b);
		mergeSort(&(*a));
		mergeSort(&b);
		merge(a,b);
	}
}

void quickSort(array *a,int first,int last){
	int i=first,j=last;
	string pivot;
	strcpy(pivot,a->warna[(first+last)/2]);
	
	while(i<=j){
		while(strcmp(a->warna[i],pivot)<0){
			i++;
		}
		while(strcmp(a->warna[j],pivot)>0){
			j--;
		}
		if(i<=j){
			swap(&a->lama[i],&a->lama[j]);
			swapString(&(a->nama[i]),&(a->nama[j]));
			swapString(&(a->ukuran[i]),&(a->ukuran[j]));
			swapString(&(a->warna[i]),&(a->warna[j]));
			i++;
			j--;
		}
	}
	if(first<j){
		quickSort(&(*a),first,j);
	}
	if(i<last){
		quickSort(&(*a),i,last);
	}
}