#include<stdio.h>
int main(){
    int n1,n2,n3,n4;
    printf("Enter Number 1: ");
    scanf("%d",&n1);
    printf("Enter Number 2: ");
    scanf("\n%d",&n2);
    printf("Enter Number 3: ");
    scanf("\n%d",&n3);
    printf("Enter Number 4: ");
    scanf("\n%d",&n4);
    float avg = (n1 + n2 + n3 + n4)/4.;
    printf("Average of %d,%d,%d and %d is %.2f",n1,n2,n3,n4,avg);
    return 0;
}