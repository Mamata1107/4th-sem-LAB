//6.2 RE to FA : a(a+b)*b

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

// FA Function
int fa(char input[])
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
        }
    }

    return (state == 2) ? ACCEPT : REJECT;
}

// Start State
int state0(char ch)
{
    if(ch == 'a')
        return 1;

    return 0;
}

// Middle State
int state1(char ch)
{
    if(ch == 'a')
        return 1;

    else if(ch == 'b')
        return 2;

    return 0;
}

// Accept State
int state2(char ch)
{
    if(ch == 'a')
        return 1;

    else if(ch == 'b')
        return 2;

    return 0;
}

int main()
{
    char input[100];
    char choice;

    do
    {
        printf("Enter String: ");
        scanf("%s", input);

        // Validate input
        int valid = 1;

        for(int i = 0; i < strlen(input); i++)
        {
            if(input[i] != 'a' && input[i] != 'b')
            {
                valid = 0;
                break;
            }
        }

        if(!valid)
        {
            printf("Invalid Input! Only a and b are allowed.\n");
        }
        else
        {
            if(fa(input) == ACCEPT)
                printf("String Accepted.\n");
            else
                printf("String Rejected.\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

    }while(choice == 'y' || choice == 'Y');

    printf("Closing The Program.\n");

    return 0;
}
