#include "header.h"



data makeData(string nama,int umur,float nilaiFrontend,float nilaiBackend){
	data d;
	
	strcpy(d.nama, nama);
	d.umur = umur;
	d.nilaiBackend = nilaiBackend;
	d.nilaiFrontend = nilaiFrontend;
	
	return d;
}

void createEmpty(Queue *Q){
	(*Q).head = (*Q).tail = -1;
}

int isEmpty(Queue Q){
	return (Q.head == -1 && Q.tail == -1);
}

int isFull(Queue Q){
	return (Q.head < Q.tail && Q.tail - Q.head == MAX-1) || (Q.head > Q.tail && Q.head - Q.tail == 1);
}
int isOneElmt(Queue Q){
	return (Q.head == Q.tail && Q.head!=-1);
}
void enqueue(Queue *Q, data d){
	if(isEmpty(*Q)){
		(*Q).head = (*Q).tail = 0;
	}else{
		if((*Q).tail == MAX-1){
			(*Q).tail = 0;
		}else {
			(*Q).tail++;
		}
	}
	(*Q).d[(*Q).tail] = d;
	

}

void dequeue(Queue *Q){
	data temp;
	temp = (*Q).d[(*Q).head];
	
	if(isOneElmt(*Q)){
		createEmpty(&(*Q));
	}else{
		if((*Q).head == MAX-1){
			(*Q).head = 0;
		}else{
			(*Q).head++;
		}
	}

}
int isFound(Queue Q,string nama){
	int i;
	if(Q.head<=Q.tail){
		for(i=Q.head;i<=Q.tail;i++){
			if(strcmpi(nama,Q.d[i].nama)==0){
				return i;
			}
		}
	}else{
		for(i=Q.head; i<MAX; i++){
			if(strcmpi(nama,Q.d[i].nama)==0){
				return i;
			}
		}
		for(i=0; i<=Q.tail; i++){
			if(strcmpi(nama,Q.d[i].nama)==0){
				return i;
			}
		}
	}
	return -1;
}

void Print(Queue Q){
	int i;
	
	if(Q.head <= Q.tail){
		for(i=Q.head; i<=Q.tail; i++){
			printf("%s(%.0f|%.0f) ", Q.d[i].nama, Q.d[i].nilaiFrontend, Q.d[i].nilaiBackend);
		}
	}else{
		for(i=Q.head; i<MAX; i++){
			printf("%s(%.0f|%.0f) ", Q.d[i].nama, Q.d[i].nilaiFrontend, Q.d[i].nilaiBackend);
		}
		for(i=0; i<=Q.tail; i++){
			printf("%s(%.0f|%.0f) ", Q.d[i].nama, Q.d[i].nilaiFrontend, Q.d[i].nilaiBackend);
		}
	}
}

int cekPelamar(Queue Q){
	
	if(Q.d[Q.head].umur>30){
		return 1;
	}
	if(Q.d[Q.head].nilaiBackend + Q.d[Q.head].nilaiFrontend <150){
		return 1;
	}
	return 2;
}
void show(Queue Q,int temp){
	printf("\n=== Tampil Detail ===");
	printf("\nNama				: %s",Q.d[temp].nama);
	printf("\nUmur				: %i",Q.d[temp].umur);
	printf("\nNilai Frontend			: %.0f",Q.d[temp].nilaiFrontend);	
	printf("\nNilai Backend			: %.0f",Q.d[temp].nilaiBackend);
}

int cekNama(Queue Q1,Queue Q2,string nama){
	int i;
	if(Q1.head<=Q1.tail){
		for(i=Q1.head;i<=Q1.tail;i++){
			if(strcmpi(nama,Q1.d[i].nama)==0){
				return 1;
			}
		}
	}else{
		for(i=Q1.head; i<MAX; i++){
			return 1;
		}
		for(i=0; i<=Q1.tail; i++){
			return 1;
		}
	}
	if(Q2.head<=Q2.tail){
		for(i=Q2.head;i<=Q2.tail;i++){
			if(strcmpi(nama,Q2.d[i].nama)==0){
				return 1;
			}
		}
	}else{
		for(i=Q2.head; i<MAX; i++){
			return 1;
		}
		for(i=0; i<=Q2.tail; i++){
			return 1;
		}
	}
}
void edit(Queue *Q,data d, int temp){
	(*Q).d[temp] = d;
}