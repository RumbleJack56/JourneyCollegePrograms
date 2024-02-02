#include<stdio.h>
#include<string.h>

int main(){
    char a[]="Prog",b[]="PRog";
    int ax = strcmp(b,a);
    printf("%d",ax);
    return 0;
}