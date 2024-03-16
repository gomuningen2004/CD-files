#include <stdio.h>

void removeLeftFactoring(char prod[20][20], int n) {
    char alpha[10][10], beta1[10][10], beta2[10][10];
    int i, j, k;

    for (int x = 0; x < n; x++) {
        if (prod[x][2] == '-') {
            i = 4;
            j = 0;

            while (prod[x][i] != '/' && prod[x][j] != '\0' && prod[x][i] == prod[x][j]) {
                alpha[x][j] = prod[x][i];
                i++;
                j++;
            }
            alpha[x][j] = '\0';

            k = 0;
            while (prod[x][i] != '/' && prod[x][i] != '\0') {
                beta1[x][k++] = prod[x][i++];
            }
            beta1[x][k] = '\0';

            k = 0;
            if (prod[x][i] == '/') {
                i++;
                while (prod[x][i] != '\0') {
                    beta2[x][k++] = prod[x][i++];
                }
                beta2[x][k] = '\0';
            } else {
                beta2[x][0] = '$';
                beta2[x][1] = '\0';
            }

            printf("\n%c->%s%c'\n", prod[x][0], alpha[x], prod[x][0]);
            printf("%c'->%s/%s\n", prod[x][0], beta1[x], beta2[x]);
        } else {
            printf("The production %s is not in the correct format.\n", prod[x]);
        }
    }
}

int main() {
    char prod[20][20];
    int n;

    printf("Enter the number of productions: ");
    scanf("%d", &n);

    printf("Enter the %d productions: \n", n);
    getchar(); // Consume newline character left in buffer
    for (int i = 0; i < n; i++) {
        fgets(prod[i], 20, stdin);
    }

    removeLeftFactoring(prod, n);

    return 0;
}
