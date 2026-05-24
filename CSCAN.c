// C-SCAN Disk Scheduling without abs()

#include <stdio.h>

int main() {
    int req[20], n, head, i, j, temp, diff, seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Sorting
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(req[j] > req[j+1]) {
                temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }

    printf("Seek Sequence: %d ", head);

    // Move right
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {

            diff = req[i] - head;

            seek = seek + diff;
            head = req[i];

            printf("-> %d ", head);
        }
    }

    // Jump and continue
    for(i = 0; i < n; i++) {
        if(req[i] < head) {

            diff = head - req[i];

            seek = seek + diff;
            head = req[i];

            printf("-> %d ", head);
        }
    }

    printf("\nTotal Seek Time = %d", seek);

    return 0;
}
