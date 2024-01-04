%{
    #include <stdio.h>
    #include <string.h>

    int wordcount = 0;
%}

%%
    ([a-zA-Z0-9])* { wordcount++; }
    "\n" {
        printf("Total number of words: %d", wordcount);
        wordcount = 0;
    }
%%

int main() {
    yylex();
    return 0;
}