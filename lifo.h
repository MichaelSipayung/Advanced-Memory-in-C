#ifndef LIFO_HEADER
#define LIFO_HEADER
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct Simpul{
    char kode[6];
    char nama[21];
    float piutang;
    struct Simpul *Berikut;
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
simpul_Lgn *simpulAkhir=NULL;
simpul_Lgn *simpulCari=NULL;
void callSwicthMenu();
#endif
