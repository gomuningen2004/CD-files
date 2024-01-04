#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isIdentifier(const char *str)
{
    if (*str == '\0') return 0;

    if (!isalpha((unsigned char)*str) && *str != '_') return 0;

    while (*str)
    {
        if (!isalnum((unsigned char)*str) && *str != '_') return 0;
        str++;
    }

    return 1;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    if (isIdentifier(input)) {
        printf("'%s' is a valid identifier.\n", input);
    } else {
        printf("'%s' is not a valid identifier.\n", input);
    }

    return 0;
}
