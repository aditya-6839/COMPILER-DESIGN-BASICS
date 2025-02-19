#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKEN_LENGTH 100

void lexicalAnalysis(char *input) {
    int i = 0;
    char token[MAX_TOKEN_LENGTH];
    int tokenIndex = 0;
    while (input[i] != '\0') {
        if (isspace(input[i])) {
            i++;
            continue;
        }
        if (isalpha(input[i])) {
            tokenIndex = 0;
            while (isalnum(input[i])) {
                token[tokenIndex++] = input[i++];
            }
            token[tokenIndex] = '\0';
            printf("Identifier: %s\n", token);
        } else if (isdigit(input[i])) {
            tokenIndex = 0;
            while (isdigit(input[i])) {
                token[tokenIndex++] = input[i++];
            }
            token[tokenIndex] = '\0';
            printf("Number: %s\n", token);
        } else {
            printf("Symbol: %c\n", input[i]);
            i++;
        }
    }
}

void syntaxAnalysis(char *input) {
    int len = strlen(input);
    if (len > 0 && isalpha(input[0])) {
        printf("Valid syntax\n");
    } else {
        printf("Invalid syntax\n");
    }
}

void semanticAnalysis(char *input) {
    if (strstr(input, "int") || strstr(input, "float") || strstr(input, "char")) {
        printf("Valid semantics\n");
    } else {
        printf("Invalid semantics\n");
    }
}

int main() {
    char input[MAX_TOKEN_LENGTH];
    printf("Enter input code: ");
    fgets(input, MAX_TOKEN_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;
    printf("Lexical Analysis:\n");
    lexicalAnalysis(input);
    printf("Syntax Analysis:\n");
    syntaxAnalysis(input);
    printf("Semantic Analysis:\n");
    semanticAnalysis(input);
    return 0;
}
