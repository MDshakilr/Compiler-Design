//file read
#include<stdio.h>
#include <string.h>
int main()
{
    FILE *x;
    char ch;


    x = fopen("test3_forread.txt","r");

    while(!feof(x))
    {
        ch=fgetc(x);
        printf("%c",ch);
    }

    fclose(x);//close file

}


