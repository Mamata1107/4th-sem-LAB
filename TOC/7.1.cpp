//7.1 PDA Simulation for a^n b^n c^n

#include <stdio.h>
#include <string.h>

#define MAX 100
#define ACCEPT 1
#define REJECT 0

char stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(char ch)
{
    stack1[++top1] = ch;
}

void push2(char ch)
{
    stack2[++top2] = ch;
}

char pop1()
{
    if(top1 == -1)
        return '\0';
    return stack1[top1--];
}

char pop2()
{
    if(top2 == -1)
        return '\0';
    return stack2[top2--];
}

int pda(char input[])
{
    int i = 0;

    top1 = -1;
    top2 = -1;

    // Push all a's into Stack1
    while(input[i] == 'a')
    {
        push1('A');
        i++;
    }

    // Pop Stack1 and Push into Stack2 for each b
    while(input[i] == 'b')
    {
        if(pop1() == '\0')
            return REJECT;

        push2('B');
        i++;
    }

    // Pop Stack2 for each c
    while(input[i] == 'c')
    {
        if(pop2() == '\0')
            return REJECT;

        i++;
    }

    // Accept only if input is completely read and both stacks are empty
    if(input[i] == '\0' && top1 == -1 && top2 == -1)
        return ACCEPT;

    return REJECT;
}

int main()
{
    char input[100];
    char choice;

    do
    {
        printf("Enter String. Only a, b and c are allowed: ");
        scanf("%s", input);

        if(pda(input) == ACCEPT)
            printf("String is Accepted by PDA.\n");
        else
            printf("String is Rejected by PDA.\n");

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

    }while(choice == 'y' || choice == 'Y');

    printf("Closing The Program.\n");

    return 0;
}
