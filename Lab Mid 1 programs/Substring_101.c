#include <stdio.h>

int main() {
    char a[6];
    int i, flag = 0;

    printf("Enter a binary string: ");
    scanf("%s", a);

    for (i = 0; a[i + 2] != '\0'; i++) {
        if (a[i] == '1' && a[i + 1] == '0' && a[i + 2] == '1') {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("String contains '101' as substring.\n");
    } else {
        printf("String doesn't contain '101' as substring.\n");
    }

    return 0;
}
