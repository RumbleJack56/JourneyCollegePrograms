#include<stdio.h>
int main(){
    int a=1,b=1,c,n,i=1;
    printf("Fibonacci Series\nEnter Number: ");
    scanf("%d",&n);
    do{
        printf("%d ",a);
        c=a+b;
        a=b;
        b=c;
        i++;
    }
    while(i<=n);
    return 0;
}