#include <stdlib.h>

/*
    File-Name: sort_ll.c
    Signature: 202002.ORIGINAL
    Author: Turky Abdulaziz Saderaldin
    Subject: function to sort list of integers using linked-list.

*/ 

struct Node{
    int *number;
    struct Node *next,*prev;
};

void srt_ll(int *list[],unsigned int list_size, char dir){
    int i;
    struct Node *head;
    head=(struct Node*)malloc(sizeof(struct Node));
    for(i=0;i<list_size;i++){ // load numbers to linked-list
        struct Node *node;
        node=(struct Node*)malloc(sizeof(struct Node));
        node->number=list[i];
        node->next=head;
        head->prev=node;
        head=node;
    }
    struct Node *sorted,*check,*temp;
    check=head;
    sorted=(struct Node*)malloc(sizeof(struct Node));
    while(check->next!=NULL){ // iterate through linked-list
        temp=check;
        while(check->next!=NULL){        
            if(dir=='a'){ // sort ascending
                if(*check->number>=*temp->number){
                    temp=check;
                }
            }
            else if(dir=='d'){ // sort descending
                if(*check->number<=*temp->number){
                    temp=check;
                }
            }
            check=check->next;
        }
        struct Node *s_node=(struct Node*)malloc(sizeof(struct Node));
        s_node->number=temp->number;
        s_node->next=sorted;
        sorted->prev=s_node;
        sorted=s_node;
        if(temp==head){
            head=temp->next;
        }
        else{
            temp->prev->next=temp->next;
        }
        temp->next->prev=temp->prev;
        check=head;
    }
    i=0;
    while(sorted->next!=NULL){ // return sorted list
        list[i++]=sorted->number;
        sorted=sorted->next;
    }
}
