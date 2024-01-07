#include <stdio.h>

int main() {
    int n, r = 0, o, x;

    printf("Enter an integer: ");
    scanf("%d", &n);

    o = n;

    while (n != 0) {
        x = n % 10;
        r = r * 10 + x;
        n /= 10;
    }

    if (o == r) {
        printf("%d is a palindrome.\n", o);
    } else {
        printf("%d is not a palindrome.\n", o);
    }

    return 0;
}
