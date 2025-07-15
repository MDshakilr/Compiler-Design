#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int isOperatorChar(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '%' || ch == '=' || ch == '<' || ch == '>' ||
            ch == '!' || ch == '&' || ch == '|');
}

int isSpecialSymbol(char ch) {
    return (ch == ';' || ch == ',' || ch == '(' || ch == ')' ||
            ch == '{' || ch == '}' || ch == '[' || ch == ']');
}

int isKeyword(const char buffer[]) {
    const char* keywords[32] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for",
        "goto", "if","int", "long", "register","return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
        "while"
    };
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], buffer) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *fp;
    char code[5000] = {0};
    char word[100];

    fp = fopen("code.txt", "r");
    if (fp == NULL) {
        printf("❌ Error: Could not open code.txt\n");
        return 1;
    }

    fread(code, sizeof(char), 4999, fp);
    code[4999] = '\0';
    fclose(fp);

    int keywordCount = 0, identifierCount = 0;
    int operatorCount = 0, specialSymbolCount = 0;

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
                i++;
                continue;
            }
        }
        i++;
    }

    printf("\nSpecial Symbols:\n");
    for (int i = 0; code[i] != '\0'; i++) {
        if (isSpecialSymbol(code[i])) {
            printf("  %c\n", code[i]);
            specialSymbolCount++;
        }
    }

    printf("\nKeywords and Identifiers:\n");
    int len = strlen(code);
    int idx = 0;
    int wordIdx = 0;

    while (idx <= len) {
        char ch = code[idx];

        if (isalnum(ch) || ch == '_') {
            word[wordIdx++] = ch;
        } else {
            if (wordIdx > 0) {
                word[wordIdx] = '\0';

                if (isKeyword(word)) {
                    printf("  \"%s\" is a Keyword\n", word);
                    keywordCount++;
                } else {
                    printf("  \"%s\" is an Identifier\n", word);
                    identifierCount++;
                }
                wordIdx = 0;
            }
        }
        idx++;
    }

    printf("\nSummary:\n");
    printf("Total Operators: %d\n", operatorCount);
    printf("Total Special Symbols: %d\n", specialSymbolCount);
    printf("Total Keywords: %d\n", keywordCount);
    printf("Total Identifiers: %d\n", identifierCount);

    int totalTokens = keywordCount + identifierCount + specialSymbolCount + operatorCount;
    printf("Total Tokens (Keywords + Identifiers + Special Symbols + Operators): %d\n", totalTokens);

    return 0;
}
