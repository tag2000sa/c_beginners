#include "sort_pointer.h"
void *srt_lst_ptr(int *list[],unsigned int list_size,char dir){
    int i,j,*temp;
    for(i=0;i<list_size;i++){
        for(j=i+1;j<list_size;j++){
            if(dir=='a'){ // ascending
                if(*list[i]>*list[j]){
                   temp=list[i];
                   list[i]=list[j];
                   list[j]=temp;
                }
            }
            else if(dir=='d'){ // descending
                if(*list[i]<*list[j]){
                   temp=list[i];
                   list[i]=list[j];
                   list[j]=temp;
                }
            }
            else{
                printf("Error: srt_lst_ptr(int *list,char dir)\n\tdir:\ta->ascending\n\t\td->descending\n");
                exit(1);
            }
        }
    }
}
