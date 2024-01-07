#include <stdio.h>

int main() {
    char a[6];

    printf("Enter only 1s and 0s: ");
    scanf("%s", a);

    int l;
    for (l = 0; a[l] != '\0'; l++);

    if (l >= 3 && a[l - 3] == '0' && a[l - 2] == '0' && a[l - 1] == '0') {
        printf("String ends with 000\n");
    } else {
        printf("String doesn't end with 000\n");
    }

    return 0;
}
