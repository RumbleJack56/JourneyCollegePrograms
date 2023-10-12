#include<stdio.h>
int main(){
    char a[30],b[30],c[30];


    scanf("%s",&a);
    while((getchar())!='\n');
    printf("\n");
    
    gets(b);
    
    printf("\n");
    
    fgets(c,30,stdin);
    
    
    printf("\n");
    printf("a is %s \n",a);
    printf("b is %s \n",b);
    printf("c is %s \n",c);

}