// Write a C program to implement Bitwise Operators.
#include<stdio.h>
int main(){
    int a,b;
    printf("Enter Number 1: ");
    scanf("%d",&a);
    printf("Enter Number 2: ");
    scanf("%d",&b);
    printf("\n");

    printf("Bitwise And : %d\nBitwise OR : %d\nBitwise XOR : %d\nBitwise NOT : %d  %d\nBitwise Leftshift : %d  %d\nBitwise Rightshift : %d   %d\n",a&b,a|b,a^b,~a,~b,a<<1,b<<1,a>>1,b>>2);
}