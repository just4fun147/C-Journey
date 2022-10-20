#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#define X 3
#define Y 5

typedef char string[50];

typedef struct{
    int id;
    string nama;
    string gender;
    int umur;
}Penumpang;

typedef Penumpang Seat[Y][X];

typedef struct{
    Seat Kiri;
    Seat Kanan;
}Pesawat;

Penumpang make_penumpang(int id, string nama, string gender,int umur);
void init_pesawat(Pesawat *P); 
void initTambahan(Pesawat *P); 
void cetak_pesawat(Pesawat P);
void info(Penumpang *k);
void seat();
void plus(Penumpang *k);

