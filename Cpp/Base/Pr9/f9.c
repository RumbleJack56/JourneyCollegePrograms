#include<stdio.h>
#include<string.h>
int main(){
    char inputBuffer[60];
    printf("Enter Word: ");
    fgets(inputBuffer,60,stdin);
    int lenWord = strcspn(inputBuffer,"\n");
    char revString[lenWord],inputFormatted[lenWord];
    for (int k=0;k<lenWord;++k){
        inputFormatted[k] = inputBuffer[k];
    }
    for (int k=lenWord-1; k>=0;--k){
        revString[lenWord - 1 - k] = inputBuffer[k];
    }
    printf("%s",revString);
}