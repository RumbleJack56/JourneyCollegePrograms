#include<stdio.h>
#include<string.h>
int main(){
    char inputBuffer[60];
    printf("Enter Word: ");
    fgets(inputBuffer,60,stdin);
    int wordSize = strcspn(inputBuffer,"\n");
    for (int k=0; k<wordSize;++k){
        
        if ((inputBuffer[k]<123) && (inputBuffer[k]>96)){
            char temp[1] = {inputBuffer[k]};
            strupr(temp);
            inputBuffer[k] = temp[0];
            continue;
        }
    }
    printf("Uppercase is %s",inputBuffer);
    for (int k=0; k<wordSize;++k){
        if ((inputBuffer[k]<91) && (inputBuffer[k]>64)){
                char temp[1] = {inputBuffer[k]};
                strlwr(temp);
                inputBuffer[k] = temp[0];
                continue;
            }
    }
    printf("Lowercase is %s",inputBuffer);
}