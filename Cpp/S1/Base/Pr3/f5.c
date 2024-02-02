#include<stdio.h>
int main(){
    int a,rev=0;
    printf("Enter Number: ");
    scanf("%d",&a);


    while (a!=0){
        rev=10*rev + (a%10);
        a/=10;

    }
    printf("%d",rev);
    return 0;
}