#include<stdio.h>
int fib(int n){
    if (n<=1){
        return n;
    } else{
        return fib(n-1) + fib(n-2); 
    }
}
int main(){
    int num;
    printf("Enter Number: ");
    scanf("%d",&num);
    if (num<1){
        printf("Error number cant be lesser than 1");
        return -1;
    }
    for(int k=0;k<num;++k){
        printf("%d ",fib(k));
    }
    return 0;
}
// int main(){
//     int inp;
    
//     printf("enter number: ");
//     scanf("%d",&inp);


//     for (int k=1;k<=inp;++k){
    
    
//         int a=0,b=1,c;
//         if (k==1){printf("%d ",a);}

//         else if (k==2){printf("%d ",b);}
        
//         else{
//             for(int j=0;j<k-2;++j){
//             c=a+b;
//             a=b;
//             b=c;
//             }
//             printf("%d ",c);
//         }
//     }
//     return 0;
// }