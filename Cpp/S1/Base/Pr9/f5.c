#include<stdio.h>
#include<string.h>
int main(){
    char inputBuffer[60];
    printf("Enter String: ");
    fgets(inputBuffer,60,stdin);
    char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};
    int vowelCount=0;
    for (int k=0;k<strcspn(inputBuffer,"\n");++k){
        for (int j=0;j<10;++j){
            if (inputBuffer[k]==vowels[j]){
                vowelCount++;
                break;
            }
        }
    }
    printf("%d",vowelCount);
}