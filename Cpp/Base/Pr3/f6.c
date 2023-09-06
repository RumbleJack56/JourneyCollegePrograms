#include<stdio.h>

int main(){



int a=0,b=10,c=20;
int d = a && ++b && ++c;
printf("%d %d %d %d \n", a,b,c,d);

a++;
int e = a && (++b>20) && ++c;
printf("%d %d %d %d \n", a,b,c,e);

int f = ++a || (++b && ++c);
printf("%d %d %d %d \n", a,b,c,f);
a= a+(++a);
printf("%d",a);
return 0;   

int inp;
scanf("%d",&inp);
switch (inp)
{
case "1":
    
    break;

default:
    break;
}




}