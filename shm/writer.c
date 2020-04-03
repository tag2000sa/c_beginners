#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc,char* argv[]){
    int shmid,*data;
    key_t key;
    size_t data_size;
    data_size=sizeof(int);
    key=ftok(".",'a');
    shmid=shmget(key,data_size,IPC_CREAT|0666);
    printf("%d\n",shmid);
    if(shmid<0){
        perror("shmget");
        exit(errno);
    }
    data=(int *)(shmat(shmid,NULL,0));
    if(&data<0){
        perror("shmat");
        exit(1);
    }

    data[0]=atoi(argv[1]);

    if(shmdt((void *)data)<0){
        perror("shmdt");
        exit(1);
    }
    /* shmctl(shmid,IPC_RMID,0); */

    sleep(100);
    return 0;
}
