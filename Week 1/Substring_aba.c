#include <stdio.h>

int main() {
    char a[6];
    int i, flag = 0;

    printf("Enter only a's and b's: ");
    scanf("%s", a);

    for (i = 0; a[i + 2] != '\0'; i++) {
        if (a[i] == 'a' && a[i + 1] == 'b' && a[i + 2] == 'a') {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("String contains 'aba' as substring\n");
    } else {
        printf("String doesn't contain 'aba' as substring\n");
    }

    return 0;
}
