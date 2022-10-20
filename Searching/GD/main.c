#include "header.h"


int main(int argc, char *argv[]) {
	arrayType array,history,sortArray;
	int menu;
	int input;
	int find,found;
	int i;
	
	createEmpty(history);
	createEmpty(array);
	
	do{
		system("cls");
		printf("GUIDED SEARCHING");
		printf("\n [1] Input Number");
		printf("\n [2] Sequential Search");
		printf("\n [3] Binary Search");
		printf("\n [4] Show Number and Search History");
		printf("\n [0] End Program");
		printf("\n>>>");scanf("%d",&menu);
		
		switch(menu){
			case 1:
				if(isFull(array)){
					createEmpty(array);
				}
				printf("\nDisini inputkan 5 angka sekaligus, secara acak, dan unique \n");
				for(i=0;i<N;i++){
					printf("Data ke-%d = ",i+1);scanf("%d",&input);
					if(cekUnique(array,input)==0){
						printf("data harus unique dan !=0 [!]\n");
						i--;
					}else{
						array[i]=input;
					}
				}
				printf("\nData berhasil ditambahkan[!]");
				break;
			case 2:
				if(isEmpty(array)){
					printf("\n Array Kosong [!]");
					break;
				}
				printf("\nData dalam Array : ");printArray(array);
				printf("\nCari : ");scanf("%d",&find);
				if(find==0){
					printf("\n NULL atau 0 tidak dapat dicari [!]");
					break;
				}
				historyPencarian(history,find);
				found=sequentialSearch(array,find);
				if(found==-1){
					printf("\nData tidak ditemukan[!]");
				}else{
					printf("\nData %d ditemukan di indeks ke-%d",array[found],found);
				}
				break;
			case 3:
				if(isEmpty(array)){
					printf("\nArray Kosong[!]");
					break;
				}
				printf("\nSebelum Sorting : ");printArray(array);
				copyArray(array,sortArray);
				bubbleSort(sortArray);
				printf("\nSetelah Sorting : ");printArray(sortArray);
				printf("\nCari : ");scanf("%d",&find);
				if(find==0){
					printf("\nNULL atau 0 tidak dapat dicari[!]");
					break;
				}
				historyPencarian(history,find);
				found=binarySearch(sortArray,0,N-1,find);
				
				if(found==-1){
					printf("\n Data tidak ditemukan[!]");
				}else{
					printf("\nData %d ditemukan di indeks ke-%d",sortArray[found],found);
				}
				break;
			case 4:
				if(isEmpty(array)){
					printf("\nArray Kosong[!]");
					break;
				}
				printf("\nData dalam Array : ");printArray(array);
				printf("\nHistory Pencarian : ");printArray(history);
				break;
			default:
				break;
		}
		getch();
	}while(menu!=0);
	printf("Selamat Belajar");
	return 0;
}