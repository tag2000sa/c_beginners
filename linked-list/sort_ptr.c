/*
    File-Name: sort_ptr.c
    Signature: 202002.ORIGINAL
    Author: Turky Abdulaziz Saderaldin
    Subject: function to sort list of integers using array of pointers.

*/ 

void srt_ptr(int *list[],unsigned int list_size,char dir){
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
        }
    }
}
