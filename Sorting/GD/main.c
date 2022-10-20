#include "header.h"



int main(int argc, char *argv[]) {
	int n,pilih;
	array a;
	createEmpty(&a);
	
	do{
		system("cls");
		printf("\tSORTING");
		printf("\n1. Set Array");
		printf("\n2. Print Array");
		printf("\n3. Bubble Sort");
		printf("\n4. Merge Sort");
		printf("\n5. Quick Sort");
		printf("\n0. Keluar");
		printf("\nMasukkan pilihan menu : ");scanf("%d",&pilih);
		
		switch(pilih){
			case 1:
				if(isEmpty(a)==1){
					printf("\nMasukan jumlah elemen dalam array : ");scanf("%d",&n);
					setArray(&a,n);
					printf("\nArray telah terbentuk");
					printInfo(a);
				}else{
					printf("\nArray sudah terisi");
				}
				break;
			
			case 2:
				printf("\t\tTampil Array\n");
				printInfo(a);
				break;
			
			case 3:
				printf("\nSebelum bubble sort : \n");printInfo(a);
				printf("\nSetlah bubble sort : \n");bubbleSort(&a);
				printInfo(a);
				break;
			case 4:
				printf("\nSebelum merge sort : \n");printInfo(a);
				printf("\nSetelah merge sort : \n");mergeSort(&a);
				printInfo(a);
				break;
			case 5:
				printf("\nSebelum quick sort : \n");printInfo(a);
				printf("\nSetelah quick sort : \n");quickSort(&a,0,a.last);
				printInfo(a);
				break;
			case 0:
				printf("\nKeluar");
				break;
			default:
				printf("\nTidak ada pilihan!");
				break;
		}
		getch();
	}while(pilih!=0);
	return 0;
}