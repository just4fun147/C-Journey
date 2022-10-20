#include "header.h"

int isEmpty(arrayType a){
	return (a[0]==NULL);
}

int isFull(arrayType a){
	return (a[N-1]!=NULL);
}

void createEmpty(arrayType a){
	int i;
	for(i=0;i<N;i++){
		(a)[i]=NULL;
	}
}

void initMaha(Mahasiswa maha){
	int i;
	for(i=0;i<M;i++){
		strcpy(maha.nama[i],"");
		strcpy(maha.npm[i],"");
	}
	
}
void swapElement(Mahasiswa *maha,int i,int j){
	string temp,temp1;
	strcpy(temp,(*maha).nama[i]);
	strcpy(temp1,(*maha).npm[i]);
	strcpy((*maha).npm[i],(*maha).npm[j]);
	strcpy((*maha).nama[i],(*maha).nama[j]);
	strcpy((*maha).npm[j],temp1);
	strcpy((*maha).nama[j],temp);
}
void bubbleSort(Mahasiswa *maha){
	int i,j;
	string temp,temp1;
	for(i=0;i<M-1;i++){
		for(j=i+1;j<M;j++){
			if(strcmp((*maha).npm[i],(*maha).npm[j])>0){
				strcpy(temp,(*maha).nama[i]);
				strcpy(temp1,(*maha).npm[i]);
				strcpy((*maha).npm[i],(*maha).npm[j]);
				strcpy((*maha).nama[i],(*maha).nama[j]);
				strcpy((*maha).npm[j],temp1);
				strcpy((*maha).nama[j],temp);
			}
		}
	}
}

int binarySearch(Mahasiswa maha,int left,int right,string npm){
	int mid = (left+right)/2;
	
	if(right>=left){
		if(strcmp(maha.npm[mid],npm)==0){
			return mid;
		}else if(strcmp(maha.npm[mid],npm)>0){
			return binarySearch(maha,left,mid-1,npm);
		}else{
			return binarySearch(maha,mid+1,right,npm);
		}
		
	}
}

int sequentialSearch(arrayType a,infoType find){
	int i;
	for(i=0;i<N;i++){
		if(a[i]==find){
			return i;
		}
	}	
	return -1;
}

void printArray(arrayType a){
	int i;
	for(i=0;i<N;i++){
		printf("%d  ",a[i]);
	}
}

void historyPencarian(arrayType a,infoType find){
	int i;
	if(isFull(a)){
		createEmpty(a);
	}
	
	for(i=0;i<N;i++){
		if(a[i]==NULL){
			a[i]=find;
			break;
		}
	}
}
int cekUnique(arrayType a,infoType input){
	int i;
	for(i=0;i<N;i++){
		if(a[i]==input||input==0){
			return 0;
		}
	}
	return -1;
}

void copyArray(arrayType a,arrayType b){
	int i;
	for(i=0;i<N;i++){
		b[i]=a[i];
	}
}

void insertRandom(arrayType a){
	int i,k;
	time_t t1;
	srand ( (unsigned) time (&t1));
	for(i=0;i<N;i++){
		k= rand() % 50 + 1;
		(a)[i]=k;
	}
}

int cekNama(Mahasiswa maha,string nama){
	int i;
	for(i=0;i<M;i++){
		if(strcmp(maha.nama[i],nama)==0){
			return -1;
		}	
	}
	return 0;
}
int cekNpm(Mahasiswa maha,string npm){
	int i;
	for(i=0;i<M;i++){
		if(strcmp(maha.npm[i],npm)==0){
			return -1;
		}	
	}
	return 0;
}
void printMahasiswa(Mahasiswa maha){
	int i;
	printf("\nDATA SEMUA MAHASISWA");
	for(i=0;i<M;i++){
		printf("\n[%d] %s-%s",i+1,maha.nama[i],maha.npm[i]);
	}
}

int cek(Mahasiswa maha,string npm){
	int i;
	string npm2;
	for(i=0;i<M;i++){
		if(strcmp(maha.npm[i],npm)==0){
			return i;
		}
	}
	return -1;
}
void cariProdi(string npm){
	int i;
	string temp,temp1,a;
	strncpy(temp,npm,4);
	strcpy(a,"    ");
	strncpy(temp,a,2);
	i=atoi(temp);
	if(i==06){
		printf("Teknik Industri");
	}else if(i==07){
		printf("Informatika");
	}else if(i==17){
		printf("Sistem Informasi");
	}else{
		printf("yang tidak diketahui");
	}
}