#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

struct Numbers{
int num1;
int num2;
};

int main(){
key_t key;
int shmid;

//Generate unique key
key = ftok("shmfile",65);

//Create shared memory
shmid=shmget(key, sizeof(struct Numbers), 0666|IPC_CREAT);

//Attach shared memory
struct Numbers *data = (struct Numbers *)shmat (shmid,NULL,0);

printf("Enter first number:");
scanf("%d",&data->num1);

printf("Enter second number:");
scanf("%d",&data->num2);

printf("\nNumbers stored successfully.\n");

//Detach shared memory
shmdt(data);

return 0;
}
