#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int NIM;
	double IPK;
}Mahasiswa;


int main(int argc, char *argv[]) {
	Mahasiswa M;
	Mahasiswa* pM;
	
	printf("NIM: ");scanf("%d",&M.NIM);
	printf("IPK: ");scanf("%d",&M.IPK);
	
	pM=&M;
	
	printf("\nNIM: %d",pM->NIM);
	printf("\nIPK: %d",pM->IPK);
	return 0;
}