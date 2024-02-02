#include<stdio.h>
int main(){
    char inp[20];
    printf("Enter Data: ");
    fgets(inp,20,stdin);
    printf("%s",inp);
}