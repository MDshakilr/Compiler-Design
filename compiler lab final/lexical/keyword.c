#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(const char buffer[]) {
    const char* keywords[32] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for",
        "goto", "if","int", "long", "register","return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
        "while"
    };
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], buffer) == 0) return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char code[5000] = {0};
    char word[100];

    fp = fopen("code.txt", "r");
    if (!fp) {
        printf("❌ Could not open file\n");
        return 1;
    }
    fread(code, 1, 4999, fp);
    fclose(fp);

    int keywordCount = 0;
    int len = strlen(code);
    int idx = 0, wordIdx = 0;

    printf("Keywords:\n");
    while (idx <= len) {
        char ch = code[idx];
        if (isalnum(ch) || ch == '_') {
            word[wordIdx++] = ch;
        } else {
            if (wordIdx > 0) {
                word[wordIdx] = '\0';
                if (isKeyword(word)) {
                    printf("  %s\n", word);
                    keywordCount++;
                }
                wordIdx = 0;
            }
        }
        idx++;
    }

    printf("Total Keywords: %d\n", keywordCount);
    return 0;
}

