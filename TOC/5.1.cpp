//5.1 Email Validation using NFA
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

// Global State Variable
int state = 0;

// NFA Function
int nfa(char input[])
{
    state = 0;

    for(int i=0;i<strlen(input);i++)
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
        }
    }

    return (state==4)?ACCEPT:REJECT;
}

// State 0 : Username
int state0(char ch)
{
    if(isalnum(ch) || ch=='_')
        return 1;
    return 0;
}

// State 1 : Username continues or '@'
int state1(char ch)
{
    if(isalnum(ch) || ch=='_')
        return 1;
    else if(ch=='@')
        return 2;
    return 0;
}

// State 2 : Domain name
int state2(char ch)
{
    if(isalpha(ch))
        return 3;
    return 0;
}

// State 3 : Domain continues or '.'
int state3(char ch)
{
    if(isalpha(ch))
        return 3;
    else if(ch=='.')
        return 4;
    return 0;
}

// State 4 : Extension (.com, .edu, etc.)
int state4(char ch)
{
    if(isalpha(ch))
        return 4;
    return 0;
}

int main()
{
    char input[100];
    char choice;

    do
    {
        printf("Enter Email: ");
        scanf("%s", input);

        if(nfa(input)==ACCEPT)
            printf("Valid Email Address.\n");
        else
            printf("Invalid Email Address.\n");

        printf("Do you want to continue? (y/n): ");
        scanf(" %c",&choice);

    }while(choice=='y' || choice=='Y');

    printf("Closing The Program.\n");

    return 0;
}
