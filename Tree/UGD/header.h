#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <stdbool.h>

typedef char string[100];
typedef struct Node* address;
typedef struct Node* BinaryTree;

typedef struct Node{
	string nama,jenis;
	int jumlah;
	float harga;
	address Left;
	address Right;
}Node;

void createEmpty(BinaryTree *BT);

bool isEmpty(BinaryTree BT);
bool isLeaf(BinaryTree BT);
bool isSubTree(BinaryTree parent,BinaryTree child);
bool isSuperTree(BinaryTree child,BinaryTree parent);
bool isFound(BinaryTree BT,string nama);

int maksimum(int a,int b);
int height(BinaryTree BT);
int level(BinaryTree BT,address P);
address addressOf(BinaryTree BT,string nama);
address alokasi(string nama,string jenis,int jumlah, float harga);
void insTreeBST(BinaryTree *BT,address P);
void inOrder(BinaryTree BT);
void deleteLeaf(address *P);
void gantiJumlah(BinaryTree *BT,string nama,int jumlah);
void deleteMenu(BinaryTree *BT,string nama);