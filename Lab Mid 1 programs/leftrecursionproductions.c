#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    char p[20][20], a[20][20], b[20][20];
    int i, j, k, n;
    
    printf("enter the number of productions:");
    scanf("%d", &n);
    
    printf("enter %d productions:", n);
    for(k = 0; k < n; k++)
    {
        gets(p[k]);
    }
    
    for(k = 0; k < n; k++)
    {
        if(p[k][0] == p[k][3])
        {
            printf("\nentered production is left recursive");
            i = 4;
            j = 0;
            
            while(p[k][i] != '/')
            {
                a[k][j++] = p[k][i++];
            }
            a[k][j] = '\0';
            i++;
            j = 0;
            
            while(p[k][i] != '\0')
            {
                b[k][j++] = p[k][i++];
            }
            b[k][j] = '\0';
            
            printf("\nthe production %d after removing the left productions is:\n", k + 1);
            printf("\n%c->%s%c'", p[k][0], b[k], p[k][0]);
            printf("\n%c'->%s%c'/$", p[k][0], a[k], p[k][0]);
        }
        else
        {
            printf("\nentered production %d is not left recursive", k + 1);
        }
    }
}
