#include <stdio.h>
#include <conio.h>
int main()
{
    char a[5];
    int i, flag = 0, length;

    printf("Enter a binary string: ");
    scanf("%s", a);

    for (length = 0; a[length] != '\0'; length++);

    for (i = 0; i < length - 2; i++)
    {
        if (a[i] == '1' && a[i + 1] == '0' && a[i + 2] == '1')
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("String contains '101' as substring.");
    }
    else
    {
        printf("String doesn't contain '101' as substring.");
    }

    return 0;
}
