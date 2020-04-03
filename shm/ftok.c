#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>

int main (int argc, char* argv[]){
    key_t mykey;
    mykey=ftok(".",1234);
    printf("%d\n",mykey);
    return 0;
}
