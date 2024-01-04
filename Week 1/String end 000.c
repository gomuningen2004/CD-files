#include <stdio.h>

int main()
{
    char a[5];
    int length;

    printf("Enter only 1s and 0s : ");
    scanf("%s", a);
    
    for (length = 0; a[length] != '\0'; length++);

    if (length >= 3 && a[length - 3] == '0' && a[length - 2] == '0' && a[length - 1] == '0')
    {
        printf("String ends with 000");
    }
    else
    {
        printf("String doesn't end with 000");
    }

    return 0;
}
