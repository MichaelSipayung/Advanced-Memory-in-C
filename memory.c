#include "headerMem.h"

int main(){
    memTest();
    memtestTwo();
    matrixA();
    understandingStruct();
    minimizeStorange();
    thirdDimensionPOin();
    larikPointer();
    pointerToPointer();
    return 0;
}

void memTest(){
    int *alloc;
    alloc  = malloc(4*sizeof(int));
    if(alloc){
            *(alloc)=12,*(alloc+1)=13,*(alloc+2)=90,*(alloc+3)=87;
            printf("1.Address \t: %p and value \t: %d\n" , alloc,*alloc);
            printf("2.Address \t: %p and value \t: %d\n" , alloc+1,*(alloc+1));
            printf("3.Address \t: %p and value \t: %d\n" , alloc+2,*(alloc+2));
            printf("4.Address \t: %p and value \t: %d\n" , alloc+3,*(alloc+3));
            printf("sizeof alloc \t: %d byte" , sizeof(*alloc));
            //accumulate all element 
            int begin =0,total=0;
            while (begin!=4)
            {
                total+=*(alloc+begin);
                ++begin;
            }    
            printf("\ntotal allocated object \t: %d \n" , total);
            free(alloc);
        }
        else{
            printf("Failed to allocated object in memory \n");
        }
}
void memtestTwo(){
    int (*x)[3];
    x = malloc(5*3*sizeof(*x)); //matrices 5 *x | pointer that point to aray of array size 5*3
    if (x)
    {
        printf("Allocation success\n");
        //fill teh value 
        *(*(x+0)+0)=12;//index (0,0);
        *(*(x+0)+1)=13;//index (0,1);
        *(*(x+0)+2)=18;//index (0,2);
        printf("item value (0,2) : %d \n" , *(*(x)+2));
        //next row 
        *(*(x+1)+0)=143;
        *(*(x+1)+1)=123;
        *(*(x+1)+2)=113;
        printf("item value (1,2) : %d \n" , *(*(x+1)+2));
        free(x);
    }
    else{
        printf("failed to allocated the object\n");
    }
    
}
void matrixA(){
    int (*matriks)[KOLOM];
    matriks=malloc(BARIS*KOLOM*sizeof(*matriks));
    if(matriks){
        printf("Allocated success\n");
    for (size_t i = 0; i!=BARIS; ++i)
    {
        for (size_t j = 0; j < KOLOM; ++j)
        {
            *(*(matriks+i)+j)=i;
        }        
    }
    //adding square matrix by it's self
    for (size_t i = 0; i!=BARIS; ++i)
    {
        for (size_t j = 0; j < KOLOM; ++j)
        {
            *(*(matriks+i)+j)+=*(*(matriks+i)+j);
        }        
    }
    printf("result \t: \n");
    for (size_t i = 0; i!=BARIS; ++i)
    {
        for (size_t j = 0; j < KOLOM; ++j)
        {
            printf("%d | ",*(*(matriks+i)+j));
        }        
        printf("\n");
    }  
    free(matriks);
    }
    else{
        printf("Allocated failed\n");
    }
}

void understandingStruct(){
    int (*alloc)[3];
    alloc=malloc(BARIS*KOLOM*sizeof(*alloc));
    if (alloc)
    {
        *(*(alloc))=12;
        printf("1.before freed\t: %d\n" , *(*(alloc+0)+0));
        printf("allocated success\n");
        printf("1.Taking the addredd\t: %p\n" , *(alloc+0)+0);
        printf("2.Taking the addredd\t: %p\n" , *(alloc+0)+1);
        printf("3.Taking the addredd\t: %p\n" , *(alloc+0)+2);
        free(alloc);
    }
    else{
        printf("bad alloc\n");
    }
    //printf("1.After freed\t: %d\n" , *(*(alloc+0)+0));//bad alloc has freed
}
void minimizeStorange(){
    //act like one dimension but the purpose is make 2 dimension array 
    int *alloc;
    alloc =malloc(BARIS*KOLOM*sizeof(*alloc));
    if(alloc){
        printf("Allocated success\n");
        //fill the value to current object 
        *(alloc+0*KOLOM+0)=12; //(0,0)
        *(alloc+0*KOLOM+1)=13; //(0,1)
        *(alloc+0*KOLOM+2)=83; //(0,2)
        
        *(alloc+1*KOLOM+0)=21; //(1,2)
        *(alloc+1*KOLOM+1)=31; //(1,2)
        *(alloc+1*KOLOM+2)=41; //(1,2)

        *(alloc+2*KOLOM+0)=67; //(2,0)
        *(alloc+2*KOLOM+1)=89; //(2,1)
        *(alloc+2*KOLOM+2)=56; //(2,2)
        printf("Traverse element \n");
        int beginBar=0,endBar=3;
        printf("result after assignment\t: \n");
        while (beginBar!=endBar)
        {
            int beginCol=0, endCol=3;
            while (beginCol!=endCol)
            {
                printf("%d | " , *(alloc+beginBar*KOLOM+beginCol));
                ++beginCol;
            }
            
            ++beginBar;
            printf("\n");
        }
        free(alloc);
    }
    else{
        printf("Bad alloc\n");
    }    
}
void thirdDimensionPOin(){
    int (*alloc)[3][3];
    alloc =malloc(3*BARIS*KOLOM*sizeof(*alloc)); //allocated 3*3*3 object for third dimension array 
    if (alloc)
    {
        printf("Success allocated obejct\n");
        *(*(*(alloc+2)+0)+0)=12; //first row and first col 
        printf("The third  group from 2 dimension of array \t:%d \n" ,(*(*(*(alloc+2)+0)+0)));
        free(alloc);
    }
    else{
        printf("Bad allocated object\n");
    }
}
void larikPointer(){
    int *alloc[5];//matrices with size n*5
    //acclocate object
    for (size_t i = 0; i < BARIS; ++i)
    {
        alloc[i]=malloc(KOLOM*sizeof(*alloc));
        if (alloc)
        {
            printf("Allocated object success\n");
        }
        else{
            return;
        }
        
    }
    //fill the value 
    for (size_t i = 0; i < BARIS; ++i)
    {
        for (size_t j = 0; j < KOLOM; ++j)
        {
            *(alloc[i]+j)=i;
        }       
    }
    //show current item
    printf("Current item :\n");
    for (size_t i = 0; i < BARIS; ++i)
    {
        for (size_t j = 0; j < KOLOM; ++j)
        {
            printf("%d| ",*(alloc[i]+j));
        }      
        printf("\n"); 
    }
    //freed from memory 
    for (size_t i = 0; i < BARIS; ++i)
    {
        free(alloc[i]);
    }
}
void pointerToPointer(){
    int a =12,*point=&a,**pointPoint=&point;
    printf("1.Address \t: %p add value \t: %d \n", a,a);
    printf("2.Address \t: %p add value \t: %d \n", point,*point);
    printf("3.Address \t: %p add value \t: %d \n", pointPoint,**pointPoint);
}