#include <stdio.h>
#include <string.h>

int isKeyword(char *str) {
    char keywords[][10] = {"int", "float", "char", "return", "if", "else", "while"};
    int i;
    for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void classifyToken(char *token) {
    if (isKeyword(token)) {
        printf("%s is a keyword.\n", token);
    } else {
        if (token[strlen(token) - 1] == '(') {
            printf("%s is a function.\n", token);
        } else if (token[strlen(token) - 1] == ']') {
            printf("%s is an array.\n", token);
        } else if (token[0] >= '0' && token[0] <= '9') {
            printf("%s is a constant.\n", token);
        } else if ((token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z')) {
            printf("%s is a variable.\n", token);
        } else {
            printf("%s is an invalid expression.\n", token);
        }
    }
}

int main() {
    FILE *file;
    char word[100];
    file = fopen("your_file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("File opened successfully.\n");

    while (fgets(file, "%s", word) != EOF) {
        classifyToken(word);
    }

    fclose(file);

    return 0;
}
