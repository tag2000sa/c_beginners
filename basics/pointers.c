#include <stdio.h>

/*
 *  File-Name: pointers.c
 *  This file was created on 02/19/20
 *  Signature: 202002.ORIGINAL
 *  Author: Turky Abdulaziz Saderaldin
 *  Subject: 
 *
 * */ 

/* structure */
struct course{
    int number;
    int *hours;
    char* name[2];
};

int main(int argc, char* argv[]){
    int x;
    int *y; 
    x=10;
    y=&x;
    printf("x=%d\n",x);
    /* print referenced value before increment */
    printf("y=%d\n",(*y)++);
    /* print x after increment */
    printf("x=%d\n",x);

    /* basic structure */
    struct course a;
    a.number=499;
    int h=3;
    a.hours=&h;
    printf("course a (%d) hours (%d)\n",a.number,*(a.hours));

    /* pointer structure */
    struct course *b;
    struct course tmp;
    tmp.number=463;
    h=4;
    tmp.hours=&h;
    b=&tmp;
    printf("course a (%d) hours (%d)\n",b->number,*(b->hours));
    printf("course a (%d) hours (%d)\n",(*b).number,*((*b).hours));
return 0;
}
