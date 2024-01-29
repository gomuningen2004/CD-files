%{
#include<stdio.h>
char inputfile[20];
%}

kw      "int"|"float"|"char"|"double"|"if"|"else"|"switch"|"case"|"return"
specialcharacters       [!@#$^&().,;{}()\[\]]
operator        "+"|"-"|"*"|"%"|"<"|"<="|">"|">="|"="|"<>"

%%

{kw}        {printf("\n%s is a keyword", yytext);}
[a-zA-Z][a-zA-Z0-9]*        {printf("\n%s is an identifier", yytext);}
[+-]?[0-9]+(.[0-9]+)?(E[+-]?[0-9]+)?        {printf("\n%s is a numeric literal", yytext);}
{operator}        {printf("\n%s is an operator", yytext);}
{specialcharacters}        {printf("\n%s is a special character", yytext);}
.       {}

%%

int main(){
    printf("Enter input filename with extention: ");
    scanf("%s", inputfile);
    yyin = fopen(inputfile, "r");
    yylex();
    fclose(yyin);
}

int yywrap(){
    return 1;
}
