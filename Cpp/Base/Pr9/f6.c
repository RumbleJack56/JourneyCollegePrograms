#include<stdio.h>
#include<string.h>
int main(){
    char inputBuffer[60];
    printf("Enter Word: ");
    fgets(inputBuffer,60,stdin);
    int lenWord = strcspn(inputBuffer,"\n"),flag=0;

    for (int k=lenWord-1; k>=0;--k){
        if (inputBuffer[lenWord-1-k]!=inputBuffer[k]){
            flag=1;
            break;
        }
    }

    if (flag==0){
        printf("Palindrome");
    }
    else{
        printf("not Palindrome");
    }
}