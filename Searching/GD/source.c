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

void swapElement(keyType *first,keyType *second){
	keyType temp;
	temp=(*first);
	(*first)=(*second);
	(*second)=temp;
}

void bubbleSort(arrayType a){
	int i,j;
	for(i=0;i<N-1;i++){
		for(j=i+1;j<N;j++){
			if((a)[i]>(a)[j]){
				swapElement(&(a)[i],&(a)[j]);
			}
		}
	}
}

int binarySearch(arrayType a,int left,int right,infoType find){
	int mid = (left+right)/2;
	
	if(right>=left){
		if(a[mid]==find){
			return mid;
		}else if(a[mid]>find){
			return binarySearch(a,left,mid-1,find);
		}else{
			return binarySearch(a,mid+1,right,find);
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
		printf("%d",a[i]);
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