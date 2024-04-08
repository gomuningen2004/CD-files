%{
#include <stdio.h>
#include <math.h>
%}

%%
[0-9]+ {
    int n = atoi(yytext);     // Convert matched text to an integer
    int o = n;
    int d = 0;
    int s = 0;

    // Count number of digits in the number
    while (n > 0) {
        n /= 10;
        d++;
    }

    n = o; // Reset n to the original value

    // Calculate sum of each digit raised to the power of the number of digits
    while (n > 0) {
        int v = n % 10;
        s += pow(v, d);
        n /= 10;
    }

    // Check if the sum equals the original number
    if (s == o) {
        printf("%d is an Armstrong number.\n", o);
    } else {
        printf("%d isn't an Armstrong number.\n", o);
    }
    printf("Enter a number: ");
}

[ \t]+                          // Ignore whitespace
.|\n { }                        // Ignore other characters
%%

int main() {
    printf("Enter a number: ");
    yylex();                    // Invoke the lexer
    return 0;
}

int yywrap() {
    return 1;
}
