#include "header.h"

int main(int argc, char const *argv[]){
    Pesawat P;
    Penumpang *ptrDisplay,temp,*kiri,*bawah,*kanan,*atas;
	int menu,menuSeat,umur,down,i,j;
	string nama,gender,opsi;
	
    init_pesawat(&P); 
    
    ptrDisplay = &P.Kiri[0][0];
	 

    do{
    system("cls");
    info(ptrDisplay);
    cetak_pesawat(P);

    printf("\n-----------Menu---------");
    printf("\n[1]. Pilih Seat");
    printf("\n[2]. Input Data");
    printf("\n[3]. Ubah Data");
    printf("\n[4]. Hapus Data");
    printf("\n[5]. Input Social-distancing[Tugas]");
    printf("\n[0]. Exit");
    printf("\nMasukan pilihan menu: >> ");scanf("%d",&menu);
    
    switch(menu){
    	default:
    		printf("menu tidak ditemukan!");
    		getch();
    		break;
    	case 1:
    		seat();
    		printf("\n\tMasukan pilihan menu: >> ");scanf("%d",&menuSeat);
    		if(menuSeat==1){
				if(ptrDisplay==&P.Kiri[0][0]){
					printf("mentok");
				}else if(ptrDisplay==&P.Kiri[1][0]){
					ptrDisplay=&P.Kanan[0][2];
				}else if(ptrDisplay==&P.Kiri[2][0]){
					ptrDisplay=&P.Kanan[1][2];
				}else if(ptrDisplay==&P.Kiri[3][0]){
					ptrDisplay=&P.Kanan[2][2];
				}else if(ptrDisplay==&P.Kiri[4][0]){
					ptrDisplay=&P.Kanan[3][2];
				}else if(ptrDisplay==&P.Kanan[0][0]){
					ptrDisplay=&P.Kiri[0][2];
				}else if(ptrDisplay==&P.Kanan[1][0]){
					ptrDisplay=&P.Kiri[1][2];
				}else if(ptrDisplay==&P.Kanan[2][0]){
					ptrDisplay=&P.Kiri[2][2];
				}else if(ptrDisplay==&P.Kanan[3][0]){
					ptrDisplay=&P.Kiri[3][2];
				}else if(ptrDisplay==&P.Kanan[4][0]){
					ptrDisplay=&P.Kiri[4][2];
				}else{
					ptrDisplay--;
				}
			}else if(menuSeat==2){
				if(ptrDisplay==&P.Kanan[4][2]){
					printf("mentok");
				}else if(ptrDisplay==&P.Kiri[0][2]){
					ptrDisplay=&P.Kanan[0][0];
				}else if(ptrDisplay==&P.Kiri[1][2]){
					ptrDisplay=&P.Kanan[1][0];
				}else if(ptrDisplay==&P.Kiri[2][2]){
					ptrDisplay=&P.Kanan[2][0];
				}else if(ptrDisplay==&P.Kiri[3][2]){
					ptrDisplay=&P.Kanan[3][0];
				}else if(ptrDisplay==&P.Kiri[4][2]){
					ptrDisplay=&P.Kanan[4][0];
				}else if(ptrDisplay==&P.Kanan[0][2]){
					ptrDisplay=&P.Kiri[1][0];
				}else if(ptrDisplay==&P.Kanan[1][2]){
					ptrDisplay=&P.Kiri[2][0];
				}else if(ptrDisplay==&P.Kanan[2][2]){
					ptrDisplay=&P.Kiri[3][0];
				}else if(ptrDisplay==&P.Kanan[3][2]){
					ptrDisplay=&P.Kiri[4][0];
				}else{
					ptrDisplay++;
				}
			}else if(menuSeat==3){
				if(ptrDisplay==&P.Kanan[0][2]||ptrDisplay==&P.Kanan[0][1]||ptrDisplay==&P.Kanan[0][0]||ptrDisplay==&P.Kiri[0][0]||ptrDisplay==&P.Kiri[0][1]||ptrDisplay==&P.Kiri[0][2]){
					printf("mentok");
					getch();
					break;
				}else{
					ptrDisplay=ptrDisplay-3;
				}
			}else if(menuSeat==4){
				if(ptrDisplay==&P.Kanan[4][1]||ptrDisplay==&P.Kanan[4][2]||ptrDisplay==&P.Kanan[4][0]||ptrDisplay==&P.Kiri[4][0]||ptrDisplay==&P.Kiri[4][1]||ptrDisplay==&P.Kiri[4][2]){
					printf("mentok");
					getch();
					break;
				}else{
					ptrDisplay=ptrDisplay+3;
				}
			}else{
				printf("\npilihan tidak ada!");
			}
    		getch();
    		break;
    	case 2:
    		if(strcmpi(ptrDisplay->nama,"-")!=0){
    			printf("Seat ini sudah ditempati. Silahkan pilih seat lain!");
    			getch();
    			break;
    		}
    		if(down!=1){	
						printf("---Input Data---");
		    		printf("\nMasukan nama: ");fflush(stdin);gets(nama);
		    		printf("Masukan gender: ");fflush(stdin);gets(gender);
		    		printf("Masukan umur:");scanf("%d",&umur);
		    		temp = make_penumpang(ptrDisplay->id,nama,gender,umur);
					*ptrDisplay = temp;
				}else{
				printf("Sedang PPKM, silahkan input data di menu 5");
			}
    		getch();
    		break;
    	case 3:
    		printf("---Ubah Data---");
    		printf("\nMasukan nama: ");fflush(stdin);gets(nama);
    		printf("Masukan gender: ");fflush(stdin);gets(gender);
    		printf("Masukan umur:");scanf("%d",&umur);
    		temp = make_penumpang(ptrDisplay->id,nama,gender,umur);
			*ptrDisplay = temp;
    		break;
    	case 4:
    		temp = make_penumpang(ptrDisplay->id,"-","-",0);
			*ptrDisplay = temp;
    		printf("Data berhasil dihapus!");
    		getch();
    		break;
    	case 5:
    		if(down!=1){
    			printf("menu ini akan mereset semua data!");
	    		printf("\nmenu input[2] tidak dapat digunakan setelah anda mengakses menu ini!");
	    		printf("\nYakin ingin melanjutkan? [yes/no]");
	    		fflush(stdin);gets(opsi);
	    		if(strcmpi(opsi,"yes")==0){ 
	    			initTambahan(&P);
	    			printf("---Input Data---");
	    			printf("\nMasukan nama: ");fflush(stdin);gets(nama);
	    			printf("Masukan gender: ");fflush(stdin);gets(gender);
	    			printf("Masukan umur:");scanf("%d",&umur);
	    			temp = make_penumpang(ptrDisplay->id,nama,gender,umur);
					*ptrDisplay = temp;
	    			down=1;
	    			getch();
	    			break;
	    			
				}else {
					printf("[Warning].. Perhatikan jarak dengan penumpang lain");
					getch();
					break;
				}
			}else{
				if(strcmpi(ptrDisplay->nama,"-")!=0){
    			printf("Seat ini sudah ditempati. Silahkan pilih seat lain!");
    			getch();
    			break;
				}else{
					for(i=0;i<Y;i++){
						if(i==0){
							for(j=0;j<X;j++){
								if(ptrDisplay==&P.Kiri[0][0]){
									if(strcmpi(&P.Kiri[i][j+1].nama,"-")!=0||strcmpi(&P.Kiri[i+1][j].nama,"-")!=0){
									goto error;
									}else{
										goto input;
									}
									
								}else if(ptrDisplay==&P.Kiri[0][j]){
									if(strcmpi(&P.Kiri[i][j+1].nama,"-")!=0||strcmpi(&P.Kiri[i][j-1].nama,"-")!=0||strcmpi(&P.Kiri[i+1][j].nama,"-")!=0){
									goto error;
									}else{
										
										goto input;
									}
								}else if(ptrDisplay==&P.Kanan[0][2]){
									if(strcmpi(&P.Kanan[i][1].nama,"-")!=0||strcmpi(&P.Kanan[i+1][j].nama,"-")!=0){
									goto error;
									}else{
										goto input;
									}
								}else if(ptrDisplay==&P.Kanan[0][j]){
									if(strcmpi(&P.Kanan[i][j+1].nama,"-")!=0||strcmpi(&P.Kanan[i][j-1].nama,"-")!=0||strcmpi(&P.Kanan[i+1][j].nama,"-")!=0){
									goto error;
									}else{
										goto input;
									}
								}
							}
						}else if(i==4){
							if(ptrDisplay==&P.Kiri[4][0]){
									if(strcmpi(&P.Kiri[i][j+1].nama,"-")!=0||strcmpi(&P.Kiri[i-1][j].nama,"-")!=0){
									goto error;
									}else{
										goto input;
									}
								}else if(ptrDisplay==&P.Kiri[4][j]){
									if(strcmpi(&P.Kiri[i][j+1].nama,"-")!=0||strcmpi(&P.Kiri[i][j-1].nama,"-")!=0||strcmpi(&P.Kiri[i-1][j].nama,"-")!=0){
									goto error;
									}else{
										goto input;
									}
								}else if(ptrDisplay==&P.Kanan[4][2]){
									if(strcmpi(&P.Kanan[i][j-1].nama,"-")!=0||strcmpi(&P.Kanan[i-1][j].nama,"-")!=0){
									goto error;
									}else{
										goto input;
									}
								}else if(ptrDisplay==&P.Kanan[4][j]){
									if(strcmpi(&P.Kanan[i][j+1].nama,"-")!=0||strcmpi(&P.Kanan[i][j-1].nama,"-")!=0||strcmpi(&P.Kanan[i-1][j].nama,"-")!=0){
									goto error;
									}else{
										goto input;
									}
								}
						}else{
							for(j=0;j<X;j++){
								if(j==0){
									if(ptrDisplay==&P.Kiri[i][0]){
										if(strcmpi(&P.Kiri[i-1][0].nama,"-")!=0||strcmpi(&P.Kiri[i+1][1].nama,"-")!=0){
											goto error;
										}
										break;
									}
								}else if(j==2){
									kiri:
									if(ptrDisplay==&P.Kanan[i][2]){
										if(strcmpi(&P.Kanan[i-1][2].nama,"-")!=0||strcmpi(&P.Kanan[i+1][2].nama,"-")!=0||strcmpi(&P.Kanan[i][1].nama,"-")!=0){
											goto error;
										}
										break;
									}
								}else if(ptrDisplay==&P.Kiri[i][j]){
									if(strcmpi(&P.Kiri[i][j+1].nama,"-")!=0||strcmpi(&P.Kiri[i][j-1].nama,"-")!=0||strcmpi(&P.Kiri[i+1][j].nama,"-")!=0||strcmpi(&P.Kiri[i-1][j].nama,"-")!=0){
									goto error;
									}
									goto input;
								}else if(ptrDisplay==&P.Kanan[i][j]){
									if(strcmpi(&P.Kanan[i][j+1].nama,"-")!=0||strcmpi(&P.Kanan[i][j-1].nama,"-")!=0||strcmpi(&P.Kanan[i+1][j].nama,"-")!=0||strcmpi(&P.Kanan[i-1][j].nama,"-")!=0){
									goto error;
									}
									goto input;
								}
							}
						}

						}
					}
	
				}
				input:
				printf("---Input Data---");
				printf("\nMasukan nama: ");fflush(stdin);gets(nama);
				printf("Masukan gender: ");fflush(stdin);gets(gender);
				printf("Masukan umur:");scanf("%d",&umur);
				temp = make_penumpang(ptrDisplay->id,nama,gender,umur);
				*ptrDisplay = temp;
				getch();
				break;
				
			error:
					printf("[Warning].. Perhatikan jarak dengan penumpang lain!");
					getch();
					break;
		
			
    			
    	case 0:
    		printf("saya Paulus Pandu Windito-200710755 mengerjakan UGD dengan jujur!");
    		getch();
    		break;
	}
	}while(menu!=0);
	

    return 0;
}