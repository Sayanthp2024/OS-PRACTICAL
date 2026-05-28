#include <stdio.h>

void cscan(int arr[], int n, int head)
{
    int i, j, temp;
    int seek_count = 0;
    int distance, cur_track;
    int max = 199;
    int head_count = 0;

    // Sort the requests
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int index = n;

    // Find the head position
    for(i = 0; i < n; i++)
    {
        if(head < arr[i])
        {
            index = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d ", head);

    // Move right
    for(i = index; i < n; i++)
    {
        cur_track = arr[i];
        distance = cur_track - head;

        seek_count += distance;
        head_count++;

        head = cur_track;

        printf("-> %d ", cur_track);
    }

    // Move to end of disk
    seek_count += (max - head);

    // Jump to beginning
    seek_count += max;
    head = 0;

    printf("-> %d ", head);

    // Continue from beginning
    for(i = 0; i < index; i++)
    {
        cur_track = arr[i];
        distance = cur_track - head;

        seek_count += distance;
        head_count++;

        head = cur_track;

        printf("-> %d ", cur_track);
    }

    printf("\n\nTotal Seek Time = %d", seek_count);
    printf("\nHead Movement Count = %d\n", head_count);
}

int main()
{
    int arr[20], n, head, i;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk requests:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    cscan(arr, n, head);

    return 0;
}