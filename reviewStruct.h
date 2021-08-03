#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum namaHari{minggu,senin,selasa,rabu,kamis,jumat,sabtu};
//next day 
void callDay();
void traverse();
struct strukturPsd{ //name structure
    char *kode;
    char *nama;
    int unit;
    float harga;
};//put here for variable name 
struct strukturPsd persedianCabang,persedianPusat;
//direct initialization 
struct NewstrukturPsd{ //name structure
    char *kode;
    char *nama;
    int unit;
    float harga;
}newPersedianCabang={"algo","Algorithm",12,32};
struct NewstrukturPsd newData={"mat","math",13,32};
struct Tanggal{
    unsigned int hari;
    unsigned int bulan;
};
struct Alamat{
    char jalan[14];
    char kota[43];
};
struct structInSruct{
    char nama[56];
    struct Tanggal masuk;
    struct Alamat tinggal;
    float gaji;
};
struct structInSruct fillData={"discrete",12,5,"madison","avenue",98.8};
//array in structure 
struct arrayIn{
    int unit,gaji;
    float harga;
};
struct arrayIn fillArray[5]={
    12,12000,30.90,
    15,13000,40.90,
    16,14000,50.90,
    17,19000,80.90,
};
void traverseArrayStruct();
struct newTanggal{
    unsigned hari:5;
    unsigned bulan:4;
    unsigned tahun:7;
};
struct newTanggal compare;
struct newTanggalNonBIt{
    unsigned hari;
    unsigned bulan;
    unsigned tahun;
};
struct newTanggalNonBIt compareRes;
void compareInMemory();
union {
    float keliling;
    double luas;
}unionVar;
struct {
    float keliling;
    double luas;
}withoutUnion;
void sizeOfUnion();
//more about union 
struct Bit{
    unsigned bit0:1;
    unsigned bit1:1;
    unsigned bit2:1;
    unsigned bit3:1;
    unsigned bit4:1;
    unsigned bit5:1;
    unsigned bit6:1;
    unsigned bit7:1;
};
union{
    unsigned int decimal;
    struct Bit binari;
}Nilai;
void showBit(unsigned );
//typedef for name alias 
typedef struct {
    int sold;
    float unit;
    
}Matematic;
Matematic firstMath,secMath;//contain all element in struct mathematic
typedef struct{
    char *jalan;
    char *kota;
}AlamatPoint;
struct point{
    char *nama;
    AlamatPoint tinggal;
    int *jamKerja;

}pointKaryawan,*Pk=&pointKaryawan;
void insertStructPoint(); 
void traverseStructPoint(); 
void freed();
struct arrayStr{
    char *nama;
    char *jalan;
    char *city;
};
struct arrayStr newKaryawan[3]={
    "jack","madison","NYU",
    "linke","madison","NYU",
    "daniel","madison","NYU",

};
void traversenewKaryawan(struct arrayStr*);
//pass struct to function 
struct bookPsd{
    char kode[6];
    int unitSold;
};
struct bookPsd fillBook={
    "math",12
};
void passBook(struct bookPsd*);
void byValuePassBook(char[],int);
void changePassBook(struct bookPsd*);
//return struct
struct bookPsd returnBook(struct bookPsd);

struct ReturnPointer{
    char *nama;
    char *jalan;
    char *city;
    int price;
};
struct ReturnPointer returnPOintDa[3]={
    "jack","madison","NYU",12,
    "linke","madison","NYU",23,
    "daniel","madison","NYU",4

};
struct ReturnPointer *nameFind(struct ReturnPointer*);
void showRet();