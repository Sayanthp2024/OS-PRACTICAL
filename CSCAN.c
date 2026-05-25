// C-SCAN Disk Scheduling with Head Movement Count

#include <stdio.h>

int main() {
    int req[20], n, head, i, j, temp;
    int seek = 0, diff, pos;
    int count = 0;

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

    // Find first request greater than head
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {
            pos = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d ", head);

    // Move right
    for(i = pos; i < n; i++) {

        diff = req[i] - head;

        seek = seek + diff;
        count++;

        head = req[i];

        printf("-> %d ", head);
    }

    // Jump to beginning
    seek = seek + head;
    head = 0;

    printf("-> %d ", head);

    // Move right again
    for(i = 0; i < pos; i++) {

        diff = req[i] - head;

        seek = seek + diff;
        count++;

        head = req[i];

        printf("-> %d ", head);
    }

    printf("\n\nTotal Seek Time = %d", seek);
    printf("\nHead Movement Count = %d", count);

    return 0;
}
