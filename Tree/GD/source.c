#include "header.h"

void createEmpty(BinaryTree *BT){
	(*BT)=NULL;
}

bool isEmpty(BinaryTree BT){
	return (BT==NULL);
}

bool isLeaf(BinaryTree BT){
	return(isEmpty(BT->Left)&&isEmpty(BT->Right));
}

bool isSubTree(BinaryTree parent,BinaryTree child){
	return((child==parent->Left)||(child==parent->Right));
}

bool isSuperTree(BinaryTree child,BinaryTree parent){
	return(isSubTree(parent,child));	
}

bool isFound(BinaryTree BT,int x){
	if(isEmpty(BT)){
		return false;
	}else{
		return(BT->data==x||isFound(BT->Left,x)||isFound(BT->Right,x));
	}
}

int maksimum(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int height(BinaryTree BT){
	if(isEmpty(BT)){
		return (-1);
	}else if(isLeaf(BT)){
		return 0;
	}else{
		return(1+maksimum(height(BT->Left),height(BT->Right)));
	}
}

int level(BinaryTree BT,address P){
	if(BT->data==P->data){
		return 1;
	}else if(isFound(BT->Left,P->data)){
		return(1+level(BT->Left,P));
	}else{
		return(1+level(BT->Right,P));
	}
}
address addressOf(BinaryTree BT,int x){
	if(isEmpty(BT)){
		return NULL;
	}else if(BT->data==x){
		return BT;
	}else{
		if(isFound(BT->Left,x)){
			return(addressOf(BT->Left,x));
		}else if(isFound(BT->Right,x)){
			return(addressOf(BT->Right,x));
		}else{
			return NULL;
		}
	}
}

address alokasi(int data){
	address P=NULL;
	P=(Node*)malloc(sizeof(Node));
	
	if(P==NULL){
		return NULL;
	}else{
		P->data=data;
		P->Left=P->Right=NULL;
		return P;
	}
}

void insTreeBST(BinaryTree *BT,address P){
	if(isEmpty((*BT))){
		(*BT)=P;
	}else{
		if(P->data<(*BT)->data){
			insTreeBST(&(*BT)->Left,P);
		}else{
			insTreeBST(&(*BT)->Right,P);
		}
	}
}

void insTreeAcak(BinaryTree *BT,address P){
	int a;
	if(isEmpty((*BT))){
		(*BT)=P;
	}else{
		a=rand()%2;
		if(a==0){
			insTreeAcak(&(*BT)->Left,P);
		}else{
			insTreeAcak(&(*BT)->Right,P);
		}
	}
}

void preOrder(BinaryTree BT){
	if(!isEmpty(BT)){
		printf("%d",BT->data);
		preOrder(BT->Left);
		preOrder(BT->Right);
	}
}

void inOrder(BinaryTree BT){
	if(!isEmpty(BT)){
		inOrder(BT->Left);
		printf("%d",BT->data);
		inOrder(BT->Right);
	}
}
void postOrder(BinaryTree BT){
	if(!isEmpty(BT)){
		postOrder(BT->Left);
		postOrder(BT->Right);
		printf("%d",BT->data);
	}
}

void deleteLeaf(address *P){
	address A=(*P);
	(*P)=NULL;
	free(A);
}