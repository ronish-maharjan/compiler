#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// List of C keywords
const char *keywords[] = {
    "int", "return", "if", "else", "for", "while",
    "do", "break", "continue", "switch", "case",
    "default", "void", "char", "float", "double",
    "long", "short", "unsigned", "signed", "goto",
    "struct", "typedef", "union", "enum", "const",
    "sizeof", "static", "volatile", "register", "auto",
    "extern"
};
int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

// Function to check if a string is a keyword
int isKeyword(char *str) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Main scanner function
int main() {
    FILE *fp;
    char ch, buffer[MAX_LEN];
    int i = 0;

    fp = fopen("lex-test-your_roll_number.c", "r");

    if (fp == NULL) {
        printf("Error: Cannot open source file!\n");
        return 1;
    }

    printf("Tokens Found in Source Code:\n\n");

    while ((ch = fgetc(fp)) != EOF) {
        // If alphanumeric or underscore (part of identifiers or keywords)
        if (isalnum(ch) || ch == '_') {
            buffer[i++] = ch;
        }
        else if ((ch == ' ' || ch == '\n' || ch == '\t' || ispunct(ch)) && i > 0) {
            buffer[i] = '\0';
            i = 0;

            // Check token type
            if (isKeyword(buffer))
                printf("<KEYWORD, %s>\n", buffer);
            else if (isdigit(buffer[0]))
                printf("<NUMBER, %s>\n", buffer);
            else
                printf("<IDENTIFIER, %s>\n", buffer);
        }

        // Operators and punctuations
        if (ispunct(ch)) {
            switch (ch) {
                case '+': case '-': case '*': case '/': case '=':
                case '<': case '>':
                    printf("<OPERATOR, %c>\n", ch);
                    break;
                case '(': case ')': case '{': case '}':
                case ';': case ',': case '[': case ']':
                    printf("<SYMBOL, %c>\n", ch);
                    break;
            }
        }
    }

    fclose(fp);
    return 0;
}
//gcc lex-test_your_roll_number.c -o program
//gcc scanner.c -o scanner
//./scanner

