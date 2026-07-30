//5.2 Validate Phone Number 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
int state7(char ch);
int state8(char ch);
int state9(char ch);
int state10(char ch);

// Global State Variable
int state = 0;

// NFA Function
int nfa(char input[])
{
    state = 0;

    for(int i = 0; i < strlen(input); i++)
    {
        char ch = input[i];

        switch(state)
        {
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

            case 7:
                state = state7(ch);
                break;

            case 8:
                state = state8(ch);
                break;

            case 9:
                state = state9(ch);
                break;

            case 10:
                state = state10(ch);
                break;
        }
    }

    return (state == 10) ? ACCEPT : REJECT;
}

// State 0 : First digit must be 9
int state0(char ch)
{
    if(ch == '9')
        return 1;
    return 0;
}

// State 1 : Second digit must be 7 or 8
int state1(char ch)
{
    if(ch == '7' || ch == '8')
        return 2;
    return 0;
}

// Remaining 8 digits

int state2(char ch)
{
    if(isdigit(ch))
        return 3;
    return 0;
}

int state3(char ch)
{
    if(isdigit(ch))
        return 4;
    return 0;
}

int state4(char ch)
{
    if(isdigit(ch))
        return 5;
    return 0;
}

int state5(char ch)
{
    if(isdigit(ch))
        return 6;
    return 0;
}

int state6(char ch)
{
    if(isdigit(ch))
        return 7;
    return 0;
}

int state7(char ch)
{
    if(isdigit(ch))
        return 8;
    return 0;
}

int state8(char ch)
{
    if(isdigit(ch))
        return 9;
    return 0;
}

int state9(char ch)
{
    if(isdigit(ch))
        return 10;
    return 0;
}

// Accept State
int state10(char ch)
{
    return 0;
}

int main()
{
    char input[100];
    char choice;

    do
    {
        printf("Enter  Phone Number: ");
        scanf("%s", input);

        // Check length
        if(strlen(input) != 10)
        {
            printf("Invalid Phone Number.\n");
        }
        else
        {
            if(nfa(input) == ACCEPT)
                printf("Valid  Phone Number.\n");
            else
                printf("Invalid Phone Number.\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    printf("Closing The Program.\n");

    return 0;
}
