#include<stdio.h>
int main(){
    int sum=0,num;
    printf("Enter Number: ");
    scanf("%d",&num);
    printf("\n");
    for (int k=1;k<=num;++k){
        sum+=k;
    }
    printf("Sum of %d natural numbers is %d",num,sum);
    return 0;
}