#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
    char p[20], a[20], b[20];
    int i = 4, j = 0; // Initialized i and j directly

    printf("enter the production:");
    gets(p);

    if(p[0] == p[3])
    {
        printf("\nentered production is left recursive");

        while(p[i] != '/')
        {
            a[j++] = p[i++];
        }
        a[j] = '\0';
        i++; // Move to skip '/'
        j = 0;
        while(p[i] != '\0')
        {
            b[j++] = p[i++];
        }
        b[j] = '\0';

        printf("\nthe production after removing the left productions is:\n");
        printf("\n%c->%s%c'", p[0], b, p[0]);
        printf("\n%c'->%s%c'/$", p[0], a, p[0]);
    }
    else
    {
        printf("entered production is not left recursive");
    }
}
