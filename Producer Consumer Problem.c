#include <stdio.h>
#include <stdlib.h>

int current_size = 0, buffersize = 0;

// Producer Function
void producer() {
    int n;

    printf("Enter the products to be produced: ");
    scanf("%d", &n);

    if ((current_size + n) <= buffersize) {
        current_size += n;

        printf("The units produced = %d\n", n);
        printf("Current buffer size = %d\n", current_size);
    }
    else {
        printf("Buffer Overflow\n");
    }
}

// Consumer Function
void consumer() {
    int x;

    printf("Enter the units to consume: ");
    scanf("%d", &x);

    if (x <= current_size) {
        current_size -= x;

        printf("%d units consumed\n", x);
        printf("Current buffer size = %d\n", current_size);
    }
    else {
        printf("Buffer Underflow\n");
    }
}

int main() {

    int choice;

    printf("Enter the buffer size: ");
    scanf("%d", &buffersize);

    while (1) {

        printf("\n1. PRODUCER");
        printf("\n2. CONSUMER");
        printf("\n3. EXIT");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch(choice) {

            case 1:

                if (current_size == buffersize) {
                    printf("Buffer is FULL\n");
                }
                else {
                    producer();
                }

                break;

            case 2:

                if (current_size == 0) {
                    printf("Buffer is EMPTY\n");
                }
                else {
                    consumer();
                }

                break;

            case 3:

                printf("Exiting Program...\n");
                exit(0);

            default:

                printf("Invalid Input\n");
        }
    }

    return 0;
}
