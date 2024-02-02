#include<stdio.h>
#include<cstring>
#define getName(var)   #var


int main(){
    int lambavariablename1,lambavariablename2;
    printf("Enter 2 numbers: ");
    scanf("%d %d",&lambavariablename1,&lambavariablename2);
    printf("%d %d \n",lambavariablename1,lambavariablename2);
    int maxval = lambavariablename1>lambavariablename2 ? lambavariablename1 : lambavariablename2;
    char name[50];
    lambavariablename1>lambavariablename2 ? strcpy(name,getName(lambavariablename1)) : strcpy(name,getName(lambavariablename2));
    printf("%s is the bigger number with value %d",name,maxval);
    return 0;
}