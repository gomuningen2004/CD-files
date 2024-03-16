#include<stdio.h>
#include<string.h>
#define SIZE 10

int main() {
    char nt, b, a, p[10][SIZE];
    int n, i = 3;
    
    printf("Enter Number of Production : ");
    scanf("%d", &n);
    
    printf("Enter the grammar as E->E-A :\n");
    for (int j = 0; j < n; j++) {
        scanf("%s", p[j]);
    }
    
    for (int j = 0; j < n; j++) {
        printf("\nGRAMMAR %s", p[j]);
        nt = p[j][0];
        if (nt == p[j][i]) {
            a = p[j][i + 1];
            printf(" is left recursive.\n");
            while (p[j][i] != 0 && p[j][i] != '|')
                i++;
            
            if (p[j][i] != 0) {
                b = p[j][i + 1];
                printf("Grammar without left recursion:\n");
                printf("%c->%c%c'", nt, b, nt);
                printf("\n%c'->%c%c'|E\n", nt, a, nt);
            } else
                printf(" can't be reduced\n");
        } else
            printf(" is not left recursive.\n");
        i = 3;
    }
    
    return 0;
}
