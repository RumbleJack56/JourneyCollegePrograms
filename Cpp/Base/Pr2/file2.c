<<<<<<< HEAD
#include <stdio.h>
int main(){
    int a,b;
    printf("Enter Number 1: ");
    scanf("%d",&a);
    printf("Enter Number 2: ");
    scanf("%d",&b);
    while (b != 0){
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    if (a&1 == 1){
        printf("%f",(float)(a >> 1) + 0.5);
    }
    else{
        printf("%d",a >> 1);
    }
    
=======
#include <stdio.h>
int main(){
    int a,b;
    printf("Enter Number 1: ");
    scanf("%d",&a);
    printf("Enter Number 2: ");
    scanf("%d",&b);
    while (b != 0){
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    if (a&1 == 1){
        printf("%f",(float)(a >> 1) + 0.5);
    }
    else{
        printf("%d",a >> 1);
    }
    
>>>>>>> 673eca3828584dd9cb320f13ffcee4031144e733
}