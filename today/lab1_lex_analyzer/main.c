#include <stdio.h>

// Function declaration (defined in another file)
int compute(int a, int b);

int main() {
    int a = 5, b = 10, c;

    // assign to c using function from another file
    c = compute(a, b);

    printf("Result = %d\n", c);
    return 0;
}
