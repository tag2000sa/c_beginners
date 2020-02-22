#include <stdio.h>
#include <stdbool.h>

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
    bool *compulsory;
    /* 4 characters string + "\0" termination character */ 
    char codename[5]; // must be the last item if size not specified
};

int main(int argc, char* argv[]){
    int x;
    int *y; 
    x=10;
    y=&x;
    printf("x=%d\n",x);
    /* print referenced value before increment */
    printf("y=%d update after print value\n",(*y)++);
    /* print x after increment */
    printf("x=%d\n",x);

    /* read input from user to pointer variable y */
    printf("Enter an integer:");
    scanf("%d",y);
    printf("new y=%d\n",*y);


    /* basic structure */
    printf("\n======================\nBasic Structure\n======================\n");
    struct course a;
    a.number=499;
    int h=3;
    a.hours=&h;

    /* read string from user */ 
    printf("Enter Course Code Name:");
    scanf("%s",a.codename);

    /* flush input buffer */
    while ((getchar()) != '\n');

    /* read one character from user */ 
    printf("Is this a compulsory course? [Y/n] ");
    char tmp_c;
    scanf(" %c",&tmp_c);
    getchar(); // dump white space from next input buffer

    /* assign boolean value to pointer */
    char yes='y';
    char Yes='Y';
    bool tmp_b;
    tmp_b=true;
    a.compulsory=&tmp_b;

    /* check input ... && 10=1 , 01=1 , 11=1,  */
    if(tmp_c!=yes && tmp_c !=Yes)
    {
        *(a.compulsory)=!&tmp_b; // toggle bolean value
    }
    printf("course a (%s%d) hours (%d) ",a.codename,a.number,*(a.hours));
    if(*(a.compulsory))
    {
        printf("it is a compulsory course.\n");
    }
    else
    {
        printf("it is an elective course.\n");
    }

    /* pointer structure */
    printf("\n======================\nPointer Structure\n======================\n");
    struct course *b;
    struct course tmp_struct;
    tmp_struct.number=463;
    h=4;
    tmp_struct.hours=&h;
    tmp_struct.compulsory=&tmp_b;
    int n = sizeof(tmp_struct.codename)/sizeof(tmp_struct.codename[0]);
    int i;
    for(i=0;i<n;i++){
        tmp_struct.codename[i]=a.codename[i];
    }
    /* *(tmp_struct.codename)=*(a.codename); */
    b=&tmp_struct;
    printf("course a (%s%d) hours (%d) %s\n",b->codename,b->number,*(b->hours),*(b->compulsory)?"it is a compulsory course":"it is an elective course");
    printf("course a (%s%d) hours (%d) %s\n",(*b).codename,(*b).number,*((*b).hours),*((*b).compulsory)?"it is a compulsory course":"it is an elective course");


return 0;
}
