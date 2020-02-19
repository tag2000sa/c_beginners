#include <stdio.h>

/*
 *  File-Name: variables.c
 *  This file was created on 02/19/20
 *  Signature: 202002.ORIGINAL
 *  Author: Turky Abdulaziz Saderaldin
 *  Subject: 
 *
 * */ 

/* global variable */
int x; 

/* pass by reference */
void function1(int *x){
    (*x)++;
    printf("%d\n",*x);
}

/* pass by value */
void function2(int x){
    x++;
    printf("%d\n",x);
}
int main(int argc, char* argv[]){
    /* local variable */
    int y;
    x=10;
    y=x;
    /* print global variable */
    printf("%d\n",x);
    /* pass-by-reference-function */
    function1(&y);
    /* pass-by-value-function */
    function2(y);
    /* print local variable */
    printf("%d\n",y);

return 0;
}
