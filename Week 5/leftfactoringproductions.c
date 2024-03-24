#include<stdio.h>
#include<stdlib.h>

void main()
{
    char p[20][20], a[10][10], b1[10][10], b2[10][10];
    int i, j, k, x, n;

    printf("enter the number of productions:");
    scanf("%d", &n);
    printf("enter the %d productions:", n);

    for(i = 0; i < n; i++) // Corrected loop condition to avoid reading an extra production
    {
        gets(p[i]);
    }

    for(x = 0; x < n; x++) // Changed loop condition to iterate over valid indices
    {
        if(p[x][1] == '-' && p[x][2] == '>')
        {
            i = 3;
            j = 0;
            
            while(p[x][j] != '/')
            {
                j++;
            }
            j++;
            k = 0;
            
            while(p[x][i] == p[x][j])
            {
                a[x][k++] = p[x][i++];
                j++;
            }
            a[x][k] = '\0';
            k = 0;
            
            while(p[x][i] != '/')
            {
                b1[x][k++] = p[x][i++];
            }
            b1[x][k] = '\0';
            k = 0;
            
            if(p[x][j] == '\0')
            {
                b2[x][k++] = '$';
                b2[x][k] = '\0';
            }
            else
            {
                while(p[x][j] != '\0')
                {
                    b2[x][k++] = p[x][j++];
                }
                b2[x][k] = '\0';
            }
            
            printf("\n%c->%s%c'\n", p[x][0], a[x], p[x][0]);
            printf("%c'->%s/%s", p[x][0], b1[x], b2[x]);
        }
        else
        {
            printf("\nthe production %d is not in the correct format", x + 1); // Added +1 to display the correct production number
        }
    }
}
