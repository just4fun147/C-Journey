#include "header.h"
//parent=cabang
//child=anggota

int main(int argc, char *argv[]) {
	ListParent L;
	adrParent P,cek1,cek2;
	adrChild C;
	int menu;
	string name,targetName,kodeCabang,negara,id,nama,kode1,kode2;
	Cabang cabang;
	Anggota anggota;
	createEmpty(&L);
	
	do{
		system("cls");
		printf("Multilist");
		printf("\n1. Daftar babang baru");
		printf("\n2. Cari cabang di suatu negara");
		printf("\n3. Daftarkan anggota baru");
		printf("\n4. Pangkas anggota");
		printf("\n5. Tampilkan cabang dan anggota dan anggota seluruh dunia");
		printf("\n\n BONUS");
		printf("\n6. Bubarkan Agen");
		printf("\n7. Lacak agen");
		printf("\n\n Tugas");
		printf("\n8. Bala bantuan");
		printf("\n0. Exit");
		printf("\n>> : ");scanf("%d",&menu);
		
		switch(menu){
			
			case 1:
				inputkode:
				printf("\nKode cabang : ");fflush(stdin);gets(kodeCabang);
				if(strcmpi(kodeCabang,"")==0){
					goto inputkode;
				}
				inputnegara:
				printf("\nNama negara : ");fflush(stdin);gets(negara);
				if(strcmpi(negara,"")==0){
					goto inputnegara;
				}
				cabang=makeCabang(kodeCabang,negara);
				insertLastParent(&L,cabang);
				break;
			case 2:
				if(isEmpty(L)){
					printf("\nBUAT CABANG TERLEBIH DAHULU");
					break;
				}
				inputnegara2:
				printf("Nama negara: ");fflush(stdin);gets(negara);
				if(strcmpi(negara,"")==0){
					goto inputnegara2;
				}
				printCabang(L,negara);
				break;
			case 3:
				if(isEmpty(L)){
					printf("\nBUAT CABANG TERLEBIH DAHULU");
					break;
				}
				inputkode3:
				printf("\nKode Cabang yang ditambahkan anggotanya : ");fflush(stdin);gets(kodeCabang);
				if(strcmpi(kodeCabang,"")==0){
					goto inputkode3;
				}
				inputid3:
					printf("\nid anggota : ");fflush(stdin);gets(id);
				if(strcmpi(id,"")==0){
					goto inputid3;
				}
				inputanggota3:
				printf("\nnama anggota : ");fflush(stdin);gets(nama);	
				if(strcmpi(id,"")==0){
					goto inputanggota3;
				}
				anggota=makeAnggota(id,nama);
				insertLastChild(&L,kodeCabang,anggota);
				break;
			case 4:
				if(isEmpty(L)){
					printf("BUAT CABANG TERLEBIH DAHULU");
					break;
				}
				inputkode4:
				printf("\nKode Cabang yang dihapus anggotanya : ");fflush(stdin);gets(kodeCabang);	
				if(strcmpi(kodeCabang,"")==0){
					goto inputkode4;
				}
				deleteLastChild(&L,kodeCabang);
				break;
			case 5:
				if(isEmpty(L)){
					printf("BUAT CABANG TERLEBIH DAHULU");
					break;
				}
				printAll(L);
				break;
			case 6:
				if(isEmpty(L)){
					printf("BUAT CABANG TERLEBIH DAHULU");
					break;
				}
				inputcabang6:
					printf("\nKode Cabang yang dibubarkan : ");fflush(stdin);gets(kodeCabang);
				if(strlen(kodeCabang)==0){
					goto inputcabang6;
				}
				deleteCabang(&L,kodeCabang);
				break;
			case 7:
				if(isEmpty(L)){
					printf("BUAT CABANG TERLEBIH DAHULU");
					break;
				}
				inputid6:
					printf("\nid anggota : ");fflush(stdin);gets(id);
				if(strlen(id)==0){
					goto inputid6;
				}
				printAnggota(L,id);
				break;
			case 8:
				if(isEmpty(L)){
					printf("BUAT CABANG TERLEBIH DAHULU");
					break;
				}
				kode1:
				printf("\nKode cabang yang memberikan : ");fflush(stdin);gets(kode1);
				if(strlen(kode1)==0){
					goto kode1;
				}
				kode2:
				printf("\nKode cabang yang menerima : ");fflush(stdin);gets(kode2);
				if(strlen(kode2)==0){
					goto kode2;
				}
				cek1= cekKode(L,kode1);
				cek2= cekKode(L,kode2);
				if(cek1==NULL||cek2==NULL){
					printf("\nSALAH SATU CABANG TIDAK ADA");
					break;
				}
				if(!HaveChild(cek1)){
					printf("\nPEMBERI TIDAK PUNYA ANGGOTA");
					break;
				}
				transfer(&L,cek1,cek2);
				break;
			case 0:
				printf("\nPaulus Pandu Windito-200710755");
				return 0;		
		}getch();
	}while(menu!=0);
	
	return 0;
}