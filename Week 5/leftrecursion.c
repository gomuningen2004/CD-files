#include<stdio.h>
#include<string.h>

int main() {
    char prod[20], alpha[20], beta[20];
    int i, j;
    
    printf("Enter the production: ");
    fgets(prod, sizeof(prod), stdin);
    
    if(prod[0] == prod[3]) {
        printf("\nThe entered production is left recursive.\n");
        i = 4;
        j = 0;
        while(prod[i] != '/') {
            alpha[j++] = prod[i++];
        }
        alpha[j] = '\0';
        
        i = i + 1;
        j = 0;
        while(prod[i] != '\0') {
            beta[j++] = prod[i++];
        }
        beta[j] = '\0';
        
        printf("\nThe production after removing the left recursion is:\n");
        printf("\n%c->%s%c'", prod[0], beta, prod[0]);
        printf("\n%c'->%s%c'/$\n", prod[0], alpha, prod[0]);
    }
    else {
        printf("The entered production is not left recursive.\n");
    }
    
    return 0;
}