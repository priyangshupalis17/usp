//WRITER


#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>

struct msg_buf
{
	long msg_type;
	char msg_text[10];
} msg;

int main()
{
	key_t key;
	int msgid;
	key=ftok("prog.c", 65);
	msgid=msgget(key,0666 | IPC_CREAT);
	msg.msg_type=1;
	printf("Enter the message to be written to the queue\n");
	scanf("%s",msg.msg_text);
	msgsnd(msgid,&msg,sizeof(msg),0);
	printf("message sent to the queue\n");
	return 0;	
}
