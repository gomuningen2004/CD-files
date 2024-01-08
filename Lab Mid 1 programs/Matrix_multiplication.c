#include<stdio.h>

int main() {
    int r, c, i, j, m, n, o, S = 0;
    
    printf("Enter required number of rows & columns of first matrix ");
    scanf("%d %d", &r, &c);
    
    printf("Enter required number of rows & columns of second matrix ");
    scanf("%d %d", &m, &n);
    
    int a[r][c], b[m][n];
    
    if(c != m) {
        printf("The matrices can't be multiplied.");
    } else {
        printf("Enter elements of first matrix\n");
        for(i = 0; i < r; i++) {
            for(j = 0; j < c; j++) {
                scanf("%d", &a[i][j]);
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        
        printf("Enter elements of second matrix\n");
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                scanf("%d", &b[i][j]);
                printf("%d ", b[i][j]);
            }
            printf("\n");
        }
        
        int d[i][j];
        
        printf("Product of matrices is\n");
        for(i = 0; i < r; i++) {
            for(j = 0; j < n; j++) {
                for(o = 0; o < c; o++) {
                    S = S + (a[i][o] * b[o][j]);
                }
                d[i][j] = S;
                printf("%d\t", d[i][j]);
                S = 0;
            }
            printf("\n");
        }
    }
    
    return 0;
}
