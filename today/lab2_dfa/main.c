#include <stdio.h>
#include <string.h>

// Function to simulate the DFA
int isAccepted(char *input) {
    int state = 0; // start state = q0
    int i = 0;

    while (input[i] != '\0') {
        char ch = input[i];

        switch (state) {
            case 0: // q0
                if (ch == 'a' || ch == 'b') {
                    state = 0; // stay in q0
                } else if (ch == 'c') {
                    state = 1; // move to q1
                } else {
                    return 0; // invalid symbol
                }
                break;

            case 1: // q1 (accepting)
                // After reaching q1, no more symbols should come
                return 0;
        }
        i++;
    }

    // Accept if final state is q1
    return (state == 1);
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isAccepted(input))
        printf("String is accepted by the DFA.\n");
    else
        printf("String is NOT accepted by the DFA.\n");

    return 0;
}
