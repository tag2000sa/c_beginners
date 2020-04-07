#include "myfunc.h"
void myfunction(char *message){
    char c;
    setbuf(stdout,NULL);
    while((c=*message++)!=0)
        putc(c,stdout);
}
