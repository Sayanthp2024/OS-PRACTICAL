#include <stdio.h>
#include <stdlib.h>

int n = 0, buffersize = 0, currentsize = 0;

void producer()
{
    printf("\nEnter number of elements to be produced: ");
    scanf("%d", &n);

    if ((currentsize + n) <= buffersize)
    {
        currentsize += n;
        printf("%d elements produced. Current buffer size: %d\n",
               n, currentsize);
    }
    else
    {
        printf("\nBuffer is not sufficient (Overflow condition)\n");
    }
}

void consumer()
{
    int x;
    printf("\nEnter number of elements to be consumed: ");
    scanf("%d", &x);

    if (currentsize >= x)
    {
        currentsize -= x;
        printf("%d elements consumed. Elements left: %d\n",
               x, currentsize);
    }
    else
    {
        printf("\nBuffer is empty or insufficient elements (Underflow condition)\n");
    }
}

int main()
{
    int choice;

    printf("Enter maximum buffer size: ");
    scanf("%d", &buffersize);

    do
    {
        printf("\n1. Producer\n2. Consumer\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (currentsize == buffersize)
                    printf("\nBuffer is full. Cannot produce.\n");
                else
                    producer();
                break;

            case 2:
                if (currentsize == 0)
                    printf("\nBuffer is empty. Cannot consume.\n");
                else
                    consumer();
                break;

            case 3:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}