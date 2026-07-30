//Receiver
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct message{
long type;
char text[100];
};

int main(){
struct message msg;

//Generate key
key_t key = ftok("progfile", 65);

//Access existing queue
int msgid = msgget(key, 0666 |IPC_CREAT);

//Receive message
msgrcv(msgid, &msg, sizeof(msg), 1, 0);

printf("Received Message:  %s\n",msg.text);

//Delete queue
msgctl(msgid, IPC_RMID, NULL);

return 0;
}
