#include <stdio.h>
#include <string.h>

int isOperatorChar(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '%' || ch == '=' || ch == '<' || ch == '>' ||
            ch == '!' || ch == '&' || ch == '|');
}

int main() {
    FILE *fp;
    char code[5000] = {0};

    fp = fopen("code.txt", "r");
    if (!fp) {
        printf(" Could not open file\n");
        return 1;
    }
    fread(code, 1, 4999, fp);
    fclose(fp);

    int operatorCount = 0;

    printf("Operators:\n");
    for (int i = 0; code[i] != '\0';) {
        if (isOperatorChar(code[i])) {
            if ((code[i] == '+' && code[i+1] == '+') ||
                (code[i] == '-' && code[i+1] == '-') ||
                (code[i] == '=' && code[i+1] == '=') ||
                (code[i] == '!' && code[i+1] == '=') ||
                (code[i] == '&' && code[i+1] == '&') ||
                (code[i] == '|' && code[i+1] == '|') ||
                (code[i] == '<' && code[i+1] == '=') ||
                (code[i] == '>' && code[i+1] == '=')) {
                printf("  %c%c\n", code[i], code[i+1]);
                operatorCount++;
                i += 2;
                continue;
            } else {
                printf("  %c\n", code[i]);
                operatorCount++;
            }
        }
        i++;
    }

    printf("Total Operators: %d\n", operatorCount);
    return 0;
}

