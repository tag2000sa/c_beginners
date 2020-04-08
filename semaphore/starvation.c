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
    /* sem_wait(&s); // **[15,26] these together will cause starvation */
    while(1){
        sem_wait(&s); // **[18,24] these together will cause starvation
        if(number>=MAX){
            exit(0);
        }
        number++;
        printf("tid[%lu] %d\n",pthread_self(),number);
        sem_post(&s); // **[18,24] these together will cause starvation
    }
    /* sem_post(&s); // **[15,26] these together will cause starvation */
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
