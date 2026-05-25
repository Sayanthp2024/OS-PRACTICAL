#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {

    key_t key = 1234;
    int shmid;

    // Create shared memory
    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Attach shared memory
    char *str = (char *) shmat(shmid, NULL, 0);

    printf("Write Data : ");
    fgets(str, 1024, stdin);

    printf("Data written in memory: %s\n", str);

    // Detach shared memory
    shmdt(str);

    return 0;
}
