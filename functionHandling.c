#include "functionHeader.h"

int main(){
    printf("Absolute value %f \t : %f \n", -98.98,absolute(-98.98));
    printf("factorial of 5!\t: %d\n" , fact(5));
    printf("Accumulate number from 5 to 0 is \t:  %d \n" , sum(5));
    showStatResult(15);
    float a=25,*address=&a;
    byValuePass(a);
    printf("compare the address\t: %p\n", address);
    //call by reference 
    float aRef=13,*addressRef=&aRef;
    byReferencePass(&aRef);
    printf("Address \t: %p\n ", addressRef);
    printf("Value \t: %f\n", aRef);    
    //pass by reference test 
    int passA=12,passB=14, passC;
    anotherRef(&passA,&passB,&passC);
    printf("Result call by reference \t: %d \n" , passC);    
    passA=15;
    int *temporary  =modifyAnotherRef(&passA,&passB,&passC);
    printf("return by reference \t: %d\n " , *temporary);
    swap(&passA,&passB);
    printf("After swap a\t: %d \tb\t:%d \n", passA,passB);
    char ori[]="original";
    printf("original character \t: %s \n", ori);
    exchange(ori);
    printf("modify character \t: %s \n", ori);
    float twelve[] ={1,2,3,4,5,6,7,8,9,10,11,12};
    int arrayLength=sizeof(twelve)/sizeof(*twelve);
    showAr(twelve,arrayLength);    
    passArray(twelve,arrayLength);
    showAr(twelve,arrayLength);    
    char myName[]="michael SipayunG";
    modifyString(myName,strlen(myName)-1);
    printf("Result \t: %s\n", myName);
}

double absolute(double param){
    if (param<0)
    {
        param=-param;
    }
    return (param);
}
long int fact(int n){
    long int f=1;
    if(n<=0){
        return 0;
    }
    else{
        while (n>=1)
        {
            f*=n;
            --n;
        }       
    }
    return f;
}
long int sum(int n){
    long int f=0;
    while (n!=0)
    {
        f+=n;
        --n;
    }
    return f;
}
long int factStat(int n){
    static int f=1;
    f*=n;
    return f;
}
void showStatResult(int n){
    long int fak;
    if (n<1)
    {
        printf("Factorial is 0\n");
    }
    else{
        while (n!=1)
        {
             fak=factStat(n);
            --n;
        }
        printf("Factorial value \t: %d \n" ,fak );
    }    
}
void byValuePass(float a){
    float *addressA;
    addressA=&a;
    printf("Address \t: %p\n", addressA);
}
void byReferencePass(float*a){
    float *address  =a;
    printf("Address \t: %p\n ", address);
    printf("Value \t: %f\n", *a);
}
void anotherRef(int*a,int*b,int*c){
    *c=*a+*b;
}
int* modifyAnotherRef(int*a,int*b,int*c){
    *c=*a+*b;
    return c;// or we can modify, return to an address of non pointer variable
}
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void exchange(char data[]){
     int n = strlen(data);
     printf("length \t: %d\n", n);
     n=n-1;
     while (n!=0)
     {
         data[n]=data[n-1];
         data[n-1]=data[n];
         --n;
     }
}
void passArray(float data[],int length){
    int n =0;
    while (n!=length)
    {
        data[n]=data[n]-1;
        ++n;
    }    
}

void showAr(float data[],int length){
    int n =0;
    printf("data\t: [");
    while (n!=(length))
    {
        printf("%f |",data[n]);
        ++n;
    }
    printf("]\n");
}
void modifyString(char data[],int n){
    while (n!=-1)
    {
        if (isupper(data[n]))
        {
            data[n]=tolower(data[n]);
        }
        else if (islower(data[n]))
        {
            data[n]=toupper(data[n]);
        }
        
        --n;
    }
    
}