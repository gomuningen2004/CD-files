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
    printf("Number of lines: %d", linecount);
    printf("Number of spaces: %d", spacecount);
    printf("Number of tabs: %d", tabcount);
    return 0;
}