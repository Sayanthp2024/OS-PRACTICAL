#include <stdio.h>

int main() {

    int n, i, j;
    int bt[10], wt[10], tat[10], p[10];
    int temp;
    float tot_WT = 0, tot_TAT = 0;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst times
    printf("Enter burst time of each process:\n");

    for(i = 0; i < n; i++) {

        p[i] = i + 1;

        printf("P%d: ", p[i]);
        scanf("%d", &bt[i]);
    }

    // SJF Sorting
    for(i = 0; i < n - 1; i++) {

        for(j = i + 1; j < n; j++) {

            if(bt[i] > bt[j]) {

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process number
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // First waiting time
    wt[0] = 0;

    // Calculate waiting time
    for(i = 1; i < n; i++) {

        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {

        tat[i] = wt[i] + bt[i];

        tot_WT += wt[i];
        tot_TAT += tat[i];
    }

    // Display output
    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {

        printf("P%d\t%d\t%d\t%d\n",
               p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           tot_WT / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           tot_TAT / n);

    return 0;
}
