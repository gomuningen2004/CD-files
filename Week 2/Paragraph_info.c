#include <stdio.h>
#include <ctype.h>

int main() {
    int lines = 0, words = 0, characters = 0, tabs = 0, spaces = 0;
    char ch, prevCh = ' '; // Initialize prevCh to a space to handle consecutive spaces

    printf("Enter text (Press Ctrl+D (Ctrl+Z on Windows) to end input):\n");

    while ((ch = getchar()) != EOF) {
        characters++;

        if (ch == '\n') {
            lines++;
        }

        if (isspace(ch)) {
            spaces++;

            if (ch == ' ' || ch == '\t' || ch == '\n') {
                if (!isspace(prevCh)) {
                    words++;
                }
            }
        }

        if (ch == '\t') {
            tabs++;
        }

        prevCh = ch;
    }

    printf("Number of lines: %d\n", lines);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);
    printf("Number of tab spaces: %d\n", tabs);
    printf("Number of white spaces: %d\n", spaces);

    return 0;
}
