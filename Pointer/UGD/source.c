#include "header.h"

Penumpang make_penumpang(int id, string nama, string gender,int umur){
    Penumpang P;

    P.id=id;
    strcpy(P.nama,nama);
    strcpy(P.gender,gender);
    P.umur=umur;

    return P;
}

void init_pesawat(Pesawat *P){
    Penumpang *pKiiri, *pKanan; //deklarasi pointer untuk seat di sisi kiri dan kanan
    int i, j;
    int id_seat_kiri=1, id_seat_kanan=16;

    // inisialisasi pointer untuk masing-masing sisi
    pKiiri=&P->Kiri[0][0];
    pKanan=&P->Kanan[0][0];
    

    for(j=0;j<Y;j++){
        for(i=0;i<X;i++){
            *pKiiri = make_penumpang(id_seat_kiri,"-","-",0);
            *pKanan = make_penumpang(id_seat_kanan,"-","-",0);
            
            pKiiri++;
            pKanan++;
            
            id_seat_kiri++;
            id_seat_kanan++;
        }
    }
    
}

void cetak_pesawat(Pesawat P){
    Penumpang *pKiiri, *pKanan;

    pKiiri=&P.Kiri[0][0];
    pKanan=&P.Kanan[0][0];

    int i, j;
    printf("\n\t\t Seat Pesawat \n");
    for(j=0;j<Y;j++){
        for(i=0;i<X;i++){
            printf("[ %d-%s ] ",pKiiri->id, pKiiri->nama);
            *pKiiri++;
        }  
        printf("\t"); 
        for(i=0;i<X;i++){
            printf("[ %d-%s ] ",pKanan->id, pKanan->nama);
            *pKanan++;
        }
        printf("\n");   
    }
}

void info(Penumpang *k){
	
	printf("--------PesawatKita--------");
	printf("\n\nd: %d",k->id);
	printf("\nnama: %s",k->nama);
	printf("\ngender: %s",k->gender);
	printf("\numur: %d",k->umur);
	printf("\n------------------------");
}

void seat(){
	printf("---Pilih Seat--");
	printf("\n\t1. geser kiri");
	printf("\n\t2. geser kanan");
	printf("\n\t3. geser atas");
	printf("\n\t4. geser bawah");
}


void initTambahan(Pesawat *P){
	Penumpang *pKiiri, *pKanan; //deklarasi pointer untuk seat di sisi kiri dan kanan
    int i, j;
    int id_seat_kiri=1, id_seat_kanan=16;

    // inisialisasi pointer untuk masing-masing sisi
    pKiiri=&P->Kiri[0][0];
    pKanan=&P->Kanan[0][0];
    

    for(j=0;j<Y;j++){
        for(i=0;i<X;i++){
            *pKiiri = make_penumpang(id_seat_kiri,"-","-",0);
            *pKanan = make_penumpang(id_seat_kanan,"-","-",0);
            
            pKiiri++;
            pKanan++;
            
            id_seat_kiri++;
            id_seat_kanan++;
        }
    }
    
}