%{
    #include <stdio.h>
    #include <math.h>
%}

%%
[0-9]+ {
    int num = atoi(yytext);
    int origin = num;
    int numdigits = 0;
    int sum = 0;

    while (num > 0) {
        num /= 10;
        numdigits++;
    }

    num = origin;

    while (num > 0) {
        int digits = num % 10;
        sum += pow(digits, numdigits);
        num /= 10;
    }

    if (sum == origin) {
        printf("%d is an Armstrong number.\n", origin);
    } else {
        printf("%d isn't an Armstrong number.\n", origin);
    }
}

[ \t]+ 
.|\n { 
    printf("Invalid character: %s\n", yytext);
}
%%

int main() {
    yylex();
    return 0;
}
