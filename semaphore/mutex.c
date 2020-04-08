#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 100
#define pshared 0 // 0:threads   1+:process
#define key 1 // 1+:unlocked   0:locked

int i,number=0;
sem_t s;

void increment(void){
    while(1){
        sleep(1); // delay to assure progress
        sem_wait(&s); // start mutual execlusion (enter critical section)
        if(number>=MAX){
            sem_post(&s); // prevent deadlock
            exit(0); // terminate thread properly
        }
        number++;
        printf("tid[%lu] %d\n",pthread_self(),number);
        sem_post(&s); // end mutual execlusion (exit critical section)
    }
}

int main(int argc, char* argv[]){
    int threads=atoi(argv[1]);
    pthread_t tid[threads];
    sem_init(&s,pshared,key);
    for(i=0;i<threads;i++){
        // create thread
        pthread_create(&tid[i],NULL,(void *)increment,NULL);
    }
    for(i=0;i<threads;i++){
        // join thread (wait)
        pthread_join(tid[i],NULL);
    }
    // destory thread
    pthread_exit(0);

    // destroy semaphore
    sem_destroy(&s);

    return 0;
}
