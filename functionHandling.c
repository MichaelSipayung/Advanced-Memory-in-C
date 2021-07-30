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
    int dataSort[]={1,2,1,2,3,1,2,4,1,2,1,2,3,1};
    bubleSort(dataSort,sizeof(dataSort)/sizeof(*dataSort));
    showArIn(dataSort,sizeof(dataSort)/sizeof(*dataSort));
    int matriks[][3]={1,2,3,4,5,6,7,8,9};
    secDimen(matriks,3,3);
    showMat(matriks,3,3);    
    char checkVowel[] ="mciahel sipayung";
    int hMati=0;
    int hHidup=0;
    pointerAsParam(checkVowel,&hHidup,&hMati);
    printf("Name \t: %s\n", checkVowel);
    printf("Total Vowel \t : %d\n", hHidup);
    printf("Total Non Vowel \t : %d\n", hMati);
    int reportData[]={1,2,3,4,5,111,231,123,1231,76,345,123,31,1,23,1231,31,31,133,23,45,64};
    int great=100,less=90,allAr=sizeof(reportData)/sizeof(*reportData);
    anotherSample(reportData,&great,&less,allAr);
    accumulateSample(reportData,&allAr);
    //proof for small arr : like induction 
    int smallSamle[]={1,2,3,4,5};
    allAr=sizeof(smallSamle)/sizeof(*smallSamle);
    accumulateSample(smallSamle,&allAr);
    int (*allocDynamic)[3];
    allocDynamic= malloc(3*3*sizeof(*allocDynamic));
    for (size_t i = 0; i < 3; ++i)
    {
        for (size_t j = 0; j < 3; ++j)
        {
            *(*(allocDynamic+i)+j)=i;
        }
    }
    int row=3,cols=3;
    printf("Before modify \n");
    ShowpointerAsTwoDim(allocDynamic,&row,&cols);
    pointerAsTwoDim(allocDynamic,&row,&cols);
    printf("After modify \n");
    ShowpointerAsTwoDim(allocDynamic,&row,&cols);
    free(allocDynamic);
    //array ..pointer
    int *alocate[3];//3 : row to be allocate
    //note for array..pointer , row is fixed, and cols is col
    
    int bar=3, column=3;
    for (size_t i = 0; i < bar; ++i)
    {
        alocate[i]=malloc(column*sizeof(int)); //allocate matrix 3x3
        
    }
    printf("Before modify\n");
    fillArrayPoint(alocate,&bar,&column);
    showArrayPoint(alocate,&bar,&column);
    printf("After Modify\n");
    arrayPoint(alocate,&bar,&column);
    showArrayPoint(alocate,&bar,&column);

    for (size_t i = 0; i < bar; ++i)
    {
        free(alocate[i]);
    }
    printf("Call recursion, factorial value of 5! \t: %d\n", recursion(5));    
    //initialized array 
    int dataIsbn[]={1,2,3,4,5,2,1,2,1,333,1,2,3};
    quickSort(dataIsbn,0,sizeof(dataIsbn)/sizeof(*dataIsbn));
    printf("After short the data  \n");
    showArIn(dataIsbn,sizeof(dataIsbn)/sizeof(*dataIsbn));
    printf("fibonaci (4) \t: %d\n", fibonaciRec(4));
    printf("Iteratif fibonaci (4) \t: %d\n", iterativeFibonac(4));

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
void bubleSort(int data[],int n){
    for (size_t j = 0; j < n-1; ++j)
    {
        for (size_t i = 0; i < n-j-1; ++i)
        {
            if (data[i]>data[i+1])
            {
                swap(&data[i],&data[i+1]);//exchange two data 
            }   
        }   
    }    
}

void showArIn(int data[],int length){
    int n =0;
    printf("data\t: [");
    while (n!=(length))
    {
        printf("%d |",data[n]);
        ++n;
    }
    printf("]\n");    
}
void secDimen(int data[][3],int baris ,int kolom){
    for (size_t i = 0; i < baris; ++i)
    {
        for (size_t j= 0; j < kolom; ++j)
        {
            data[i][j]=data[i][j]-1;
        }   
    }    
}
void showMat(int data[][3],int baris,int kolom){
    printf("result\n");
    for (size_t i = 0; i < baris; ++i)
    {
        for (size_t j= 0; j < kolom; ++j)
        {
            printf ("%d |",data[i][j]);
        }
        printf("\n");   
    }
}
void pointerAsParam(char *str,int*hidup,int*mati){
    while (*str)
    {
        if (*str=='a'||*str=='u'||*str=='i'||*str=='e'||*str=='o'||*str=='A'||*str=='O'||*str=='U'||
            *str=='E'||*str=='O')
        {
            (*hidup)++;
        }
        else if ((*str>='a'&&*str<='z')||(*str>='A'&&*str<='Z'))
        {
            (*mati)++;
        }           
        ++str;
    }    
}
void anotherSample(int data[],int*great,int*small,int total){
    int tempGreat[100]={0}, tempSmall[100]={0};
    int startGreat=0,startSmall=0;
    while (total!=-1)
    {
        if (data[total]>*great)
        {
            tempGreat[startGreat]=data[total];
            ++startGreat;
        }
        else if (data[total]<*small)
        {
            tempSmall[startSmall]=data[total];
            ++startSmall;
        }   
        --total;
    }
    printf("value less than \t: %d \n", *small);
    for (size_t i = 0; i < startSmall; ++i)
    {
        printf("%d |", tempSmall[i]);
    }
    printf("\n");
    printf("value greater than \t: %d \n", *great);
    for (size_t i = 0; i < startGreat; ++i)
    {
        printf("%d |", tempGreat[i]);
    }
    printf("\n");
}
void accumulateSample(int*data,int*total){
    int accum=0;
    *total=*total-1;
    while ((*total)!=-1)
    {
        accum+=(*(data+(*total)));
        --(*total);
    }
    printf("Total value\t: %d\n", accum);
}
void pointerAsTwoDim( int (*data)[3],int *baris,int *column){
    for (size_t i = 0; i < *baris; ++i)
    {
        for (size_t j = 0; j < *column; ++j)
        {
            *(*(data+i)+j)=*(*(data+i)+j)-1;
        }    
    }    
}
void ShowpointerAsTwoDim( int (*data)[3],int *baris,int *column){
    for (size_t i = 0; i < *baris; ++i)
    {
        for (size_t j = 0; j < *column; ++j)
        {
            printf("%d |",*(*(data+i)+j));
        }
        printf("\n");    
    }    
}
void arrayPoint(int*data[3],int*row,int*cols){
    for (size_t i = 0; i < *row; ++i)
    {
        for (size_t j = 0; j < *cols; ++j)
        {
            *(data[i]+j)-=1;
        }
    }    
}
void fillArrayPoint(int*data[3],int*row,int*cols){
    for (size_t i = 0; i < *row; ++i)
    {
        for (size_t j = 0; j < *cols; ++j)
        {
            *(data[i]+j)=i;
        }
    }
}
void showArrayPoint(int*data[3],int*row,int*cols){
    for (size_t i = 0; i < *row; ++i)
    {
        for (size_t j = 0; j < *cols; ++j)
        {
            printf("%d| ",*(data[i]+j));
        }
        printf("\n");
    }
}
long int recursion(int n){
    if (n<=1)
    {
        return 1;
    }
    return (n*recursion(n-1));    
}
void quickSort( int x[],int bawah ,int atas){
    int i,j,k;
    int sementara;
    while (atas>bawah)
    {
        i= bawah;
        j=atas;
        sementara=x[bawah];
        while (i<j)
        {
            while (x[j]>sementara)
            {
                --j;
            }
            x[i]=x[j];
            while (i<j&&x[i]<=sementara)
            {
                ++i;
            }
            x[j]=x[i];
        }
        x[i]=sementara;
        quickSort(x,bawah,i-1);
        bawah=i+1;   
    }    
}
int fibonaciRec(int n){
    if (n<2) //terminate condition 
    {
        return n;
    }
    return (fibonaciRec(n-2)+fibonaciRec(n-1));
    
}
int iterativeFibonac(int n){
    int low_Fibo, high_Fibo,x,i;
    if (n<2)
    {
        return(n);
    }
    low_Fibo=0;
    high_Fibo=1;
    for ( i = 2; i <= n; ++i)
    {
        x=low_Fibo;
        low_Fibo=high_Fibo;
        high_Fibo=x+low_Fibo;
    }
    return high_Fibo;
}
