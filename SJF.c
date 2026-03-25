#include <stdio.h>

int main() {
    int n, i, j;
    int bt[10], wt[10], tat[10];
    int temp;
    float tot_WT = 0, tot_TAT = 0;

    // 1. START
    // 2. Get number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // 3. Get burst time of each process
    printf("Enter burst time of each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // 4. Sort processes based on burst time (SJF)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // Waiting time for first process
    wt[0] = 0;

    // 5. Calculation of WT and TAT
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        tot_WT += wt[i];
        tot_TAT += tat[i];
    }

    // 6. Display result
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", tot_WT / n);
    printf("\nAverage Turnaround Time = %.2f\n", tot_TAT / n);

    // 7. STOP
    return 0;
}