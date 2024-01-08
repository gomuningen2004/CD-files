%{
#include <stdio.h>

int linecount = 0, spacecount = 0, tabcount = 0;
%}

%%
[\n] { linecount++; }
[ \t] { spacecount++; }
[^\t] { tabcount++; }
%%

int main() {
yylex();
printf("Number of lines: %d\n", linecount);
printf("Number of spaces: %d\n", spacecount);
printf("Number of tabs: %d\n", tabcount);
return 0;
}

int yywrap() {
    return 1;
}
