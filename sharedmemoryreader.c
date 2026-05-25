// Shared Memory Reader Program

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {

    key_t key = 1234;
    int shmid;

    // Access shared memory
    shmid = shmget(key, 1024, 0666);

    // Attach shared memory
    char *str = (char *) shmat(shmid, NULL, 0);

    // Read data
    printf("Data read from memory: %s\n", str);

    // Detach shared memory
    shmdt(str);

    return 0;
}
