// FIFO Disk Scheduling without abs()

#include <stdio.h>

int main() {
    int req[20], n, head, i, diff, seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Seek Sequence: %d ", head);

    for(i = 0; i < n; i++) {

        if(req[i] > head)
            diff = req[i] - head;
        else
            diff = head - req[i];

        seek = seek + diff;
        head = req[i];

        printf("-> %d ", head);
    }

    printf("\nTotal Seek Time = %d", seek);

    return 0;
}
