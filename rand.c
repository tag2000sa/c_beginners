#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*
 *  File-Name: rand.c
 *  Signature: 202002.ORIGINAL
 *  Author: Turky Abdulaziz Saderaldin
 *  Subject:  generate random number using time to seed random 
 *
 * */ 

int main(int argc, char* argv[]){
    unsigned int now, x=1, i;    
    time_t t;
    for(i=0;i<10;i++){
        srand((unsigned) time(&t)); // random seed
        /* x=1+(int)(rand()%50); // random range from 1 to 50 */
        now=time(&t);
        x=1+rand_r(&now)%50; // random range from 1 to 50 */
        usleep(100000*x); // micro-second sleep
        printf("%i\n",x);
    }
    return 0;
}
