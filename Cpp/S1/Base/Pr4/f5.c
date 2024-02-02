#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter Number 1: ");
    scanf("%d",&a);
    printf("Enter Number 2: ");
    scanf("\n%d",&b);
    if (a<b){
        c=a;
        a=b;
        b=c;
    }
    while(b!=0){
        c = a;
        a = b;
        b = c%b;
    }
    printf("The HCF is %d",a);
    return 0;
}