#include <stdio.h>
#include <string.h>
#include <math.h>
void enumDay();
void enumHour();
void traverseEnum();
void switchEnum();
void structPsd();
struct circle
{
    double radius,area,keliling;
};
struct circle firstCircle;
//struct that contain another struct 
struct date
{
    unsigned int hari;
    unsigned int bulan;
    unsigned int tahun;

};
struct address
{
    char streetName[40];
    char city[40];
};
struct  
{
    char nama[40];
    struct date masuk;
    struct address tinggal;
    float gaji;
} employeeName={
    //direct initialize
    "Michael",
    15,5,32,"Jl.Jamin Ginting","Medan",67.09
};
//array and struct 
struct Psd
{
    char kode[5];
    char name[20];
    int unit;
    float harga;
};
struct Psd Persedian[100]={
    "m123","Monitor",13,23.09,
    "0x8d","Pc",89,98.32
};
//medan digit binary 
struct Tanggal
{
    unsigned hari:5;
    unsigned bulan:4;
    unsigned tahun:7;
};
struct jenisStatus
{
    unsigned jenis:1;
    unsigned status:1;
};
struct 
{
    char nama[23];
    struct Tanggal masuk;
    struct jenisStatus js;
} karyawan={
    "michael",
    17,11,98,
    1,
    0 //if single : 0 and 1: not single
};
union 
{   
    int radius;
    float area;
    double luas;
} callCircle;

struct {
    int radius;
    float area;
    double luas;
}compareMemory;
//advanced test 
struct Bit{
    unsigned bit0:1;
    unsigned bit1:1;
    unsigned bit2:1;
    unsigned bit3:1;
    unsigned bit4:1;
    unsigned bit5:1;
    unsigned bit6:1;
    unsigned bit7:1;
    unsigned bit8:1;
    unsigned bit9:1;
    unsigned bit10:1;
    unsigned bit11:1;
    unsigned bit12:1;
    unsigned bit13:1;
    unsigned bit14:1;
    unsigned bit15:1;
};
union {
    unsigned int decimal;
    struct Bit Binari;
}Nilai;
void traverseBit();
//using typedef to redeclare 
typedef struct{
    int age,month,year;
}dateTake;
typedef struct {
    //without followed struct keyword
    dateTake take;
}karyaw;
karyaw nameKar; //without call karyaw folowed by struct 
//pointer and structure 
struct{
    char name[5];
} nameStructor,*pointer; //method 1

struct{
    int nilai;
}myVal,*pointMyVal=&myVal;
//more sample
//traverse array
typedef struct{
    unsigned hari:5;
    unsigned bulan:4;
}pointTanggal;

typedef union 
{
    short int fix;
    float tetap;
}pointTambahan;

typedef struct{
    char name[10];
    pointTanggal masuk;
}pointElemenk;

pointElemenk pElemen[2]={
"michael",5,11,
"jackie",4,9
};
//test pointer 
pointElemenk *pointerToElement = pElemen;//without address operator, because poinerToElement point to an array 
//declaration for traverse the element 
void traverseAll();
void fillTheElement();
//next sample 
struct bookNum
{
    char *name;
    int sold;
}bookIs,*refBook=&bookIs;
//pass structure to function 
struct  psdUnit
{
    char kode[5];
    int unit;
};
struct psdUnit persedianS={"mike",12};
void passStruct(char[],int);
//test pass by reference 
void byRef(int*,int*);
struct 
{
    int harga,total;
}original,*reference=&original;

struct newPsd{
    int unit;
    int harga;
};
struct newPsd newPersedian={
    12,34
};
void tampilHasil(struct newPsd );
//pointer call 
void tampilHasilPointer(struct newPsd*);
//implement return struct 
typedef struct{
    char*kode;
    int unit;
}returnStruct;
returnStruct fillData={
    "ebook",
    12
};
//function for return reference 
void returnRefModify(returnStruct*);
void returnRefShow(returnStruct*);
