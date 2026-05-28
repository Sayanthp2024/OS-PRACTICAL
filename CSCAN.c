#include <stdio.h>

void cscan(int arr[], int n, int head)
{
    int i, j, temp;
    int seek_count = 0;
    int distance, cur_track;
    int max = 199;

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

    int index;

    // Find the head position
    for(i = 0; i < n; i++)
    {
        if(head < arr[i])
        {
            index = i;
            break;
        }
    }

    // Move right
    for(i = index; i < n; i++)
    {
        cur_track = arr[i];
        distance = cur_track - head;
        seek_count += distance;
        head = cur_track;

        printf("%d ", cur_track);
    }

    // Move to end of disk
    seek_count += (max - head);
    head = 0;

    // Jump to beginning and continue
    seek_count += max;

    for(i = 0; i < index; i++)
    {
        cur_track = arr[i];
        distance = cur_track - head;
        seek_count += distance;
        head = cur_track;

        printf("%d ", cur_track);
    }

    printf("\nTotal seek time = %d\n", seek_count);
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

    printf("Seek sequence:\n");

    cscan(arr, n, head);

    return 0;
}
        