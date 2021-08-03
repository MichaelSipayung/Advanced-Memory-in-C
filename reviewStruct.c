#include "reviewStruct.h"
int main(){
    callDay();
    traverse();
    /*printf("1.Persedian cabang(unit)\t:%d\n",newPersedianCabang.unit);
    printf("2.Persedian cabang(unit)\t:%d\n",newData.unit);
    printf("3.struct in struct(masuk-bulan)\t:%d\n",fillData.masuk.bulan);
    */
    traverseArrayStruct();    
    compareInMemory();
    sizeOfUnion();
    showBit(128);
    showBit(255);
    insertStructPoint();
    traverseStructPoint();
    freed();
    traversenewKaryawan(newKaryawan);//without address operator because it's already pointer ;
    passBook(&fillBook);//followed with address operator
    byValuePassBook(fillBook.kode,fillBook.unitSold);
    changePassBook(&fillBook);
    passBook(&fillBook);
    //return all struct .. by value 
    struct bookPsd temporary=returnBook(fillBook);
    printf("unit sold \t: %d unit \n", temporary.unitSold);
    showRet();
    return 0;

}
void callDay(){
    printf("Nama hari pertama\t: %d\n",minggu);
}
void traverse(){
    for (size_t i = minggu; i <=sabtu; ++i)
    {
        printf("%d |",i);
    }
    printf("\n");
}
/*
persedianCabang={
    "algo","Algoritma",12,90.12
};wrong */
void traverseArrayStruct(){
    printf  ("Array in structure\n");
    for (size_t i = 0; i < 4; ++i)
    {
        printf("%d | %d | %f\n", fillArray[i].unit,fillArray[i].gaji,fillArray[i].harga);
    }
    
}
//bit field 
void compareInMemory(){
    printf("Sizeof non bit field\t: %d  byte\n", sizeof(compareRes));
    printf("Sizeof bit field\t: %d  byte\n", sizeof(compare));
}
void sizeOfUnion(){
    printf("Sizeof union \t: %d byte \n", sizeof(unionVar));
    printf("sizeof without union \t: %d byte\n", sizeof(withoutUnion));
}
void showBit(unsigned n){
    Nilai.decimal=n;
    printf("%d %d %d %d %d %d %d %d \n",Nilai.binari.bit7,Nilai.binari.bit6,Nilai.binari.bit5,Nilai.binari.bit4,
    Nilai.binari.bit3,Nilai.binari.bit2,Nilai.binari.bit1,Nilai.binari.bit0);
}
void insertStructPoint(){
    Pk->nama="michael";
    Pk->tinggal.jalan="madison";
    Pk->tinggal.kota="new york";
    Pk->jamKerja=malloc(3*sizeof(*(Pk->jamKerja)));
    Pk->jamKerja[0]=8;//first day 
    Pk->jamKerja[1]=7;
    Pk->jamKerja[2]=8;
} 
void traverseStructPoint(){
    printf("nama\t: %s\n", Pk->nama);
    printf("alamat\t: %s\n", Pk->tinggal.jalan);
    printf("kota\t: %s\n", Pk->tinggal.kota);
    printf("1.jam kerja\t: %d jam\n", Pk->jamKerja[0]);
    printf("2.jam kerja\t: %d jam\n", Pk->jamKerja[1]);
}
void freed(){
    free(Pk->jamKerja);
}
void traversenewKaryawan(struct arrayStr *variableHere){
    printf("traverse through pointer\n");
    for (size_t i = 0; i < 3; ++i)
    {
        printf("%s \t| %s \t| %s \n", (variableHere+i)->nama,(variableHere+i)->jalan,(variableHere+i)->city);
    }        
}
void passBook(struct bookPsd*variableName){
    printf("Pass struct as argument\n");
    printf("Kode buku\t: %s\n", variableName->kode);
    printf("unit sold \t: %d unit\n", variableName->unitSold);
}
void byValuePassBook(char kode[],int unit){
    printf("Pass struct as argument\n");
    printf("Kode buku\t: %s\n", kode);
    printf("unit sold \t: %d unit\n", unit);
}
void changePassBook(struct bookPsd*variableName){
    variableName->unitSold=variableName->unitSold-1;
}
struct bookPsd returnBook(struct bookPsd varName){
    varName.unitSold=varName.unitSold-1;
    return varName;
}
struct ReturnPointer *nameFind(struct ReturnPointer*nameParam){
    if (nameParam->price>10)
    {
        return nameParam;
    }
    else{
        return NULL;
    }
    
}
void showRet(){
    struct ReturnPointer *name;
    for (size_t i = 0; i < 3; ++i)
    {
        name=nameFind(&returnPOintDa[i]);
        if (name!=NULL)
        {
            printf("%s\t%s\t%s\t%d\n",name->nama,name->jalan,name->city,name->price);
        }           
    }   
}