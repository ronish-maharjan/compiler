#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Structure for Symbol Table Entry
struct Symbol {
    char name[30];
    char type[10];
    int size;
    int line_no;
};

// Array of symbols
struct Symbol symTable[MAX];
int count = 0;

// Function Declarations
void insert();
int search(char symbol[]);
void deleteSymbol();
void display();

// 1️⃣ Insert a new symbol
void insert() {
    char name[30], type[10];
    int size, line_no;

    printf("Enter symbol name: ");
    scanf("%s", name);

    // Check for duplicates
    if (search(name) != -1) {
        printf("Error: Symbol '%s' already exists!\n", name);
        return;
    }

    printf("Enter type: ");
    scanf("%s", type);
    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter line number: ");
    scanf("%d", &line_no);

    strcpy(symTable[count].name, name);
    strcpy(symTable[count].type, type);
    symTable[count].size = size;
    symTable[count].line_no = line_no;
    count++;

    printf("Symbol inserted successfully!\n");
}

// 2️⃣ Search for a symbol
int search(char symbol[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(symTable[i].name, symbol) == 0)
            return i;
    }
    return -1;
}

// 3️⃣ Delete a symbol
void deleteSymbol() {
    char name[30];
    printf("Enter symbol to delete: ");
    scanf("%s", name);

    int index = search(name);
    if (index == -1) {
        printf("Symbol not found!\n");
        return;
    }

    // Shift elements left
    for (int i = index; i < count - 1; i++) {
        symTable[i] = symTable[i + 1];
    }
    count--;

    printf("Symbol '%s' deleted successfully.\n", name);
}

// 4️⃣ Display the symbol table
void display() {
    if (count == 0) {
        printf("Symbol Table is empty!\n");
        return;
    }

    printf("\n------------------------------------------------------------\n");
    printf("%-15s %-10s %-10s %-10s\n", "Name", "Type", "Size", "Line No");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s %-10s %-10d %-10d\n",
               symTable[i].name,
               symTable[i].type,
               symTable[i].size,
               symTable[i].line_no);
    }
    printf("------------------------------------------------------------\n");
}

// Main driver program
int main() {
    int choice;
    char name[30];

    while (1) {
        printf("\n===== SYMBOL TABLE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            printf("Enter symbol to search: ");
            scanf("%s", name);
            if (search(name) != -1)
                printf("Symbol '%s' found in table.\n", name);
            else
                printf("Symbol '%s' not found.\n", name);
            break;
        case 3:
            deleteSymbol();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
//Enter your choice: 1
//Enter symbol name: x
//Enter type: int
//Enter size: 4
//Enter line number: 3
//Symbol inserted successfully!

//Enter your choice: 1
//Enter symbol name: y
//Enter type: float
//Enter size: 8
//Enter line number: 5
//Symbol inserted successfully!

//Enter your choice: 4
