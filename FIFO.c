#include <stdio.h>

int main() {
    int reference[50], frame[50];
    int n, fsize, i, j, flag = 0, c = 0, fault = 0;

    float miss, hit;

    printf("Enter the number of references: ");
    scanf("%d", &n);

    printf("Enter the references:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &reference[i]);

    printf("Enter frame size: ");
    scanf("%d", &fsize);

    for (i = 0; i < fsize; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++) {
        flag = 0;

        for (j = 0; j < fsize; j++) {
            if (frame[j] == reference[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            frame[c] = reference[i];
            c = (c + 1) % fsize;
            fault++;
        }
    }

    printf("\nTotal Page Faults = %d\n", fault);

    miss = ((float)fault / n) * 100;
    hit = ((float)(n - fault) / n) * 100;

    printf("Miss Ratio = %.2f%%\n", miss);
    printf("Hit Ratio = %.2f%%\n", hit);

    return 0;
}