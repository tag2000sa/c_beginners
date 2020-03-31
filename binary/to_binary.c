#include <stdio.h>
void itob(unsigned int x){
    unsigned int mask=1, output=0;
    int flag=1; // true
    mask=mask<<31;
    printf("0b");
    for(mask;mask>0;mask=mask>>1){
        if(x&mask){
            // 1
            output=1;
            flag=0; // flase
        }
        else if(flag>0){
            continue;
        }
        else{
            // 0
            output=0;
        }
        printf("%u",output);
    }
    printf("\n");
}
