%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%%
    [+-]?[0-9]+(\.[0-9]+)? {
        double num = atof(yytext);
        if (num > 0) {
            printf("%f is a positive number.\n", num);
        } else if (num < 0) {
            printf("%f is a negative number.\n", num);
        } else {
            printf("Number is 0.\n");
        }
    }

    .|\n { }
%%

int main() {
    yylex();
    return 0;
}