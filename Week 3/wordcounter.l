%{
#include <stdio.h>
#include <string.h>

int wordcount = 0;
%}

%%
([a-zA-Z0-9])* { wordcount++; }
"\n" {
printf("Total number of words: %d\n", wordcount);
wordcount = 0;
printf("Enter a sentence:\n");
}
%%

int main() {
printf("Enter a sentence:\n");
yylex();
return 0;
}

int yywrap() {
return 1;
}