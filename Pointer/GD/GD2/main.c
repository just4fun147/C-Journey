#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int myArr[5],i;
	int *pointerArr;
	
	for(i=0;i<5;i++)
		myArr[i]=i+1;
		
	pointerArr=&myArr[0];
	printf("\nAlamat dari elemen ke-%d: %d, value: %d",i+1,pointerArr,*pointerArr);
	
	for(i=0;i<5;i++){
		printf("\nAlamat dari elemen ke-%d: %d, value: %d",i+1,pointerArr,*pointerArr);
		pointerArr++;
	}
	
	printf("\nMasukan indeks yang ingin diubah (0-4): ");scanf("%d",&i);
	pointerArr=&myArr[i];
	printf("Masukan value baru: ");scanf("%d",pointerArr);
	printf("\nAlamat dari elemen yang diubah: %d, value %d",pointerArr,*pointerArr);
	
	
	return 0;
}