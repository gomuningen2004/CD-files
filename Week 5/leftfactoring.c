#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char prod[20][20], alpha[20][20], beta[20][20];
    int i, j, k, n;
    
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter %d productions:\n", n);
    getchar(); // Consume the newline character left in the input buffer
    
    for(k = 1; k <= n; k++) {
        fgets(prod[k], sizeof(prod[k]), stdin);
        prod[k][strlen(prod[k]) - 1] = '\0'; // Remove the newline character
    }
    
    for(k = 1; k <= n; k++) {
        if(prod[k][0] == prod[k][3]) {
            printf("\nProduction %d is left recursive\n", k);
            i = 4;
            j = 0;
            while(prod[k][i] != '/') {
                alpha[k][j++] = prod[k][i++];
            }
            alpha[k][j] = '\0';
            
            i = i + 1;
            j = 0;
            while(prod[k][i] != '\0') {
                beta[k][j++] = prod[k][i++];
            }
            beta[k][j] = '\0';
            
            printf("Production %d after removing the left recursion is:\n", k);
            printf("%c->%s%c'\n", prod[k][0], beta[k], prod[k][0]);
            printf("%c'->%s%c'/$\n", prod[k][0], alpha[k], prod[k][0]);
        } else {
            printf("Production %d is not left recursive\n", k);
        }
    }
    return 0;
}
