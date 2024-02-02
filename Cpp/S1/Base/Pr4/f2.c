#include<stdio.h>
int main(){
    int n,s=0;
    printf("Enter number: ")
    scanf("%d",&n);
    printf("\n")
    for (int k=1;k<=n;++k){
        s+=n;
    }
    printf("Sum of first %d natural numbers is %d",n,s);
}