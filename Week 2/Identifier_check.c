#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isIdentifier(const char *str) {
    if (*str == '\0' || !isalpha((unsigned char)*str) && *str != '_') {
        return 0;
    }

    while (*++str) {
        if (!isalnum((unsigned char)*str) && *str != '_') {
            return 0;
        }
    }

    return 1;
}

int isArray(const char *str) {
    int len = strlen(str);
    return (len >= 3 && str[len - 1] == ']' && strchr(str, '[') != NULL);
}

int isFunction(const char *str) {
    int len = strlen(str);
    return (len >= 2 && str[len - 1] == ')' && strchr(str, '(') != NULL);
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    if (isIdentifier(input)) {
        printf("'%s' is a valid identifier.\n", input);
    } else if (isArray(input)) {
        printf("'%s' is an array.\n", input);
    } else if (isFunction(input)) {
        printf("'%s' is a function.\n", input);
    } else {
        printf("'%s' is not a valid identifier, array, or function.\n", input);
    }

    return 0;
}
