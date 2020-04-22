#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

/*
 *  File-Name: pattern1.c
 *  Signature: 202002.ORIGINAL
 *  Author: Turky Abdulaziz Saderaldin
 *  Subject: print Aa Bb Cc Dd ... etc.
 *
 * */ 

sem_t sem[3]; // declare array of semaphores
pthread_t tid[3]; // declare array of threads
int input;

void printCapital(void); // declare thread function to print capital letters
void printSmall(void); // declare thread function to print small leters
void printSpace(void); // declare thread function to print spaces

int main(int argc, char* argv[]){
    int i;
    input=atoi(argv[1]); // take input from command argument
    for(i=0;i<3;i++) 
        sem_init(&sem[i],0,(i==0)?1:0); // initilize semaphores
    pthread_create(&tid[0],
                    NULL,
                    (void*)printCapital,
                    NULL); // create first thread
    pthread_create(&tid[1],
                    NULL,
                    (void*)printSmall,
                    NULL); // create second thread
    pthread_create(&tid[2],
                    NULL,
                    (void*)printSpace,
                    NULL); // create third thraed
    for(i=0;i<3;i++)
        pthread_join(tid[i],NULL); // wait for threads to finish
    printf("\n");
    pthread_exit(NULL); // destroy main thread
    return 0;
}

/*
 *  first thread locks first semaphore
 *  print only capital letters then unlocks second semaphore
 * */ 
void printCapital(void){
    char i='A';
    int count=input;
    while(count>0){
        sem_wait(&sem[0]); 
        printf("%c",i);
        sem_post(&sem[1]);
        i++;
        count--;
    }
    pthread_exit(NULL);
}

/*
 *  second thread locks second semaphore
 *  print only small letters then unlocks third semaphore
 * */ 
void printSmall(void){
    char j='a';
    int count=input;
    while(count>0){
        sem_wait(&sem[1]);
        putchar(j);
        sem_post(&sem[2]);
        j++;
        count--;
    }
    pthread_exit(NULL);
}

/*
 *  third thread locks third semaphore
 *  print only a space then unlocks first semaphore
 * */ 
void printSpace(void){
    int count=input;
    while(count>0){
        sem_wait(&sem[2]);
        putc(' ',stdout);
        sem_post(&sem[0]);
        count--;
    }
    pthread_exit(NULL);
}
