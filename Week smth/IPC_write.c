#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main()
{
    int i;
    void *shm_ptr;
    char buf[SHM_SIZE];
    int shm_id;

    shm_id = shmget((key_t)2345, SHM_SIZE, IPC_CREAT | 0666);
    printf("shm_id = %d\n", shm_id);
    shm_ptr = shmat(shm_id, NULL, 0);
    printf("shm_ptr = %p\n", shm_ptr);

    printf("Enter data: ");
    fgets(buf, SHM_SIZE, stdin);
    strncpy(shm_ptr, buf, SHM_SIZE);
    printf("Data written to shared memory: %s\n", (char *)shm_ptr);

    return 0;
}
