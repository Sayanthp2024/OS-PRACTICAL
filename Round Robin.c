#include <stdio.h>

int main() {
    int n, i, time = 0, remain, tq;
    int at[50], bt[50], rt[50];
    int wt[50], tat[50];

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter Arrival Time and Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d AT BT: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];  // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int done;

    while (remain > 0) {
        done = 1;

        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                done = 0;

                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i] - at[i];
                    tat[i] = time - at[i];
                    rt[i] = 0;
                    remain--;
                }
            }
        }

        // If no process is ready, move time forward
        if (done == 1)
            time++;
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}