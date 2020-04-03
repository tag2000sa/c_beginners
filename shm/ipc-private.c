#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
    int shmid;
    size_t message_size=sizeof(char)*100;
    char *shmptr;
    shmid=shmget(IPC_PRIVATE,message_size,IPC_CREAT|0774);
    printf("%d\n",shmid);
    if(shmid<0){
        perror("shmid");
        exit(errno);
    }
    if(fork()){ // parent
        char *message="Coronavirus Pandemic: #StayHome.";
        shmptr=(char *)(shmat(shmid,NULL,0));
        if(shmptr==(char*)-1){
            perror("shmat");
            exit(1);
        }
        for(int i=0;i<strlen(message);i++){
            shmptr[i]=message[i];
        }
        if(shmdt((void*)shmptr)<0){
            perror("shmdt");
            exit(2);
        }
        printf("Parent: Message sent.\n");
        /* sleep(100); */
        wait(NULL);
        shmctl(shmid,IPC_RMID,NULL);
    }
    else{ // child
        shmptr=(char *)(shmat(shmid,NULL,0));
        char read[message_size];
        read[0]='\0';
        if(shmptr==(char*)-1){
            perror("shmat");
            exit(1);
        }
        for(int i=0;i<message_size;i++){
            read[i]=shmptr[i];
        }
        printf("Child read: %s\n",read);
        if(shmdt((void*)shmptr)<0){
            perror("shmdt");
            exit(2);
        }
    }
    return 0;
}
