#include <stdio.h>
#include <string.h>

int isSpecialSymbol(char ch) {
    return (ch == ';' || ch == ',' || ch == '(' || ch == ')' ||
            ch == '{' || ch == '}' || ch == '[' || ch == ']');
}

int main() {
    FILE *fp;
    char code[5000] = {0};

    fp = fopen("code.txt", "r");
    if (!fp) {
        printf("❌ Could not open file\n");
        return 1;
    }
    fread(code, 1, 4999, fp);
    fclose(fp);

    int specialSymbolCount = 0;

    printf("Special Symbols:\n");
    for (int i = 0; code[i] != '\0'; i++) {
        if (isSpecialSymbol(code[i])) {
            printf("  %c\n", code[i]);
            specialSymbolCount++;
        }
    }

    printf("Total Special Symbols: %d\n", specialSymbolCount);
    return 0;
}

