#include "header.h"


int main(int argc, char *argv[]) {
	arrayType array,history,sortArray;
	int menu;
	int input;
	int find,found;
	int i;
	string nama,npm,cari,a,b;
	Mahasiswa maha;
	
	createEmpty(history);
	createEmpty(array);
	
	do{
		system("cls");
		printf("UNGUIDED SEARCHING");
		printf("\n [1] JAWABAN SOAL PERTAMA");
		printf("\n [2] JAWABAN SOAL KEDUA");
		printf("\n [3] JAWABAN SOAL KETIGA");
		printf("\n [4] TUGAS");
		printf("\n [0] Exit");
		printf("\n>>>");scanf("%d",&menu);
		
		switch(menu){
			case 1:
				insertRandom(array);
				printf("\nData dalam Array : ");printArray(array);
				printf("\n\nMasukan angka yang dicari : ");scanf("%d",&find);
				if(find==0){
					printf("\n NULL atau 0 tidak dapat dicari [!]");
					break;
				}
				found=sequentialSearch(array,find);
				if(found==-1){
					printf("\nData tidak ditemukan[!]");
				}else{
					printf("\nData %d ditemukan di indeks ke-%d",array[found],found);
				}
				break;
			case 2:
				printf("\nSilahkan input 5 data mahasiswa dengan atribut berikut :");
				for(i=0;i<M;i++){
					printf("\nData Mahasiswa ke- %d",i+1);
					do{
						printf("\nNama : ");fflush(stdin);gets(maha.nama[i]);
					}while(strcmpi(maha.nama[i],"")==0);
					
					do{
						printf("NPM : ");fflush(stdin);gets(npm);
						if(cekNpm(maha,npm)!=-1){
							strcpy(maha.npm[i],npm);
						}
					}while(strlen(maha.npm[i])!=9);
					
				}
				printMahasiswa(maha);
				printf("\nMasukan NPM Mahasiswa yang dicari : ");fflush(stdin);gets(cari);
				i=cek(maha,cari);
				if(i==-1){
					printf("\nData Mahasiswa Tidak ditemukan!");
					break;
				}
				do{
					printf("\nNama : ");fflush(stdin);gets(maha.nama[i]);
				}while(strcmpi(maha.nama[i],"")==0);
						
				do{
					printf("NPM : ");fflush(stdin);gets(npm);
					if(cekNpm(maha,npm)!=-1){
						strcpy(maha.npm[i],npm);
						}
				}while(strlen(maha.npm[i])!=9);
				
				printf("\nEdit Data Mahasiswa Berhasil[!]");
				printMahasiswa(maha);
				break;
			case 3:
				bubbleSort(&maha);
				printf("\nSelamat Datang di Fitur Tebak Prodi");
				printMahasiswa(maha);
				printf("\nMasukan NPM Mahasiswa yang dicari : ");;fflush(stdin);gets(cari);
				i=binarySearch(maha,0,M-1,cari);
				if(i==-1){
					printf("\nData Mahasiswa Tidak ditemukan!");
					break;
				}
				printf("\nMahasiswa Ditemukan[!]");
				printf("\nMahasiswa dengan NPM %s berada di prodi ",cari);cariProdi(cari);
				
				break;
			case 4:
			
				break;
			default:
				break;
		}
		getch();
	}while(menu!=0);
	printf("Paulus Pandu Windito-E-200710755");
	return 0;
}