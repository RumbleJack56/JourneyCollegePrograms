#include<stdio.h>
int sum(int n){
    if (n==1){
        return 1;
    }
    else{
        return sum(n-1) + n;
    }
}

int main()
{
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
//      this has a value  it gets stored into output variable 
//                |
//                V
    int output = sum(n);
//        A        |
//        |        V
//         <-------

    printf("sum is %d",output);
}