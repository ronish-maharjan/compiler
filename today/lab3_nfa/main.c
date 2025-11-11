#include <stdio.h>
#include <string.h>

// Function to simulate the NFA
int isAcceptedByNFA(char *input) {
    int currentStates[2] = {1, 0}; // state 0 active initially
    int nextStates[2];
    int i, j;
    int len = strlen(input);

    for (i = 0; i < len; i++) {
        char ch = input[i];
        // reset next states
        for (j = 0; j < 2; j++)
            nextStates[j] = 0;

        // For each active state, compute next states
        if (currentStates[0]) { // q0 active
            if (ch == 'a' || ch == 'b')
                nextStates[0] = 1; // stay in q0
            else if (ch == 'c')
                nextStates[1] = 1; // move to q1
            else
                return 0; // invalid input
        }

        // copy nextStates → currentStates
        for (j = 0; j < 2; j++)
            currentStates[j] = nextStates[j];
    }

    // accept if final state q1 is active
    return currentStates[1];
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (isAcceptedByNFA(input))
        printf("String is accepted by the NFA.\n");
    else
        printf("String is NOT accepted by the NFA.\n");

    return 0;
}
