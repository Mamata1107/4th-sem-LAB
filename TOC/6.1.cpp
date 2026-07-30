6.1// RE to FA: 0*(1+0)001

#include <stdio.h>
#include <string.h>

#define ACCEPT 1
#define REJECT 0

int fa(char input[])
{
    int n = strlen(input);

    for(int split = 0; split <= n; split++)
    {
        int valid = 1;

        // Check 0*
        for(int i = 0; i < split; i++)
        {
            if(input[i] != '0')
            {
                valid = 0;
                break;
            }
        }

        if(!valid)
            continue;

        // Check (1+0)001
        if(split + 4 != n)
            continue;

        if((input[split] == '0' || input[split] == '1') &&
           input[split + 1] == '0' &&
           input[split + 2] == '0' &&
           input[split + 3] == '1')
        {
            return ACCEPT;
        }
    }

    return REJECT;
}

int main()
{
    char input[100];
    char choice;

    do
    {
        printf("\nEnter binary string: ");
        scanf("%s", input);

        if(fa(input) == ACCEPT)
            printf("String Accepted by FA.\n");
        else
            printf("String Rejected by FA.\n");

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    printf("Closing The Program.\n");

    return 0;
}
