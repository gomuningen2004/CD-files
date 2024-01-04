#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        char currentChar = tolower(str[i]);
        
        if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u') {
            vowels++;
        } else if (isalpha(currentChar)) {
            consonants++;
        }
    }

    printf("The number of vowels is %d\n", vowels);
    printf("The number of consonants is %d\n", consonants);

    return 0;
}

