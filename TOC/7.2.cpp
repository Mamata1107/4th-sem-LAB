//7.2 PDA Simulation for wcwR

#include <stdio.h>
#include <string.h>

#define ACCEPT 1
#define REJECT 0

int pda(char input[])
{
    char stack[100];
    int top = -1;
    int i = 0;

    // Push characters before 'c'
    while(input[i] != '\0' && input[i] != 'c')
    {
        if(input[i] != '0' && input[i] != '1')
            return REJECT;

        stack[++top] = input[i];
        i++;
    }

    // 'c' must be present
    if(input[i] != 'c')
        return REJECT;

    i++;   // Skip 'c'

    // Compare remaining string with stack
    while(input[i] != '\0')
    {
        if(top == -1)
            return REJECT;

        if(input[i] != stack[top])
            return REJECT;

        top--;
        i++;
    }

    if(top == -1)
        return ACCEPT;

    return REJECT;
}

int main()
{
    char input[100];
    char choice;

    do
    {
        printf("Language : wcwR\n");
        printf("Enter String: ");
        scanf("%s", input);

        if(pda(input) == ACCEPT)
            printf("String Accepted.\n");
        else
            printf("String Rejected.\n");

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

    }while(choice == 'y' || choice == 'Y');

    printf("Closing The Program.\n");

    return 0;
}
