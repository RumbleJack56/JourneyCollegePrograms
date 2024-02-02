#include<stdio.h>
int main(){
    int* ptr;
    int var = 1029;
    ptr = &var;

    printf("%p, %p and %d\n",&ptr,ptr,*ptr);
    var = 4310;
    printf("%d, %p and %p\n",(int)*(*(&ptr)),ptr,*ptr);
    

    
}