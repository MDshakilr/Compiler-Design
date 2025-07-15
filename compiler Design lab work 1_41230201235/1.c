

//  Check keyword or identifier



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isKeyword(const char buffer[])


{
    const char* keywords[32] =
    {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for",
        "goto", "if","int", "long", "register","return", "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void", "volatile",
        "while"
    };

    for (int i = 0; i < 32; i++)
    {
        if (strcmp(keywords[i], buffer) == 0)

        {
            return 1;
        }
    }

    return 0;
}



int main()

{
    FILE *fp;
    char word[50];

    fp = fopen("hi.txt", "r");
    if (fp == NULL)

    {
        printf("Error opening file!\n");
        return 1;
    }

    else

    {
        printf("File opened successfully!\n\n");
    }

    while (fscanf(fp, "%s", word) != EOF)

    {
        if (isKeyword(word))

        {
            printf("\"%s\" is a Keyword\n", word);
        }

        else

        {
            printf("\"%s\" is an Identifier\n", word);
        }
    }
    fclose(fp);
    return 0;
}
