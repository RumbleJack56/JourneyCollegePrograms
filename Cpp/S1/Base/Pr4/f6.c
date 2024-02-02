#include<stdio.h>
int isPrime(int n){
    for (int k=2;k<=(n+1)/2; ++k){
        if (n%k==0){return 0;}    
    }
    return 1;
}
int main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    if (isPrime(n)){printf("%d is prime",n);}
    else           {printf("%d is composite",n);}
    return 0;
}