#include "header.h"

int main(int argc, char *argv[]) {
	Matriks Mat;
	int pil,cek=0;
	int idKamar,jangkaSewa;
	string tipeKamar,nama,no;
	Kamar a;	
	int i,j,k;
	int kamarIsi=0;
	

	menu:
	system("cls");
	printf("=== Pendataan Kamar Kos ===");
	printf("\n1. Inisialisasi ");
	printf("\n2. Input Data ");
	printf("\n3. Tampil Data ");
	printf("\n0. Exit ");
	printf("\n\nMenu Tugas");
	printf("\n4. Input Data ");
	printf("\n5. Edit Data ");
	printf("\n6. Hapus Data ");
	printf("\n7. Hitung Sewa ");
	printf("\n>>>");scanf("%d",&pil);
	
	switch(pil){
		case 1:
			init(&Mat);
			printf("\n[V]Berhasi Inisialisasi");
			cek=1;
			getch();
			goto menu;
			
		case 2:
			if(cek==0){
				printf("\n[!] Inisialisasi terlebih dahulu ");
				getch();
				goto menu;
			}
			printf("\n[Data Kamar]");
			printf("\nTipe :");fflush(stdin);gets(tipeKamar);
			i = cekTipe(tipeKamar);
			if(i==4){
				printf("[!] Tipe tidak tersedia");
				goto inputTipe;
			}
			printf("\nID :");scanf("%d", &idKamar);
			j = cekID(idKamar, i);
			if(j==0){
					printf("\n[!] Maaf ID kamar tersebut bukanlah tipe Super %s", tipeKamar);
					printf("\n[!] Super Eksklusif : 1-3 | Eksklusif : 4-6 | Regular : 7-9");
					goto inputID;							
			}
			printf("\n[Data Penyewa]");
			printf("\nNama : ");fflush(stdin);gets(nama);
			printf("\nNomor Telepon : ");fflush(stdin);gets(no);		
			printf("\nJangka Sewa : ");scanf("%d", &jangkaSewa);
			Mat[i][j-1] = inputKamar(idKamar, tipeKamar, nama, no, jangkaSewa);

			printf("Berhasil input data");
			kamarIsi++;
			getch();
			goto menu;
		case 3:
			if(cek==0){
				printf("\n[!] Inisialisasi terlebih dahulu!");
				getch();
				goto menu;
			}
			tampilMatriks(Mat);
			getch();
			goto menu;
		case 0:
			printf("\nDikerjakan oleh Paulus Pandu Windito/200710755");
			return 0;
			
		case 4:
			if(cek==0){
				printf("\n[!] Inisialisasi terlebih dahulu ");
				getch();
				goto menu;
			}
			if(kamarIsi==9){
				printf("Semua kamar sudah penuh !");
				getch();
				goto menu;
			}
			printf("\n[Data Kamar]");
			
			inputTipe:
			printf("\nTipe :");fflush(stdin);gets(tipeKamar);
			i = cekTipe(tipeKamar);
			if(i==4){
				printf("[!] Tipe tidak tersedia");
				goto inputTipe;
			}
			
			
			inputID:
			printf("\nID :");scanf("%d", &idKamar);
			j = cekID(idKamar, i);
			
			if(j==0){
					printf("\n[!] Maaf ID kamar tersebut bukanlah tipe Super %s", tipeKamar);
					printf("\n[!] Super Eksklusif : 1-3 | Eksklusif : 4-6 | Regular : 7-9");
					goto inputID;							
			}
			k = cekKosong(i,j,Mat);
			if(k==3){
				printf("Maaf kamar sudah terisi !");
				getch();
				goto menu;
			}

			printf("\n[Data Penyewa]");
			inputNama:
			printf("\nNama : ");fflush(stdin);gets(nama);
			if(strcmpi(nama,"-")==0||strlen(nama)<=0){
				printf("[!] Nama Tidak Boleh Kosong");
				goto inputNama;
			}
			if(cekNama(nama,Mat)==1){
				printf("Nama sudah terdaftar");
				goto inputNama;
			}
			inputNo:
			printf("\nNomor Telepon : ");fflush(stdin);gets(no);
			if(strcmpi(no,"-")==0||strlen(no)<=0){
				printf("[!] No Tidak Boleh Kosong");
				goto inputNo;
			}		
			inputSewa:
			printf("\nJangka Sewa : ");scanf("%d", &jangkaSewa);
			if(jangkaSewa<=0){
				printf("Silahkan input lebih dari 0");
				goto inputSewa;
			}
			
			Mat[i][j-1] = inputKamar(idKamar, tipeKamar, nama, no, jangkaSewa);

			printf("Berhasil input data");
			kamarIsi++;
			getch();
			goto menu;
			
		case 5:
			if(kamarIsi==0){
				printf("Semua kamar masih kosong !");
				getch();
				goto menu;
			}
			inputNama2:
			printf("\nNama : ");fflush(stdin);gets(nama);
			if(strcmpi(nama,"-")==0||strlen(nama)<=0){
				printf("[!] Nama Tidak Boleh Kosong");
				goto inputNama2;
			}
			if(cekNama(nama,Mat)!=1){
				printf("Nama tidak ada");
				goto menu;
			}
			i=cariI(nama,Mat);
			j=cariJ(nama,Mat);
			show(i,j,Mat);
			printf("\n\n[Data Penyewa Baru]");
			inputNama3:
			printf("\nNama : ");fflush(stdin);gets(nama);
				if(strcmpi(nama,"-")==0||strlen(nama)<=0){
					printf("[!] Nama Tidak Boleh Kosong");
					goto inputNama3;
				}
				if(cekNama(nama,Mat)==1){
					printf("Nama sudah terdaftar");
					goto inputNama3;
				}
			inputNo3:
			printf("\nNomor Telepon : ");fflush(stdin);gets(no);
				if(strcmpi(no,"-")==0||strlen(no)<=0){
					printf("[!] No Tidak Boleh Kosong");
					goto inputNo3;
				}		
			inputSewa3:
			printf("\nJangka Sewa : ");scanf("%d", &jangkaSewa);
				if(jangkaSewa<=0){
					printf("Silahkan input lebih dari 0");
					goto inputSewa3;
				}
				
			editKamar(nama,no,jangkaSewa,&Mat,i,j);
			printf("Berhasil ubah data");
			getch();
			goto menu;
		
		case 6:
			if(kamarIsi==0){
				printf("Semua kamar masih kosong !");
				getch();
				goto menu;
			}
			printf("\nNama : ");fflush(stdin);gets(nama);
			if(strcmpi(nama,"-")==0||strlen(nama)<=0){
				printf("[!] Nama Tidak Boleh Kosong");
				goto menu;
			}
			if(cekNama(nama,Mat)!=1){
				printf("Nama tidak ada");
				getch();
				goto menu;
			}
			i=cariI(nama,Mat);
			j=cariJ(nama,Mat);
			tampilSebagian(i,j,Mat);
			printf("\n\n[V] Berhasil hapus data penyewa.");
			Mat[i][j] = inputKamar(0,"-","-","-",0);
			kamarIsi--;
			getch();
			goto menu;
		case 7:
			if(kamarIsi==0){
				printf("Semua kamar masih kosong !");
				getch();
				goto menu;
			}
			printf("\nNama : ");fflush(stdin);gets(nama);
			if(strcmpi(nama,"-")==0||strlen(nama)<=0){
				printf("[!] Nama Tidak Boleh Kosong");
				goto menu;
			}
			if(cekNama(nama,Mat)!=1){
				printf("Nama tidak ada");
				getch();
				goto menu;
			}
			i=cariI(nama,Mat);
			j=cariJ(nama,Mat);
			tampilSebagian(i,j,Mat);
			printf("\n--------------------------------------");
			printf("\n\nBiaya Sewa : Rp %.0f,-",biayaSewa(Mat,i,j));
			getch();
			goto menu;
		default:
			getch();
			goto menu;
	}
	return 0;
}