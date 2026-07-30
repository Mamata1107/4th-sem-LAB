///Round robin deadlock
#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], rt[20];
    int wt[20], tat[20], ct[20];
    int tq;
    int time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Arrival Time and Burst Time
    for(i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i];   // Remaining Time
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    // Round Robin Scheduling
    while(completed < n) {
        int found = 0;

        for(i = 0; i < n; i++) {

            if(at[i] <= time && rt[i] > 0) {
                found = 1;

                if(rt[i] > tq) {
                    time = time + tq;
                    rt[i] = rt[i] - tq;
                }
                else {
                    time = time + rt[i];
                    ct[i] = time;
                    rt[i] = 0;
                    completed++;
                }
            }
        }

        if(found == 0)
            time++;
    }

    // Calculate WT and TAT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    avg_wt = total_wt / n;
    avg_tat = total_tat / n;

    // Display Result
    printf("\n------------------------------------------------------------\n");
    printf("Process\tAT\tBT\tWT\tTAT\n");
    printf("------------------------------------------------------------\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("------------------------------------------------------------\n");
    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
