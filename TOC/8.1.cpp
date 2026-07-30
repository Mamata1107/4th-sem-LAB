// 8.1 Turing Machine Simulation for f(x) = x + 1

#include <stdio.h>

int main()
{
    int x;
    char tape[100];
    int head;
    char choice;

    do
    {
        printf("Enter a number: ");
        scanf("%d", &x);

        // Create tape in unary form
        head = 0;
        while(head < x)
        {
            tape[head] = '1';
            head++;
        }

        // Blank symbol
        tape[head] = 'B';

        printf("\nInitial Tape: ");
        for(int i = 0; i <= head; i++)
        {
            printf("%c", tape[i]);
        }

        // TM Operation: Replace blank with 1
        tape[head] = '1';
        head++;
        tape[head] = 'B';

        printf("\nFinal Tape: ");
        for(int i = 0; i <= head; i++)
        {
            printf("%c", tape[i]);
        }

        printf("\nResult: f(%d) = %d\n", x, x + 1);

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);

        printf("\n");

    } while(choice == 'y' || choice == 'Y');

    printf("Program Ended.\n");

    return 0;
}
