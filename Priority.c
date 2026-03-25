#include <stdio.h>

int main()
{
    int n, i, j;
    int bt[20], pr[20], pid[20];
    int wt[20], tat[20];
    int temp;

    float avg_wt = 0, avg_tat = 0;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority
    for(i = 0; i < n; i++)
    {
        printf("\nProcess %d", i+1);
        printf("\nBurst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority: ");
        scanf("%d", &pr[i]);

        pid[i] = i + 1;   // Process ID
    }

    // Sorting based on Priority (Lower value = Higher priority)
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(pr[i] > pr[j])
            {
                // Swap Priority
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // Swap Burst Time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap Process ID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Waiting time calculation
    wt[0] = 0;

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround time calculation
    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }

    // Display Table
    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               pid[i], bt[i], pr[i], wt[i], tat[i]);

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Average calculation
    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}