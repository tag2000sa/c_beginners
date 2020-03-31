#include <stdio.h>
#include <stdlib.h>
/* #include "to_binary.h" */
#include "to_bin.h"
/*
 *  File-Name: test.c
 *  Signature: 202002.ORIGINAL
 *  Author: Turky Abdulaziz Saderaldin
 *  Subject: 
 *
 * */ 

int main(int argc, char* argv[]){
    int x=atoi(argv[1]);
    printf("      octal: %o\n",x);
    printf("    decimal: %d\n",x);
    printf("hexadecimal: %x\n",x);
    printf("  character: %c\n",x);
    printf("     binary: ");
    itob(x);
return 0;
}
