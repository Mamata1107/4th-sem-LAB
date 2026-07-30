//8.2 Turing Machine Simulation for 2's Complement

#include <stdio.h>
#include <string.h>

int main()
{
    char tape[100];
    int head;
    char choice;

    do
    {
        printf("Enter a binary number: ");
        scanf("%s", tape);

        // Head starts at the last bit
        head = strlen(tape) - 1;

        // Move left until the first 1 is found
        while(head >= 0 && tape[head] != '1')
        {
            head--;
        }

        // Move one position left
        head--;

        // Flip remaining bits
        while(head >= 0)
        {
            if(tape[head] == '0')
                tape[head] = '1';
            else
                tape[head] = '0';

            head--;
        }

        printf("2's Complement: %s\n", tape);

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    printf("\nProgram Ended.\n");

    return 0;
}
