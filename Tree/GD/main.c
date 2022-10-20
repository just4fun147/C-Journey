#include "header.h"



int main(int argc, char *argv[]) {
	BinaryTree BT_BST,BT_ACAK;

	createEmpty(&BT_BST);
	insTreeBST(&BT_BST,alokasi(2));
	insTreeBST(&BT_BST,alokasi(0));
	insTreeBST(&BT_BST,alokasi(0));
	insTreeBST(&BT_BST,alokasi(7));
	insTreeBST(&BT_BST,alokasi(1));
	insTreeBST(&BT_BST,alokasi(0));
	insTreeBST(&BT_BST,alokasi(7));
	insTreeBST(&BT_BST,alokasi(5));
	insTreeBST(&BT_BST,alokasi(5));

	createEmpty(&BT_ACAK);
	insTreeAcak(&BT_ACAK,alokasi(2));
	insTreeAcak(&BT_ACAK,alokasi(0));
	insTreeAcak(&BT_ACAK,alokasi(0));
	insTreeAcak(&BT_ACAK,alokasi(7));
	insTreeAcak(&BT_ACAK,alokasi(1));
	insTreeAcak(&BT_ACAK,alokasi(0));
	insTreeAcak(&BT_ACAK,alokasi(7));
	insTreeAcak(&BT_ACAK,alokasi(5));
	insTreeAcak(&BT_ACAK,alokasi(5));
	
	printf("\nBinary Tree BST ===========");
	printf("\nPre Order : ");
	preOrder(BT_BST);
	
	printf("\nIn Order : ");
	inOrder(BT_BST);
	
	printf("\nPost Order : ");
	postOrder(BT_BST);
	
	printf("\n");
	printf("\nBinary Tree Acak ===========");
	printf("\nPre Order : ");
	preOrder(BT_ACAK);
	
	printf("\nIn Order : ");
	inOrder(BT_ACAK);
	
	printf("\nPost Order : ");
	postOrder(BT_ACAK);
	
	printf("\n\n==============================");
	printf("\nTinggi Pohon BST : %d",height(BT_BST));
	printf("\nTinggi Pohon Acak : %d",height(BT_ACAK));
	
	printf("\n\n==============================");
	printf("\nNilai 8 ada di level (BST) : %d",level(BT_BST,addressOf(BT_BST,8)));
	printf("\nNilai 8 ada di level (ACAK) : %d",level(BT_ACAK,addressOf(BT_ACAK,8)));
	return 0;
}