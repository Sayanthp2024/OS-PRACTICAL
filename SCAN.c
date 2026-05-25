// SCAN Disk Scheduling with Head Movement Count

#include <stdio.h>

int main() {
    int req[20], n, head, i, j, temp, diff;
    int seek = 0, count = 0;

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

    printf("\nSeek Sequence: %d ", head);

    // Move right
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {

            diff = req[i] - head;

            seek = seek + diff;
            count++;

            head = req[i];

            printf("-> %d ", head);
        }
    }

    // Move left
    for(i = n-1; i >= 0; i--) {
        if(req[i] < head) {

            diff = head - req[i];

            seek = seek + diff;
            count++;

            head = req[i];

            printf("-> %d ", head);
        }
    }

    printf("\n\nTotal Seek Time = %d", seek);
    printf("\nHead Movement Count = %d", count);

    return 0;
}
