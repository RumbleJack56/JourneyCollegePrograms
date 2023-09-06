#include<stdio.h>
namespace closed{
    int a= 10;
}
int main(){
    
    int c = 3;
    printf("%d",c);
    c++;
    printf("%d  %d",c,closed::a);
    return 0;
}


