#include<stdio.h>
int main(){
    int n,s=1;
    printf("Enter number: ")
    scanf("%d",&n);
    printf("\n")
    for (int k=1;k<=n;++k){
        s*=n;
    }
    printf("%d factorial is %d",n,s);
}