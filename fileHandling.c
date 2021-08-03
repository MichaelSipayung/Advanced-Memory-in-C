#include "fileHandling.h"
int main(){
    FILE *pf;
    pf=fopen("contohFile.txt","a+");//append +read
    if (!pf)
    {
        printf("can\' write a file to disk\n");
        exit(1);
    }
    printf("File is exist\n");
    fputs("abcde\n",pf);
    fputs("abcde\n",pf);
    printf("isi dari file\n");
    fwrite(&Struktur,sizeof(Struktur),1,stdout);//struct out
    fprintf(stdout,"Nilai \t: %f", 12.98);//standart output      
    //close your file 
    fclose(pf);
    if (fclose(pf))
    {
        printf("\nfile sudah ditutup\n");
    }
       
    return 0;
}