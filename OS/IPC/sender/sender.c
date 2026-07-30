//sender.c

#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct message{
long type;
char text[100];
};

int main(){
struct message msg;

//Generate key
key_t key =ftok("progfile",65);

//Create message queue
int msgid= msgget(key, 0666 | IPC_CREAT);
msg.type = 1;

printf("Enter Message: ");
fgets(msg.text, sizeof(msg.text), stdin);

//Send message
msgsnd(msgid, &msg, sizeof(msg), 0);

printf("\n Message sent successfully!\n");

return 0;
}



