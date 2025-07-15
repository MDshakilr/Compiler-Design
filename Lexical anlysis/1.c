
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Check if character is a single-character operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '%' || ch == '=' || ch == '<' || ch == '>' ||
            ch == '!' || ch == '&' || ch == '|');
}

// Check if character is a special symbol
int isSpecialSymbol(char ch) {
    return (ch == ';' || ch == ',' || ch == '(' || ch == ')' ||
            ch == '{' || ch == '}' || ch == '[' || ch == ']');
}

void lexicalAnalysis(char *code) {
    int i = 0;
    int totalOperators = 0, totalSpecialSymbols = 0;

    printf("Operators:\n");
    while (code[i] != '\0') {
        // Check for double-character operators first (e.g., ++, ==)
        if (isOperator(code[i])) {
            if ((code[i] == '+' && code[i + 1] == '+') ||
                (code[i] == '-' && code[i + 1] == '-') ||
                (code[i] == '=' && code[i + 1] == '=') ||
                (code[i] == '!' && code[i + 1] == '=') ||
                (code[i] == '&' && code[i + 1] == '&') ||
                (code[i] == '|' && code[i + 1] == '|') ||
                (code[i] == '<' && code[i + 1] == '=') ||
                (code[i] == '>' && code[i + 1] == '=')) {
                printf("  %c%c\n", code[i], code[i + 1]);
                i += 2;
                totalOperators++;
                continue;
            } else {
                // Single operator
                printf("  %c\n", code[i]);
                totalOperators++;
            }
        }
        // Count special symbols
        else if (isSpecialSymbol(code[i])) {
            totalSpecialSymbols++;
        }
        i++;
    }

    printf("\nSpecial Symbols:\n");
    i = 0;
    while (code[i] != '\0') {
        if (isSpecialSymbol(code[i])) {
            printf("  %c\n", code[i]);
        }
        i++;
    }

    printf("\nTotal Operators: %d\n", totalOperators);
    printf("Total Special Symbols: %d\n", totalSpecialSymbols);
}

int main() {
    FILE *fp;
    char code[1000] = {0};  // initialize to zero for safety

    // Open file "code.txt" (adjust filename if needed)
    fp = fopen("code.txt", "r");
    if (fp == NULL) {
        printf("❌ Error: Could not open code.txt\n");
        return 1;
    }

    // Read file content safely, stopping at EOF or 999 chars
    fread(code, sizeof(char), 999, fp);
    code[999] = '\0';  // ensure null termination
    fclose(fp);

    // Run lexical analysis on read code
    lexicalAnalysis(code);

    return 0;
}
