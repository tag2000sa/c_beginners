#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fact.h"

/*
 *  File-Name: main.c
 *  This file was created on 03/21/20
 *  Signature: 202002.ORIGINAL
 *  Author: Turky Abdulaziz Saderaldin
 *  Subject: 
 *
 * */ 


int main(int argc, char* argv[]){
    if(argc<2){
        printf("Error: no input\n");
        return -1;
    }
    if(!strcmp(argv[1],"-h")){
        printf("Usage: factorial <integer>\n");
        return 0;
    }
    else{
        int input=atoi(argv[1]);
        printf("%d! = %d\n",input,fact(input));
    }

return 0;
}
