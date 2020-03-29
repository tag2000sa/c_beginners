#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

/*
 *  File-Name: main.c
 *  Signature: 202002.ORIGINAL
 *  Author: Turky Abdulaziz Saderaldin
 *  Subject: 
 *
 * */ 

int main(int argc, char* argv[]){
    pid_t pid;
    pid=fork();
    int status;
    if(pid>0){
        // parent
        printf("parent: pid(%d) ppid(%d)\n",getpid(),getppid());
        /* sleep(1); // multiplrocess */
        /* exit(0); // orphan */
        wait(&status);// multiprocess_wait
        if(WEXITSTATUS(status)==42){
            printf("my child terminated\n");
        }
        else{
            sleep(30);
        }
        printf("parent terminated.\n");
    }
    else{
        // child
        printf("child: pid(%d) ppid(%d)\n",getpid(),getppid());
        printf("child terminated\n");
        exit(42); // 42 will do
        sleep(15); // multiprocess_wait
    }
return 0;
}
