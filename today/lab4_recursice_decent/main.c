#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[100];
int pos = 0;

// Function declarations
void E();
void Edash();
void T();
void Tdash();
void F();
void error();

// Utility: check current symbol
char peek() {
    return input[pos];
}

// Match a terminal symbol
void match(char expected) {
    if (input[pos] == expected) {
        pos++;
    } else {
        error();
    }
}

// E → T E'
void E() {
    printf("E → T E'\n");
    T();
    Edash();
}

// E' → + T E' | ε
void Edash() {
    if (peek() == '+') {
        printf("E' → + T E'\n");
        match('+');
        T();
        Edash();
    } else {
        printf("E' → ε\n");
    }
}

// T → F T'
void T() {
    printf("T → F T'\n");
    F();
    Tdash();
}

// T' → * F T' | ε
void Tdash() {
    if (peek() == '*') {
        printf("T' → * F T'\n");
        match('*');
        F();
        Tdash();
    } else {
        printf("T' → ε\n");
    }
}

// F → (E) | id
void F() {
    if (peek() == '(') {
        printf("F → (E)\n");
        match('(');
        E();
        if (peek() == ')')
            match(')');
        else
            error();
    } else if (peek() == 'i') { // assuming id starts with 'i'
        printf("F → id\n");
        match('i');
        if (peek() == 'd')
            match('d'); // match 'id'
    } else {
        error();
    }
}

// Error handler
void error() {
    printf("❌ Syntax Error at position %d (near '%c')\n", pos, input[pos]);
    exit(0);
}

int main() {
    printf("Enter an input string (e.g., id+id*id): ");
    scanf("%s", input);
    strcat(input, "$"); // End marker

    E(); // Start symbol

    if (input[pos] == '$')
        printf("✅ Parsing Successful!\n");
    else
        printf("❌ Parsing Failed (extra input found).\n");

    return 0;
}

// give input; id+id*id
