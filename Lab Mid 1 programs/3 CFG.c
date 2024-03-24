#include <stdio.h>
#include <ctype.h>

struct p {
    char n;
    char r[20];
};

int main() {
    struct p p[15];
    int n, i, j;

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions:\n");
    for (i = 0; i < n; i++) {
        printf("Enter the non-terminal: ");
        scanf(" %c", &p[i].n);
        printf("Enter the RHS production: ");
        scanf("%s", p[i].r);
    }

    printf("\nEntered productions are:\n");
    for (i = 0; i < n; i++) {
        printf("%c -> %s\n", p[i].n, p[i].r);
        printf("The starting symbol of the production is: %c\n", p[i].n);
    }

    printf("\nThe non-terminals are: ");
    for (i = 0; i < n; i++) {
        printf("%c ", p[i].n);
    }

    printf("\nThe terminals are: ");
    for (i = 0; i < n; i++) {
        for (j = 0; p[i].r[j] != '\0'; j++) {
            if (!isupper(p[i].r[j]) && p[i].r[j] != '/') {
                printf("%c ", p[i].r[j]);
            }
        }
    }

    return 0;
}
