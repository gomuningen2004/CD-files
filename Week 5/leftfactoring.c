#include<stdio.h>
#include<stdlib.h>

void main()
{
    char p[20], a[10], b1[10], b2[10];
    int i, j, k;

    printf("enter the production:");
    gets(p);

    if(p[1] == '-' && p[2] == '>')
    {
        i = 3;
        j = 0;

        while(p[j] != '/')
        {
            j++;
        }
        j++;
        k = 0;

        while(p[i] == p[j])
        {
            a[k++] = p[i++];
            j++;
        }
        a[k] = '\0';
        k = 0;

        while(p[i] != '/')
        {
            b1[k++] = p[i++];
        }
        b1[k] = '\0';
        k = 0;

        if(p[j] == '\0')
        {
            b2[k++] = '$';
            b2[k] = '\0';
        }
        else
        {
            while(p[j] != '\0')
            {
                b2[k++] = p[j++];
            }
            b2[k] = '\0';
        }

        printf("\n%c->%s%c'\n", p[0], a, p[0]);
        printf("%c'->%s/%s", p[0], b1, b2);
    }
    else
    {
        printf("the production is not the correct format");
    }
}
