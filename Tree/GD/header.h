#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <stdbool.h>

typedef struct Node* address;
typedef struct Node* BinaryTree;

typedef struct Node{
	int data;
	address Left;
	address Right;
}Node;

void createEmpty(BinaryTree *BT);

bool isEmpty(BinaryTree BT);
bool isLeaf(BinaryTree BT);
bool isSubTree(BinaryTree parent,BinaryTree child);
bool isSuperTree(BinaryTree child,BinaryTree parent);
bool isFound(BinaryTree BT,int x);

int maksimum(int a,int b);
int height(BinaryTree BT);
int level(BinaryTree BT,address P);
address addressOf(BinaryTree BT,int x);

address alokasi(int data);

void insTreeBST(BinaryTree *BT,address P);
void insTreeAcak(BinaryTree *BT,address P);

void preOrder(BinaryTree BT);
void inOrder(BinaryTree BT);
void postOrder(BinaryTree BT);

void deleteLeaf(address *P);