


//file open and close
#include<stdio.h>
int main()
{
    FILE *x;


    x = fopen("test1.txt","w");



    fclose(x);//close file

}




//file open and close
#include<stdio.h>
#include <string.h>
int main()
{
    FILE *x;
    char name[100]="shakil raana";
    int length = strlen(name);
    int i;

    x = fopen("test1.txt","w");

    for(i=0;i<length;i++)
    {
        fputc(name[i],x);
    }

    fclose(x);//close file

}
