#include "header.h"


data makeData(string nama,int umur){
	data a;
	strcpy(a.nama, nama);
	a.umur = umur;
	
	return a;
}

void createEmpty(Queue *Q){
	(*Q).head = (*Q).tail =-1;
}

int isEmpty(Queue Q){
	return (Q.head==-1 && Q.tail==-1);
}

int isFull(Queue Q){
	return (Q.head < Q.tail && Q.tail-Q.head == MAX-1) ||
			(Q.head>Q.tail && Q.head-Q.tail == 1);
}

int isOneElmt(Queue Q){
	return (Q.head == Q.tail && Q.head != -1);
}

void enqueue(Queue *Q, data val){
	if(isEmpty(*Q)){
		(*Q).head = (*Q).tail =0;
	}else{
		if((*Q).tail == MAX - 1){
			(*Q).tail =0;
		}else{
			(*Q).tail++;
		}
	}
	(*Q).D[(*Q).tail] =val;
	printf("\n[*]Berhasil menambah data!");
}

void dequeue(Queue *Q){
	data temp;
	temp = (*Q).D[(*Q).head];
	
	if(isOneElmt(*Q)){
		createEmpty(&(*Q));
	}else{
		if((*Q).head == MAX-1){
			(*Q).head = 0;
		}else{
			(*Q).head++;
		}
	}
	printf("\n[*] Berhasil menghapus data [%s](%d) !", temp.nama,temp.umur);
}

void Print(Queue Q){
	int i;
	if(Q.head<=Q.tail){
		for(i=Q.head;i<=Q.tail;i++){
			printf("%s(%d)",Q.D[i].nama,Q.D[i].umur);
		}
	}else{
		for(i=Q.head;i<MAX;i++){
			printf("%s(%d)",Q.D[i].nama,Q.D[i].umur);
		}
		for(i=0;i<=Q.tail;i++){
			printf("%s(%d)",Q.D[i].nama,Q.D[i].umur);
		}
	}
}


int isFound(Queue Q,string target){
	int i;
	
	if(Q.head<=Q.tail){
		for(i=Q.head;i<=Q.tail;i++){
			if(strcmpi(target,Q.D[i].nama)==0){
				return i;
			}
		}
	}else{
		for(i=Q.head;i<MAX;i++){
			if(strcmpi(target,Q.D[i].nama)==0){
				return i;
			}
		}
		for(i=0;i<=Q.tail;i++){
			if(strcmpi(target,Q.D[i].nama)==0){
				return i;
			}
		}
	}
	return -1;
}