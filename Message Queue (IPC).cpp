#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


struct msg_buffer
{
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;

    key = ftok("msg_queue_example", 65);
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    struct msg_buffer message;

    message.msg_type = 1; 
    strcpy(message.msg_text, "Hello, message queue!");

    if (msgsnd(msgid, &message, sizeof(message), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }

    printf("Message sent to the queue: %s\n", message.msg_text);

    return 0;
}
