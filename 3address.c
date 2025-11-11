#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tempCount = 1;  // Temporary variable counter

// Function to generate a new temporary variable name
char *newTemp() {
    static char temp[3];
    sprintf(temp, "t%d", tempCount++);
    return temp;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    char expr[100];
    char stack[100][10];  // Stack to hold operands and temporaries
    int top = -1;

    printf("Enter a simple arithmetic expression (postfix): ");
    scanf("%s", expr);

    printf("\nThree Address Code (TAC):\n");
    printf("---------------------------------\n");

    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];

        if (isalnum(c)) {  // Operand (variable or number)
            char temp[2] = {c, '\0'};
            strcpy(stack[++top], temp);
        } else if (isOperator(c)) {
            // Pop two operands
            char op2[10], op1[10];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);

            // Generate new temporary variable
            char *tempVar = newTemp();

            // Print TAC instruction
            printf("%s = %s %c %s\n", tempVar, op1, c, op2);

            // Push result back onto stack
            strcpy(stack[++top], tempVar);
        }
    }

    printf("---------------------------------\n");
    printf("Final Result stored in: %s\n", stack[top]);
    return 0;
}
//give input: ab*c+
