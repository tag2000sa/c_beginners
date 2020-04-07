#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "myfunc.h"

#define tasks 2

int main(int argc, char* argv[]){
    pid_t pid[tasks]={0};
    int i;
    for(i=0;i<tasks;i++){
        pid[i]=fork(); // parent
        if(pid[i]==0){ // child
            myfunction("Hello World.\n");
            return 0;
        }
    }
    for(i=0;i<tasks;i++){
        wait(NULL);
        /* waitpid(pid[i],NULL,0); */
    }
    return 0;
}
