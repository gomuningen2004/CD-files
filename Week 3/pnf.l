%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
char* fraction = strchr(yytext, '.');
if (fraction != NULL) {
printf("fractional part: %s\n", fraction + 1);
}
printf("Enter a number: ");
}

.|\n { }
%%

int main() {
printf("Enter a number: ");
yylex();
return 0;
}

int yywrap() {
return 1;
}