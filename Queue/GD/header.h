#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 5

typedef char string[100];

typedef struct{
	string nama;
	int umur;
}data;

typedef struct{
	data D[MAX];
	int head;
	int tail;
}Queue;

data makeData(string nama,int umur);
void createEmpty(Queue *Q);
int isEmpty(Queue Q);
int isFull(Queue Q);
int isOneElmt(Queue Q);
void enqueue(Queue *Q, data val);
void dequeue(Queue *Q);
void Print(Queue Q);
int isFound(Queue Q,string target);