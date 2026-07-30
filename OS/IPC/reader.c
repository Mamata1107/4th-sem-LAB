#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHM_SIZE 1024

int main(){
    key_t key;
    int shmid;
    char *shm_ptr;

    //Generate same key
    key = ftok("shmfile",65);

    //Access existing shared memory
    shmid = shmget(key, SHM_SIZE, 0666);

    //Attach
    shm_ptr = (char *)shmat(shmid, NULL, SHM_RDONLY);

    //Read data
    printf("Reader received:\n%s\n", shm_ptr);

    //Detach
    shmdt(shm_ptr);

    //Delete shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
