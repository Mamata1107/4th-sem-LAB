#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int main()
{
    int n, m;
    int available[MAX_RESOURCES];
    int max_claim[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES];
    int safe_sequence[MAX_PROCESSES];

    // Input the number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    // Input available instances of each resource
    printf("\nEnter the available instances of each resource:\n");
    for (int i = 0; i < m; i++)
    {
        printf("Resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }

    // Input maximum claim matrix
    printf("\nEnter the maximum claim matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        for (int j = 0; j < m; j++)
        {
            printf("Resource %d: ", j + 1);
            scanf("%d", &max_claim[i][j]);
        }
    }

    // Input allocation matrix
    printf("\nEnter the allocation matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i + 1);
        for (int j = 0; j < m; j++)
        {
            printf("Resource %d: ", j + 1);
            scanf("%d", &allocation[i][j]);

            // Calculate need matrix
            need[i][j] = max_claim[i][j] - allocation[i][j];
        }
    }

    // Initialize work and finish arrays
    for (int i = 0; i < m; i++)
        work[i] = available[i];

    for (int i = 0; i < n; i++)
        finish[i] = 0;

    // Banker's Algorithm
    int count = 0;

    while (count < n)
    {
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int j;

                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }

                if (j == m)
                {
                    // Process can be executed
                    for (int k = 0; k < m; k++)
                        work[k] += allocation[i][k];

                    finish[i] = 1;
                    safe_sequence[count++] = i;
                    found = 1;
                }
            }
        }

        if (found == 0)
            break;
    }

    // Display result
    if (count == n)
    {
        printf("\nSystem is in a SAFE state.\n");
        printf("Safe Sequence: ");

        for (int i = 0; i < n; i++)
        {
            printf("P%d", safe_sequence[i]);

            if (i != n - 1)
                printf(" -> ");
        }

        printf("\n");
    }
    else
    {
        printf("\nSystem is in an UNSAFE state.\n");
    }

    return 0;
}
