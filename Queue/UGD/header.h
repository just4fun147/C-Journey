#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 5
typedef char string[100];

typedef struct{
	string nama;
	int umur;
	float nilaiFrontend;
	float nilaiBackend;
} data;

typedef struct{
	data d[MAX];
	int head;
	int tail;
} Queue;


data makeData(string nama,int umur,float nilaiFrontend,float nilaiBackend);
void createEmpty(Queue *Q);
int isEmpty(Queue Q);
int isFull(Queue Q);
int isOneElmt(Queue Q);
void enqueue(Queue *Q,data d);
void dequeue(Queue *Q);
int isFound(Queue Q,string nama);
void Print(Queue Q);
int cekPelamar(Queue Q);
void show(Queue Q,int temp);
int cekNama(Queue Q1,Queue Q2,string nama);
void edit(Queue *Q,data d, int temp);