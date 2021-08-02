#ifndef FIFO_HEADER
#define FIFO_HEADER
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct Simpul{
    char kode[6];
    char nama[21];
    float piutang;
    struct Simpul *Berikut; //point to member of simpul 
};
typedef struct Simpul simpul_Lgn;
char jawab;
void menu(short int*);
void buatBaru();
void tambahNode();
void tampilkanNode();
void tampilkanDaftar(simpul_Lgn*,int );
void hapusNode();
simpul_Lgn *cari_Node(char*);
simpul_Lgn *simpulAwal=NULL;
simpul_Lgn *simpulAkhir=NULL;
simpul_Lgn *simpulCari=NULL;
void callSwicthMenu();
#endif
