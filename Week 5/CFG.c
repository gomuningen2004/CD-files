#include <stdio.h>
#include <conio.h>
#include <ctype.h>

struct production {
    char starting_symbol;
    char non_terminal;
    char rule[20];
} productions[15];

int main() {
    int i, j, n;

    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions:\n");

    // Initialize starting symbol flag
    int starting_symbol_set = 0;

    for (i = 0; i < n; i++) {
        printf("Enter the non-terminal: ");
        scanf(" %c", &productions[i].non_terminal);

        // If starting symbol is not set yet, set it to the current non-terminal
        if (!starting_symbol_set) {
            productions[i].starting_symbol = productions[i].non_terminal;
            starting_symbol_set = 1;
        }

        printf("Enter the RHS production: ");
        scanf("%s", productions[i].rule);

        // Update starting symbol for subsequent productions
        if (i > 0) {
            productions[i].starting_symbol = productions[i - 1].starting_symbol;
        }
    }

    printf("\nEntered productions are:\n");
    for (i = 0; i < n; i++) {
        printf("%c -> %s\n", productions[i].non_terminal, productions[i].rule);
        printf("The starting symbol of the production is: %c\n", productions[i].starting_symbol);
    }

    printf("\nThe non-terminals are:");
    for (i = 0; i < n; i++) {
        printf(" %c", productions[i].non_terminal);
    }

    printf("\nThe terminals are:");
    for (i = 0; i < n; i++) {
        for (j = 0; productions[i].rule[j] != '\0'; j++) {
            if (!isupper(productions[i].rule[j]) && productions[i].rule[j] != '/') {
                printf(" %c", productions[i].rule[j]);
            }
        }
    }

    getch();
    return 0;
}
