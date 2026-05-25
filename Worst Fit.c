// Worst Fit Memory Allocation

#include <stdio.h>

int main() {
    int bsize[10], psize[10], allocation[10];
    int bno, pno, i, j, worst;

    printf("Enter number of blocks: ");
    scanf("%d", &bno);

    printf("Enter block sizes:\n");
    for(i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &pno);

    printf("Enter process sizes:\n");
    for(i = 0; i < pno; i++)
        scanf("%d", &psize[i]);

    // Initialize allocation
    for(i = 0; i < pno; i++)
        allocation[i] = -1;

    // Worst Fit Allocation
    for(i = 0; i < pno; i++) {

        worst = -1;

        for(j = 0; j < bno; j++) {

            if(bsize[j] >= psize[i]) {

                if(worst == -1)
                    worst = j;

                else if(bsize[worst] < bsize[j])
                    worst = j;
            }
        }

        if(worst != -1) {
            allocation[i] = worst;

            bsize[worst] -= psize[i];
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");

    for(i = 0; i < pno; i++) {

        printf("%d\t\t%d\t\t", i + 1, psize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
