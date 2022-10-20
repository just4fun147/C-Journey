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

void add(array *a,infoType x){
	a->t[a->last+1]=x;
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
		printf("%d",a.t[i]);
	}
}

void setArray(array *a,int n){
	int i;
	createEmpty(a);
	for(i=0;i<n;i++){
		printf("\nMasukkan data ke %d : ",i+1);scanf("%d",&(a->t[i]));
	}
	a->last=n-1;
}

void swap(int *a,int *b){
	int temp =*a;
	*a=*b;
	*b=temp;
}

void bubbleSort(array *a){
	int i,j;
	for(i=0;i<=a->last-1;i++){
		for(j=i+1;j<=a->last;j++){
			if(a->t[i]>a->t[j]){
				swap(&(a->t[i]),&(a->t[j]));
			}
		}
	}
}

array clone(array a){
	int i;
	array temp;
	for(i=0;i<=a.last;i++){
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
		a2->t[i]=a->t[i+lenght(*a)];
	}
}

void merge(array *a,array b){
	int i=0,j=0,k;
	array temp;
	createEmpty(&temp);
	while(i<=a->last&&j<=b.last){
		if(a->t[i]<b.t[j]){
			add(&temp,a->t[i]);
			i++;
		}else{
			add(&temp,a->t[j]);
			j++;
		}
	}
	
	if(i>a->last){
		for(k=j;k<=b.last;k++){
			add(&temp,a->t[k]);
		}
	}else{
		for(k=i;k<=a->last;k++){
			add(&temp,a->t[k]);
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
	int pivot=a->t[(first+last)/2];
	
	while(i<=j){
		while(a->t[i]<pivot){
			i++;
		}
		while(a->t[j]>pivot){
			j--;
		}
		if(i<=j){
			swap(&a->t[i],&a->t[j]);
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