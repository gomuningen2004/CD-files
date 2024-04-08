#include <stdio.h>
#include <ctype.h>

int d(char str[]) {
    int s = 0;
    int i = 0;

    if (isalpha(str[0])) {
        s = 1;
    } else if (isdigit(str[0])) {
        s = 2;
    } else {
        s = 10;
    }

    while (str[i] != '\0') {
        switch (s) {
            case 1:
                if (isalnum(str[i])) {
                    s = 1;
                } else if (str[i] == '(') {
                    s = 3;
                } else if (str[i] == '[') {
                    s = 5;
                } else {
                    s = 10;
                }
                break;

            case 2:
                if (isdigit(str[i])) {
                    s = 2;
                } else if (str[i] == '.' && isdigit(str[i + 1])) {
                    s = 4;
                } else {
                    s = 10;
                }
                break;

            case 3:
                if (str[i] == ')' && str[i + 1] == '\0') {
                    s = 6;
                } else {
                    s = 10;
                }
                break;

            case 4:
                if (isdigit(str[i])) {
                    s = 4;
                } else {
                    s = 10;
                }
                break;

            case 5:
                if (isdigit(str[i])) {
                    s = 5;
                } else if (str[i] == ']' && str[i + 1] == '\0') {
                    s = 7;
                } else {
                    s = 10;
                }
                break;
        }

        i++;

        if (s == 10) {
            break;
        }
    }

    return s;
}

int main() {
    char s[20];

    printf("Enter the string: ");
    gets(s);

    int t = d(s);

    printf("%s\n", s);

    switch (t) {
        case 1:
            printf("%s is a variable.\n", s);
            break;
        case 2:
            printf("%s is an integer constant.\n", s);
            break;
        case 4:
            printf("%s is a real constant.\n", s);
            break;
        case 6:
            printf("%s is a function.\n", s);
            break;
        case 7:
            printf("%s is an array.\n", s);
            break;
        default:
            printf("%s is not a valid expression.\n", s);
            break;
    }

    return 0;
}
