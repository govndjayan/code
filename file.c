#include<stdio.h>
int main(int argc, char *argv[])
{
    FILE *f1;
    FILE *f2;
    char c;
    if(argc!=3)
	printf("\nError!! Copy-file command must have 2 arguments");
    f1=fopen(argv[1],"r");
    f2=fopen(argv[2],"w");
    if(f1==NULL)
    printf("\nError! Unable to open file : %s",argv[1]);
    if(f2==NULL)
    printf("\nError! Unable to open file : %s",argv[2]);
    while(fscanf(f1,"%c",&c)!=EOF)
	{
        fprintf(f2,"%c",c);
    }
    printf("\nFile Successfully Copied.");
    fclose(f1);
    fclose(f2);
}
