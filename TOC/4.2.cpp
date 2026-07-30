//4.2
#include <stdio.h>
#include <string.h>

#define ACCEPT 1
#define REJECT 0

// Function Prototypes
int state0(char ch);
int state1(char ch);
int state2(char ch);
int state3(char ch);
int state4(char ch);
int state5(char ch);
int state6(char ch);

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
            case 3:
                state = state3(ch);
                break;
            case 4:
                state = state4(ch);
                break;
            case 5:
                state = state5(ch);
                break;
            case 6:
                state = state6(ch);
                break;
        }
    }

    return (state == 6) ? ACCEPT : REJECT;
}

// State 0: Expect 'M'
int state0(char ch) {
    if (ch == 'M')
        return 1;
    return 0;
}

// State 1: Expect 'a'
int state1(char ch) {
    if (ch == 'a')
        return 2;
    return 0;
}

// State 2: Expect 'm'
int state2(char ch) {
    if (ch == 'm')
        return 3;
    return 0;
}

// State 3: Expect 'a'
int state3(char ch) {
    if (ch == 'a')
        return 4;
    return 0;
}

// State 4: Expect 't'
int state4(char ch) {
    if (ch == 't')
        return 5;
    return 0;
}

// State 5: Expect 'a'
int state5(char ch) {
    if (ch == 'a')
        return 6;
    return 0;
}

// State 6: Accept State
int state6(char ch) {
    return 0;
}

int main() {
    char input[100];
    char choice;

    do {
        printf("Enter a string: ");
        scanf("%s", input);

        if (nfa(input) == ACCEPT && strlen(input) == 6)
            printf("The string is accepted.\n");
        else
            printf("The string is rejected.\n");

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Closing The Program.\n");

    return 0;
}
