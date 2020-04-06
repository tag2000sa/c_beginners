#include <stdio.h>
#include "sort_ptr.h"
#include "sort_ll.h"

/*
    File-Name: main.c
    Signature: 202002.ORIGINAL
    Author: Turky Abdulaziz Saderaldin
    Subject: sort list of integers using
                1- array of pointers.
                2- linked-list.

*/ 

int main(int argc,char* argv[]){
    int i,lsize,list[]={72,-8,100,-2,12,0,-56,1,33,-14,88,-26,60,-44,1};
    lsize=sizeof(list)/sizeof(int);
    int *ascend_ptr[lsize],*descend_ptr[lsize];
    int *ascend_ll[lsize],*descend_ll[lsize];
    for(i=0;i<lsize;i++) // initialize lists.
        ascend_ptr[i]=descend_ptr[i]=ascend_ll[i]=descend_ll[i]=&list[i];
    srt_ptr(ascend_ptr,lsize,'a'); // ascending sort using pointers
    srt_ptr(descend_ptr,lsize,'d'); // descending sort using pointers
    srt_ll(ascend_ll,lsize,'a'); // ascending sort using linked-list
    srt_ll(descend_ll,lsize,'d'); // descending sort using linked-list
    printf("##\toriginal\tasc_ptr\t\tdesc_ptr\tasc_ll\t\tdesc_ll\n");
    for(i=0;i<lsize;i++){
        printf("%2d\t%4d\t\t%4d\t\t%4d\t\t%4d\t\t%4d\n",i+1,list[i],*ascend_ptr[i],*descend_ptr[i],*ascend_ll[i],*descend_ll[i]);
    }
    return 0;
}
