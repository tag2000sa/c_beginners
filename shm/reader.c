#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc,char* argv[]){
    int shmid,*data,reader;
    key_t key;
    size_t data_size;
    data_size=sizeof(int);
    key=ftok(".",'a');
    shmid=shmget(key,data_size,0666);
    if(shmid<0){
        perror("shmget");
        exit(errno);
    }
    data=(int *)(shmat(shmid,NULL,0));
    if(&data<0){
        perror("shmat");
        exit(1);
    }

    reader=*data;
    printf("%d",reader);

    if(shmdt((void *)data)<0){
        perror("shmdt");
        exit(1);
    }


    return 0;
}
