#include <stdio.h>
#include <ctype.h>

int determineType(char str[]) {
    int state = 0;
    int i = 0;

    if (isalpha(str[0])) {
        state = 1;
    } else if (isdigit(str[0])) {
        state = 2;
    } else {
        state = 10;
    }

    while (str[i] != '\0') {
        switch (state) {
            case 1:
                if (isalnum(str[i])) {
                    state = 1;
                } else if (str[i] == '(') {
                    state = 3;
                } else if (str[i] == '[') {
                    state = 5;
                } else {
                    state = 10;
                }
                break;

            case 2:
                if (isdigit(str[i])) {
                    state = 2;
                } else if (str[i] == '.' && isdigit(str[i + 1])) {
                    state = 4;
                } else {
                    state = 10;
                }
                break;

            case 3:
                if (str[i] == ')' && str[i + 1] == '\0') {
                    state = 6;
                } else {
                    state = 10;
                }
                break;

            case 4:
                if (isdigit(str[i])) {
                    state = 4;
                } else {
                    state = 10;
                }
                break;

            case 5:
                if (isdigit(str[i])) {
                    state = 5;
                } else if (str[i] == ']' && str[i + 1] == '\0') {
                    state = 7;
                } else {
                    state = 10;
                }
                break;
        }

        i++;

        if (state == 10) {
            break;
        }
    }

    return state;
}

int main() {
    char str[20];

    printf("Enter the string: ");
    gets(str);

    int type = determineType(str);

    printf("%s\n", str);

    switch (type) {
        case 1:
            printf("Variable.\n");
            break;
        case 2:
            printf("Integer constant.\n");
            break;
        case 4:
            printf("Real constant.\n");
            break;
        case 6:
            printf("Function.\n");
            break;
        case 7:
            printf("Array.\n");
            break;
        default:
            printf("Not a valid expression.\n");
            break;
    }

    return 0;
}
