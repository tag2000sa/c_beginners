#include <stdio.h>
void to_bin(unsigned int x){
    if(x){
        to_bin(x>>1);
        printf("%u",(x&1)?1:0);
    }
}


void itob(unsigned int x){
    printf("0b");
    to_bin(x);
    printf("\n");
}
