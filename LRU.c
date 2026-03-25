#include <stdio.h>

int main()
{
    int reference[50], frame[50], recent[50];
    int n, fsize, i, j, k;
    int flag = 0, flag1 = 0, c = 0, fault = 0;
    int temp;

    float miss, hit;

    printf("Enter the number of references: ");
    scanf("%d", &n);

    printf("Enter the references:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &reference[i]);

    printf("Enter the frame size: ");
    scanf("%d", &fsize);

    // Initial filling
    for (i = 0; i < fsize; i++)
    {
        frame[i] = reference[i];
        recent[i] = reference[i];
        fault++;
        c++;
    }

    recent[c] = 0;

    for (i = fsize; i < n; i++)
    {
        // Check if already present
        flag = 0;
        for (j = 0; j < fsize; j++)
        {
            if (frame[j] == reference[i])
            {
                flag = 1;
                break;
            }
        }

        // Update recent list
        for (k = 0; k < c; k++)
        {
            if (reference[i] == recent[k])
            {
                flag1 = 1;
                break;
            }
        }

        if (flag1 == 1)
        {
            temp = recent[k];
            for (j = k; j < c - 1; j++)
                recent[j] = recent[j + 1];
            recent[c - 1] = temp;
        }
        else
        {
            recent[c] = reference[i];
            c++;
            recent[c] = 0;
        }

        flag1 = 0;

        // If not found → replace LRU
        if (flag == 0)
        {
            fault++;

            for (k = 0; k < c; k++)
            {
                for (j = 0; j < fsize; j++)
                {
                    if (recent[k] == frame[j])
                    {
                        frame[j] = reference[i];
                        goto end;
                    }
                }
            }
        }

    end:
        flag = 0;
    }

    printf("\nTotal number of faults = %d\n", fault);

    miss = ((float)fault / n) * 100;
    hit = ((float)(n - fault) / n) * 100;

    printf("Total number of references = %d\n", n);
    printf("Miss ratio = %.2f%%\n", miss);
    printf("Hit ratio = %.2f%%\n", hit);

    return 0;
}