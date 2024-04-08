%{
#include <stdio.h>
%}

/* Regular Definitions */
DIGIT       [0-9]
LETTER      [a-zA-Z]
ID          {LETTER}({LETTER}|{DIGIT})*
NUMBER      {DIGIT}+(\.{DIGIT}+)?

/* Tokens */
%%
"if"        { printf("IF\n"); }
"else"      { printf("ELSE\n"); }
"while"     { printf("WHILE\n"); }
"for"       { printf("FOR\n"); }
"int"       { printf("INT\n"); }
"float"     { printf("FLOAT\n"); }
"char"      { printf("CHAR\n"); }
{ID}        { printf("IDENTIFIER: %s\n", yytext); }
{NUMBER}    { printf("NUMBER: %s\n", yytext); }
"+"         { printf("PLUS\n"); }
"-"         { printf("MINUS\n"); }
"*"         { printf("MULTIPLY\n"); }
"/"         { printf("DIVIDE\n"); }
"="         { printf("ASSIGN\n"); }
";"         { printf("SEMICOLON\n"); }
"("         { printf("LEFT_PAREN\n"); }
")"         { printf("RIGHT_PAREN\n"); }
"{"         { printf("LEFT_BRACE\n"); }
"}"         { printf("RIGHT_BRACE\n"); }
","         { printf("COMMA\n"); }
"=="        { printf("EQUALS\n"); }
"!="        { printf("NOT_EQUALS\n"); }
"<"         { printf("LESS_THAN\n"); }
"<="        { printf("LESS_THAN_OR_EQUAL\n"); }
">"         { printf("GREATER_THAN\n"); }
">="        { printf("GREATER_THAN_OR_EQUAL\n"); }
.           {}

%%
int main(int argc, char **argv) {
    yyin = fopen(argv[1], "r");
    yylex();
    fclose(yyin);
    return 0;
}

int yywrap() {
    return 1;  // Indicate end of input
}