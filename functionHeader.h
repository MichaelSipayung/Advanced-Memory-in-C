#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
double absolute(double);
long int fact(int);
long int sum(int );
long int factStat(int);
void showStatResult(int );
void byValuePass(float);
void byReferencePass(float*);
void anotherRef(int*,int*,int*);
int* modifyAnotherRef(int*,int*,int*);
void swap(int*,int*);
void exchange(char[]);
void passArray(float[],int);
void showAr(float[],int);
void modifyString(char[],int);
void bubleSort(int[],int);
void swapData(int,int);
void showArIn(int[],int);
void secDimen(int[][3],int ,int);
void showMat(int[][3],int ,int);
void pointerAsParam(char*,int*,int*);
void anotherSample(int [],int*,int*,int );
void accumulateSample(int*,int*);
void pointerAsTwoDim( int (*)[3],int *,int *);
void ShowpointerAsTwoDim( int (*)[3],int *,int *);
//prototype for array..pointer
void arrayPoint(int*[3],int*,int*);
void fillArrayPoint(int*[3],int*,int*);
void showArrayPoint(int*[3],int*,int*);
