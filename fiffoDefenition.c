#ifndef FIFO_DECLARAION
#define FIFO_DECLARAION
#include "fifo.h"
void menu(short int*pilih){
    //clrscr();
    printf("\t<<< Menu Utama >>>\n");
    printf("1.Membuat daftar berkait baru\n");
    printf("2.Membuat Node baru\n");
    printf("3.Menampilkan isi suatu node\n");
    printf("4.Menghapus suatu Node\n");
    printf("5.Menampilkan isi daftar berkait\n");
    printf("0.SELESAI\n");
    do
    {
        printf("Pilih Nomor (0-5) ?");scanf("%d",pilih);
        if (*pilih<0||*pilih>5)
        {
            printf("\7");
        }
    } while (*pilih<0||*pilih>5);    
    printf("\n\n");
}
void buatBaru(){
    if (simpulAwal)//test whether the linked list isn't null.. another word it's contain a value 
    {
        printf("Daftar berkait sudah berisi\n");
        do
        {
            printf("Akan dihapus (Y/T) ?");
            jawab=getche();
        } while (!(jawab=='y'||jawab=='Y'||jawab=='t'||jawab=='T'));
        if (jawab=='T'||jawab=='t')
        {
            return;
        }
    }
   simpulAwal=NULL;//free all linnk .. make linked list has no point to other  
   printf("\nSudah dihapus\n");
}
void tambahNode(){
    simpul_Lgn *simpulBaru;//save the current address
    float piutLgn;
    simpulBaru= malloc(sizeof(simpul_Lgn));
    if (simpulBaru==NULL)
    {
        printf("Fail to allocate the memory\n");
    }
    else{
        printf("Kode langganan ?");
        do
        {
            gets(simpulBaru->kode);
        } while (strlen(simpulBaru->kode)==0);
        printf("Nama langganan\t ?");gets(simpulBaru->nama);
        printf("Nilai Piutang\t ?");scanf("%f",&piutLgn);
        simpulBaru->piutang=piutLgn;
        simpulBaru->Berikut=NULL;
        if (simpulAwal==NULL)
        {
            simpulAwal=simpulBaru;//masukan node pertama 
        }
        else{
            simpulAkhir->Berikut=simpulBaru;
        }
        simpulAkhir=simpulBaru;
        
        do
        {
            printf("Masukan data lagi (Y/T) ?");
            jawab=getche();
        } while (!(jawab=='y'||jawab=='t'||jawab=='Y'||jawab=='T'));
        if (jawab=='Y'||jawab=='y')
        {
            printf("\n\n");
            tambahNode();   
        }
    }
}
simpul_Lgn *cari_Node(char*kodeLgn){
    simpul_Lgn *simpulSb=NULL;
    while ((simpulCari!=NULL)&&(strcmp(kodeLgn,simpulCari->kode)!=0))
    {
        if (strcmp(kodeLgn,simpulCari->kode)!=0)
        {
            simpulSb=simpulCari;
            simpulCari=simpulCari->Berikut;
        }
    }
    return(simpulSb);
}
void tampilkanNode(){
    char kodeLgn[6];
    printf("Kode Langganan ? ");scanf("%s",kodeLgn);
    simpulCari=simpulAwal;
    cari_Node(kodeLgn);
    if (simpulCari==NULL)
    {
        printf("Data ini tidak ada!!!\n");
    }
    else{
        printf("Nama langganan\t: %s\n", simpulCari->nama);
        printf("Nilai piutang\t: Rp%9.2f\n", simpulCari->piutang);
    }
}
void tampilkanDaftar(simpul_Lgn*simpulIni,int n ){
    if (simpulAwal==NULL)
    {
        printf("DAFTAR BERKAIT TIDAK BERISI\n");
    }
    if (n<=1&&simpulAwal!=NULL)
    {
        printf("-------------------------------\n");
        printf("No.Urut\tKode\tNama\tPiutang\n");
        printf("-------------------------------\n");
    }
    if (simpulIni!=NULL)
    {
        printf("%05d%-6s%-20s%9.2f\n",n,simpulIni->kode,simpulIni->nama,simpulIni->piutang);
        tampilkanDaftar(simpulIni->Berikut,n+1);//recursive call for the next list, next list is one pastb the current list
    }
}
void hapusNode(){
    simpul_Lgn *simpulSebelum;
    char kodeLgn[6];
    printf("Kode Langganan ?");scanf("%s",kodeLgn);
    simpulCari=simpulAwal;
    simpulSebelum=cari_Node(kodeLgn);
    if (simpulCari==NULL)
    {
        printf("Data Tidak ada\n");
    }
    else{
        printf("Nama langganan\t: %s\n",simpulCari->nama);
        printf("Nilai Piutang\t: Rp%9.2f\n",simpulCari->piutang);
        printf("\n");
        do
        {
            printf("Are you sure that this link will deleted (y/t) ?");
            jawab=getche();
            printf("\n");
        } while (!(jawab=='y'||jawab=='t'||jawab=='Y'||jawab=='T'));
        if (jawab=='y'||jawab||'Y')
        {
            if(simpulSebelum==NULL){
                simpulAwal=simpulAwal->Berikut;
            }
            else{
                simpulSebelum->Berikut=simpulCari->Berikut;
            }
            free(simpulCari);
            printf("Sudah dihapus !!!\n");
        }   
    }
}
void callSwicthMenu(){
    short int pilihanMenu=0;
    do
    {
        if (pilihanMenu!=0)
        {
            printf("Tekan enter untuk kembali ke menu\n");
            jawab=getche();
        }
        menu(&pilihanMenu);
        switch (pilihanMenu)
        {
        case 1:
            buatBaru();
            continue;
        case 2:
            tambahNode();
            continue;
        case 3:
            tampilkanNode();
            continue;
        case 4:
            hapusNode();
            continue;
        case 5:
            tampilkanDaftar(simpulAkhir,1);
            continue;
        }
        
    } while (pilihanMenu!=0);
}
#endif