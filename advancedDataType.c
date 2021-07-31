#include "headerAdvancedData.h"
int main(){
    enumDay();
    enumHour();
    traverseEnum();
    switchEnum();
    // assign to circle 
    firstCircle.radius=10;
    firstCircle.area= 3.14259*firstCircle.radius*firstCircle.radius;
    printf("Area of circle with radius %f is \t: %f\n", firstCircle.radius,firstCircle.area);
    printf ("Access struct that contain another struct  \n");
    printf("1.Name \t\t: %s \n", employeeName.nama);
    printf("2.Masuk hari \t: %d \n", employeeName.masuk.hari);
    printf("3.Tinggal \t: %s \n", employeeName.tinggal.streetName);    
    //traverse array in structure
    printf("traverse array in structure\n");
    int max =0;
    double revenue=0;
    while (max!=2)
    {
        printf("%s | %s | %d | %f\n", Persedian[max].kode,Persedian[max].name,Persedian[max].unit,Persedian[max].harga);
        revenue +=Persedian[max].harga*Persedian[max].unit;
        ++max;
    }
    printf("Total revenue \t: %f\n", revenue);
    printf("Total memory in use\t: %d byte\n", sizeof(karyawan.masuk));
    //compare
    printf("Total memory in use\t: %d byte\n", sizeof(employeeName.masuk));
    printf ("Show memory used \t: %d byte\n", sizeof(callCircle));
    printf ("-- compare\nShow memory used \t: %d byte\n", sizeof(compareMemory));
    printf("Sizeof float\t %d byte\n ", sizeof(float));
    //traverseBit();
    nameKar.take.age=12; // and so on 
    //test dereference pointer struct
    pointMyVal->nilai=15;//style 1
    printf("1.Dereference the value \t: %d\n", pointMyVal->nilai);
    (*pointMyVal).nilai=13;
    printf("2.Dereference the value \t: %d\n", (*pointMyVal).nilai);
    printf("Traverse array using pointer struct \n");
    traverseAll();
    //change the current value 
    bookIs.sold=8;
    printf("Current book \t: %d\n", bookIs.sold);
    refBook->sold=56;
    printf("Current book \t: %d\n", refBook->sold);
    refBook->name="math";
    printf("Current name book \t: %s\n", refBook->name);
    //call struct through function
    passStruct(persedianS.kode,persedianS.unit);
    int tempStr=12,tempStructT=89;
    reference->harga=12;
    reference->total=90;
    printf("Call by reference\n");
    byRef(&reference->harga,&reference->total);
    printf("Pass all structure through a function\n");
    printf("Pass all member test \n");
    tampilHasil(newPersedian);//pass structure 
    printf("call using pointer\n");
    tampilHasilPointer(&newPersedian);//call the address of struct newpersedian 
    printf("Original data\n");  
    returnRefShow(&fillData);//call the original data
    printf("call another function to modify the original structure\n");
    returnRefModify(&fillData);//return to struct 
    returnRefShow(&fillData);//call the original data



}
void enumDay(){
    enum {minggu,senin,selasa,rabu,kamis,jumat,sabtu};
    printf("first day\t: %d\n", minggu);
    // ... next day 0 1 2 ...
}
void enumHour(){
    enum totalSec{detik=1,detik60=60};
    enum totalSec menit,jam,detikMenit;
    menit = detik60;
    jam = menit*detik60;
    detikMenit=(detik60*5)/menit;//etst 1 minute 
    printf("%d second is equal to \t: %d menit\n ",detik60*5,detikMenit );
}
void traverseEnum(){
    enum {sunday,monday,tuesday,wednesday,thrusday,friday,saturday}countDay;
    countDay=sunday;
    while (countDay<=saturday)
    {
        printf("%d |",countDay);
        ++countDay;
    }
    printf(" --- Total day in a week is \t: %d ---\n ", countDay);    
}
void switchEnum(){
    enum {sunday,monday,tuesday,wednesday,thrusday,friday,saturday}countDay;
    countDay=monday;
    switch (countDay)
    {
    case monday:
        printf ("go to church\n");
        break;
    
    default:
        printf("study hard\n");
        break;
    }
}
void structPsd(){
    struct advancedDataType
    {
        char kode[5];
        char name[30];
        int unit;
        float harga;
    }; //direct initialize to centerDel,baseDel here ..
    struct advancedDataType centerDelivery,baseDelivery;//initialize 2 variable that contain struct(data)
    struct advancedDataType directIn={"0xma","mathematics",12,32};
    // ..test assign .. directIn.unit=13;    
}
/* void traverseBit(){
    printf("Decimal value from 12345 \t: ");
    scanf("%d",&Nilai.decimal);//reverse order for correct value note
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",Nilai.Binari.bit0,
    Nilai.Binari.bit1,Nilai.Binari.bit2,Nilai.Binari.bit3,Nilai.Binari.bit4,Nilai.Binari.bit5,Nilai.Binari.bit6,
    Nilai.Binari.bit7,Nilai.Binari.bit8,Nilai.Binari.bit9,Nilai.Binari.bit10,Nilai.Binari.bit11,Nilai.Binari.bit12,
    Nilai.Binari.bit13,Nilai.Binari.bit14,Nilai.Binari.bit15);
}*/
void traverseAll(){
    int bound=0;
    while (bound!=2)
    {
        printf("%s | %d | %d\n", (pointerToElement+bound)->name,(*(pointerToElement+bound)).masuk.hari,(pointerToElement+bound)->masuk.bulan);
        ++bound;
    }
    
}
void fillTheElement(){
    //fill the element to allow travserse through pointer 
}
void passStruct(char kode[],int unit){
    printf ("nama barang\t: %s\n",kode);
    printf ("total barang\t: %d\n",unit);
}
void byRef(int*harga,int*total){
    printf ("harga barang\t: %d\n",*harga);
    printf ("total barang\t: %d\n",*total);
}
void tampilHasil(struct newPsd nameTopass){
    printf("Harga\t: %d\n", nameTopass.harga);
    printf("Unit\t: %d\n", nameTopass.unit);
}
void tampilHasilPointer(struct newPsd*namePoint){
    printf("Harga\t: %d\n", namePoint->harga);
    printf("Unit\t: %d\n", namePoint->unit);
}

void returnRefModify(returnStruct*modifyData){
    modifyData->unit=modifyData->unit-1;//return reference we pass the address
}
void returnRefShow(returnStruct*showModify){
    printf("Harga\t: %d\n", showModify->unit);
    printf("Nama barang\t: %s\n", showModify->kode);
}



