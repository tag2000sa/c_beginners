#include <stdio.h>

/*
 *  File-Name: string.c
 *  This file was created on 02/19/20
 *  Signature: 202002.ORIGINAL
 *  Author: Turky Abdulaziz Saderaldin
 *  Subject: 
 *
 * */ 


int main(int argc, char* argv[]){
    /* single line initialization */
    char str1[]="King Abdulaziz University";
    printf("%s\n",str1);
    
    /* single line initialization */
    char str2[25]="Jeddah University";
    printf("%s\n",str2);
    
    /* aggregate initialization without size */
    char str3[]={'K','i','n','g',' ','S','a','u','d',' ','U','n','i','v','e','r','s','i','t','y','\0'};
    printf("%s\n",str3);

    /* aggregate initialization with size */
    char str4[26]={'P','r','i','n','c','e','s','s',' ','N','o','u','r','a',' ','U','n','i','v','e','r','s','i','t','y','\0'};
    printf("%s\n",str4);

    /* one character at a time */
    char str5[6];
    str5[0]='E';
    str5[1]='E';
    str5[2]='4';
    str5[3]='6';
    str5[4]='3';
    str5[5]='\0';
    printf("%s\n",str5);

    /* read input from user until white space */
    char str6[20];
    printf("\nEnter text without spacees:");
    scanf("%s",str6);
    printf("%s\n",str6);

return 0;
}
