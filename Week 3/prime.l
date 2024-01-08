%{
#include <stdio.h>
#include <stdbool.h>

bool isprime(int num) {
if (num <= 1) {
return false;
}
for (int i = 2; i * i <= num; ++i) {
if (num % i == 0) {
return false;
}
}
return true;
}

%}

%%
[0-9]+ {
int num = atoi(yytext);
if (isprime(num)) {
printf("%d is a prime number.\n", num);
} else {
printf("%d isn't a prime number.\n", num);
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