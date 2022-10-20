#include "header.h"


int main(int argc, char *argv[]) {
	List L;
	Data D,X;
	int menu,indikator,gen,cek,down,per,ketua=0;
	float nilai;
	string npm,nama,peran,gender,opsi;
	
	createEmpty(&L);

	do{
		system("cls");
		printf("Kelompok Belajar Jaya-Bonus 1&3");
		printf("\n [1] Tambah Anggota");
		printf("\n [2] Masukan Anggota");
		printf("\n [3] Tampil Seluruh Anggota");
		printf("\n [4] Hapus Anggota");
		printf("\n [5] Hapus Anggota by Gender(Bonus)");
		printf("\n [6] Tambah Anggota++(Bonus)");
		printf("\n [0] Keluar");
		printf("\n\nPilih Menu : ");scanf("%d",&menu);
		
		switch(menu){
			case 1:
				if(down==1){
					printf("Menu Reguler Sudah Tidak Dapat Diakses !");
					break;
				}
				if(indikator!=0){
					printf("Data belum dimasukan ke kelompok !");
					break;
				}
				
				strcpy(npm,"");
				strcpy(nama,npm);
				strcpy(gender,npm);
				strcpy(peran,npm);
				nilai=0;
				while(strcmp(npm,"")==0){
					printf("\nMasukkan NPM\t: ");fflush(stdin);gets(npm);
					if(strcmp(npm,"")==0){
						printf("\nNPM tidak boleh kosong!\n");
					}
					cek=cekNpm(npm,L);
					if(cek==-1){
						printf("\nNPM sudah dipakai!\n");
						strcpy(npm,"");
					}
				}
				while(strcmp(nama,"")==0){
					printf("\nMasukkan Nama\t: ");fflush(stdin);gets(nama);
					if(strcmp(nama,"")==0){
						printf("\nNama tidak boleh kosong!\n");
					}
				}

				while(strcmp(gender,"")==0){
					printf("\nMasukkan gender\t: ");fflush(stdin);gets(gender);
					
					gen=cekGender(gender);
					if(gen==3){
						printf("\nGender tidak ditemukan\n");
						strcpy(gender,"");
					}
				}
				
				while(strcmp(peran,"")==0){
					printf("\nMasukkan peran\t: ");fflush(stdin);gets(peran);
					if(strcmp(peran,"")==0){
						printf("Peran tidak boleh kosong!\n");
					}
		
				}
				while(nilai==0){
					printf("\nMasukkan nilai\t: ");scanf("%f",&nilai);
					if(nilai<0||nilai>100){
						printf("\nRange nilai hanya 0-100\n");
						nilai=0;
					}

				}
				D= makeData(npm,nama,gender,peran,nilai);
				printf("\nData berhasil dibuat");
				indikator=1;
				break;
			case 2:
				if(down==1){
					printf("Menu Reguler Sudah Tidak Dapat Diakses !");
					break;
				}
				if(indikator==0){
					printf("Data Anggota Baru Tidak Ditemukan !");
					break;
				}
				if(gen==1){
					insertFirst(&L,D);
				}else{
					insertLast(&L,D);
				}
				indikator=0;
				break;
			case 3:
				showList(L);
				break;
			case 4:
				if(isEmpty(L)){
					printf("\n[!] Kelompok Masih Kosong [!]\n");
					break;
				}
				strcpy(opsi,"");
				while(strcmpi(opsi,"")==0){
					printf("\nHapus Pertama/Terakhir: ");fflush(stdin);gets(opsi);
					if(strcmpi(opsi,"pertama")==0){
						deleteFirst(&L);
					}
					if(strcmpi(opsi,"terakhir")==0){
						deleteLast(&L);
					}
					if(strcmpi(opsi,"pertama")!=0&&strcmpi(opsi,"terakhir")!=0){
						printf("\nHanya Bisa Hapus Pertama atau Terkahir !");
						strcpy(opsi,"");
					}
				}
				
				break;
			case 5:
				if(isEmpty(L)){
					printf("\n[!] Kelompok Masih Kosong [!]\n");
					break;
				}
				strcpy(gender,"");
				while(strcmp(gender,"")==0){
					printf("\nGender Mahasiswa\t: ");fflush(stdin);gets(gender);
					
					gen=cekGender(gender);
					if(gen==3){
						printf("\nGender tidak ditemukan\n");
						strcpy(gender,"");
					}
				}
				deleteGender(&L,gender);
				break;
			case 6:
				down=1;
				strcpy(npm,"");
				strcpy(nama,npm);
				strcpy(gender,npm);
				strcpy(peran,npm);
				nilai=0;
				while(strcmp(npm,"")==0){
					printf("\nMasukkan NPM\t: ");fflush(stdin);gets(npm);
					if(strcmp(npm,"")==0){
						printf("\nNPM tidak boleh kosong!\n");
					}
					cek=cekNpm(npm,L);
					if(cek==-1){
						printf("\nNPM sudah dipakai!\n");
						strcpy(npm,"");
					}
				}
				while(strcmp(nama,"")==0){
					printf("\nMasukkan Nama\t: ");fflush(stdin);gets(nama);
					if(strcmp(nama,"")==0){
						printf("\nNama tidak boleh kosong!\n");
					}
				}

				while(strcmp(gender,"")==0){
					printf("\nMasukkan gender\t: ");fflush(stdin);gets(gender);
					
					gen=cekGender(gender);
					if(gen==3){
						printf("\nGender tidak ditemukan\n");
						strcpy(gender,"");
					}
				}
				
				while(strcmp(peran,"")==0){
					printf("\nMasukkan peran\t: ");fflush(stdin);gets(peran);
					if(strcmp(peran,"")==0){
						printf("Peran tidak boleh kosong!\n");
					}
					per=cekPeran(peran);
					if(per==3){
						printf("Peran tidak ditemukan");
						strcpy(peran,"");
					}
				}
				while(nilai==0){
					printf("\nMasukkan nilai\t: ");scanf("%f",&nilai);
					if(nilai<0||nilai>100){
						printf("\nRange nilai hanya 0-100\n");
						nilai=0;
					}

				}
				if(ketua==1&&per==1){
					printf("\nKetua Sudah Ada !");
					printf("\nAnggota Baru Gagal Ditambahakan");
					break;
				}else{
					D= makeData(npm,nama,gender,peran,nilai);
					if(per==1){
						ketua=1;
						insertFirst(&L,D);
					}else{
						if(gen==1){
							if(ketua!=1){
								insertFirst(&L,D);
							}else{
								X=makeData(L.first->D.npm,L.first->D.nama,L.first->D.gender,L.first->D.peran,L.first->D.nilai);
								deleteFirst2(&L);
								insertFirst2(&L,D);
								insertFirst(&L,X);
							}		
						}
						if(gen==2){
						insertLast(&L,D);
						}
					} 
					printf("\nAnggota Baru Berhasil Ditambahakan");
				}
				
				
				break;
			case 0:
				printf("E-Paulus Pandu Windito-200710755");
				break;
			default:
				printf("\n\t[!] Menu tidak ada [!]\n");
				break;
		}
		getch();
	}while(menu!=0);
	return 0;
}