%{
int vowels = 0;
int consonants = 0;
int lines = 0;
%}

%%

[aAeEiIoOuU]   { vowels++; }
[a-zA-Z]       { consonants++; }
\n             { lines++; }

%%

int main() {
    yylex();
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of lines: %d\n", lines + 1); // Add 1 to account for the last line
    return 0;
}

int yywrap() {
    return 1;  // Indicate end of input
}