#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int i;
    void *shm_ptr;
    char buf[1024];
    int shm_id;

    shm_id = shmget((key_t)2345, 1024, IPC_CREAT | 0666);
    printf("shm_id = %d\n", shm_id);
    shm_ptr = shmat(shm_id, NULL, 0);
    printf("shm_ptr = %p\n", shm_ptr);

    printf("Data read from shared memory: %s\n", (char *)shm_ptr);
    return 0;
}
