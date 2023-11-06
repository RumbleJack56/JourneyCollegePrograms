#include<stdio.h>
#include<string.h>
int main(){
    char inputBuffer1[60],inputBuffer2[60];
    printf("Enter Word 1: ");
    fgets(inputBuffer1,60,stdin);
    printf("Enter Word 2: ");
    fgets(inputBuffer2,60,stdin);
    inputBuffer1[strcspn(inputBuffer1,"\n")] = '\0';
    inputBuffer2[strcspn(inputBuffer2,"\n")] = '\0';
    char conCatString[60];
    strcpy(conCatString,inputBuffer1);

    printf("Concatenation of \"%s\" and \"%s\" is \"%s\"",inputBuffer1,inputBuffer2,strcat(conCatString,inputBuffer2));
}