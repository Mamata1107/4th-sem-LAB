//4.3
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
int state7(char ch);
int state8(char ch);
int state9(char ch);
int state10(char ch);
int state11(char ch);
int state12(char ch);
int state13(char ch);

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
            case 0: state = state0(ch); break;
            case 1: state = state1(ch); break;
            case 2: state = state2(ch); break;
            case 3: state = state3(ch); break;
            case 4: state = state4(ch); break;
            case 5: state = state5(ch); break;
            case 6: state = state6(ch); break;
            case 7: state = state7(ch); break;
            case 8: state = state8(ch); break;
            case 9: state = state9(ch); break;
            case 10: state = state10(ch); break;
            case 11: state = state11(ch); break;
            case 12: state = state12(ch); break;
            case 13: state = state13(ch); break;
        }
    }

    return (state == 13) ? ACCEPT : REJECT;
}

// State 0 : P
int state0(char ch)
{
    if(ch=='P') return 1;
    return 0;
}

// State 1 : r
int state1(char ch)
{
    if(ch=='r') return 2;
    return 0;
}

// State 2 : i
int state2(char ch)
{
    if(ch=='i') return 3;
    return 0;
}

// State 3 : m
int state3(char ch)
{
    if(ch=='m') return 4;
    return 0;
}

// State 4 : e
int state4(char ch)
{
    if(ch=='e') return 5;
    return 0;
}

// State 5 : Space
int state5(char ch)
{
    if(ch==' ') return 6;
    return 0;
}

// State 6 : C
int state6(char ch)
{
    if(ch=='C') return 7;
    return 0;
}

// State 7 : o
int state7(char ch)
{
    if(ch=='o') return 8;
    return 0;
}

// State 8 : l
int state8(char ch)
{
    if(ch=='l') return 9;
    return 0;
}

// State 9 : l
int state9(char ch)
{
    if(ch=='l') return 10;
    return 0;
}

// State 10 : e
int state10(char ch)
{
    if(ch=='e') return 11;
    return 0;
}

// State 11 : g
int state11(char ch)
{
    if(ch=='g') return 12;
    return 0;
}

// State 12 : e
int state12(char ch)
{
    if(ch=='e') return 13;
    return 0;
}

// Accept State
int state13(char ch)
{
    return 0;
}

int main()
{
    char input[100];
    char choice;

    do
    {
        printf("Enter a string: ");
        scanf(" %[^\n]", input);

        if(nfa(input)==ACCEPT && strlen(input)==13)
            printf("The string is accepted.\n");
        else
            printf("The string is rejected.\n");

        printf("Do you want to continue? (y/n): ");
        scanf(" %c",&choice);

    }while(choice=='y' || choice=='Y');

    printf("Closing The Program.\n");

    return 0;
}
