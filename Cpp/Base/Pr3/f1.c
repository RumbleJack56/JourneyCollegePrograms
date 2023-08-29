#include<stdio.h>

int main(){
    int a,b;
    printf("Enter Number 1:");
    scanf("%d",&a);
    printf("\nEnter Number 2: ");
    scanf("%d",&b);
    printf("\n");
    if (a>b){
        printf("%d is greater than %d\n",a,b);
    }
    if (a<b){
        printf("%d is less than %d\n",a,b);
    }
    if (a>=b){
        printf("%d is greater than or equal to  %d\n",a,b);
    }
    if (a<=b){
        printf("%d is less than or equal to %d\n",a,b);
    }
    if (a==b){
        printf("%d is equal to %d\n",a,b);
    }
    if (a!=b){
        printf("%d is not equal to %d\n",a,b);
    }
    return 0;
}