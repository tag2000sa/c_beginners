#include <stdio.h>
#include <pthread.h>
#include "myfunc.h"

#define tasks 10

int main(int argc, char* argv[]){
    pthread_t thid[tasks];
    int i;
    char m[]="Multi-Thread.\n";
    for(i=0;i<tasks;i++){
        pthread_create(&thid[i],NULL,(void *)myfunction,(void *)m);
    }
    for(i=0;i<tasks;i++){
        pthread_join(thid[i],NULL);
    }
    return 0;
}
