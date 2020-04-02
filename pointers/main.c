#include <stdio.h>
#include "sort_pointer.h"

int main(int argc,char* argv[]){
    int lsize,array[12]={72,-8,100,-2,12,0,-56,1,33,-14,88,-26};
    lsize=sizeof(array)/sizeof(int);
    int i,*ascend[lsize],*descend[lsize];
    for(i=0;i<lsize;i++){
        ascend[i]=descend[i]=&array[i];
    }
    srt_lst_ptr(ascend,lsize,'a');
    srt_lst_ptr(descend,lsize,'d');
    printf("#\toriginal\tascend\t\tdescend\n");
    for(i=0;i<lsize;i++){
        printf("%d\t%d\t\t%d\t\t%d\n",i+1,array[i],*ascend[i],*descend[i]);
    }
    return 0;
}
