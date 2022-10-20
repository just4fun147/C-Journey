#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int x;
	int *pointerX;
	
	printf("Masukan value untuk variable X: ");scanf("%d",&x);
	pointerX=&x;
	
	printf("alamat dari variable X adalah: %d dan valuenya %d", pointerX,*pointerX);
	return 0;
}