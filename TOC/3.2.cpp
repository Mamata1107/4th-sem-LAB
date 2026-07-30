//3.2
#include <stdio.h>
#include <string.h>

#define ACCEPT 1
#define REJECT 0

// Function Prototypes
int state0(char ch);
int state1(char ch);
int state2(char ch);

// Global State Variable
int state = 0;

// NFA Function
int nfa(char input[]) {
    state = 0;

    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i];

        switch (state) {
            case 0:
                state = state0(ch);
                break;

            case 1:
                state = state1(ch);
                break;

            case 2:
                state = state2(ch);
                break;
        }
    }

    return (state == 2) ? ACCEPT : REJECT;
}

// State 0: Initial State
int state0(char ch) {
    if (ch == '0')
        return 1;
    else
        return 0;
}

// State 1: Last symbol is 0
int state1(char ch) {
    if (ch == '1')
        return 2;
    else
        return 1;
}

// State 2: Accept State
int state2(char ch) {
    if (ch == '0')
        return 1;
    else
        return 0;
}

int main() {
    char input[100];
    char choice;

    do {
        printf("Enter a binary string: ");
        scanf("%s", input);

        // Validate input
        int valid = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (input[i] != '0' && input[i] != '1') {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("Invalid input! Only binary strings are allowed.\n");
        } else {
            if (nfa(input) == ACCEPT)
                printf("The string is accepted.\n");
            else
                printf("The string is rejected.\n");
        }

        printf("Do you want to enter another string? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Closing The Program.\n");

    return 0;
}
