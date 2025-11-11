#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

// Structure for DFA states
typedef struct {
    int states[MAX];
    int count;
    int isFinal;
} DFAState;

// Follow positions
int followpos[10][10];
int followCount[10];

// Positions for each symbol
int posA[10], posB[10], posC[10];
int countA = 0, countB = 0, countC = 0;

// Helper function to print state
void printState(DFAState s) {
    printf("{ ");
    for (int i = 0; i < s.count; i++)
        printf("%d ", s.states[i]);
    printf("}");
}

// Check if position is in state
int contains(DFAState s, int x) {
    for (int i = 0; i < s.count; i++)
        if (s.states[i] == x)
            return 1;
    return 0;
}

// Compute union of follow positions
DFAState move(DFAState s, char ch) {
    DFAState next = { .count = 0, .isFinal = 0 };
    for (int i = 0; i < s.count; i++) {
        int pos = s.states[i];
        if ((ch == 'a' && pos == 1) ||
            (ch == 'b' && pos == 2) ||
            (ch == 'c' && pos == 3)) {
            for (int j = 0; j < followCount[pos]; j++) {
                int f = followpos[pos][j];
                if (!contains(next, f))
                    next.states[next.count++] = f;
            }
        }
    }
    // If # (position 4) is included, mark final
    for (int i = 0; i < next.count; i++)
        if (next.states[i] == 4)
            next.isFinal = 1;

    return next;
}

int main() {
    // For RE: (a|b)*c#
    // Positions: a=1, b=2, c=3, #=4

    // Define followpos manually (for demonstration)
    // followpos(1) and followpos(2) from (a|b)* loop to {1,2,3}
    followpos[1][0] = 1; followpos[1][1] = 2; followpos[1][2] = 3; followCount[1] = 3;
    followpos[2][0] = 1; followpos[2][1] = 2; followpos[2][2] = 3; followCount[2] = 3;
    // followpos(3) = {4}
    followpos[3][0] = 4; followCount[3] = 1;

    // Initial state = firstpos(root) = {1,2,3}
    DFAState start = { .states = {1, 2, 3}, .count = 3, .isFinal = 0 };
    DFAState nextA = move(start, 'a');
    DFAState nextB = move(start, 'b');
    DFAState nextC = move(start, 'c');

    printf("\nDFA States and Transitions for (a|b)*c#\n");
    printf("----------------------------------------\n");
    printf("Start State: ");
    printState(start);
    printf("\n");

    printf("\nOn input 'a' → ");
    printState(nextA);
    printf("%s\n", nextA.isFinal ? " (Final)" : "");

    printf("On input 'b' → ");
    printState(nextB);
    printf("%s\n", nextB.isFinal ? " (Final)" : "");

    printf("On input 'c' → ");
    printState(nextC);
    printf("%s\n", nextC.isFinal ? " (Final)" : "");

    return 0;
}
