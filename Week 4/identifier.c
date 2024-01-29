#include <stdio.h>
#include <ctype.h>

// Function to determine the type of input based on the given rules
int determineType(char str[]) {
    int state = 0;
    int i = 0;

    // Initial check for the first character
    if (isalpha(str[0])) {
        state = 1;  // Variable
    } else if (isdigit(str[0])) {
        state = 2;  // Integer constant
    } else {
        state = 10; // Error
    }

    while (str[i] != '\0') {
        switch (state) {
            case 1: // Variable
                if (isalnum(str[i])) {
                    state = 1;
                } else if (str[i] == '(') {
                    state = 3;
                } else if (str[i] == '[') {
                    state = 5;
                } else {
                    state = 10; // Error
                }
                break;

            case 2: // Integer constant
                if (isdigit(str[i])) {
                    state = 2;
                } else if (str[i] == '.' && isdigit(str[i + 1])) {
                    state = 4;
                } else {
                    state = 10; // Error
                }
                break;

            case 3: // Function
                if (str[i] == ')' && str[i + 1] == '\0') {
                    state = 6;
                } else {
                    state = 10; // Error
                }
                break;

            case 4: // Real constant
                if (isdigit(str[i])) {
                    state = 4;
                } else {
                    state = 10; // Error
                }
                break;

            case 5: // Array
                if (isdigit(str[i])) {
                    state = 5;
                } else if (str[i] == ']' && str[i + 1] == '\0') {
                    state = 7;
                } else {
                    state = 10; // Error
                }
                break;
        }

        i++;

        // Break the loop if an error is encountered
        if (state == 10) {
            break;
        }
    }

    return state;
}

int main() {
    char str[20];

    printf("Enter the string: ");
    gets(str); // Note: gets is deprecated, consider using fgets

    // Determine the type of input based on rules
    int type = determineType(str);

    // Print the original string
    printf("%s\n", str);

    // Output the result based on the determined type
    switch (type) {
        case 1:
            printf("Input is a variable.\n");
            break;
        case 2:
            printf("Input is an integer constant.\n");
            break;
        case 4:
            printf("Input is a real constant.\n");
            break;
        case 6:
            printf("Input is a function.\n");
            break;
        case 7:
            printf("Input is an array.\n");
            break;
        default:
            printf("There is an error in the given expression.\n");
            break;
    }

    return 0;
}
