#include<stdio.h>

int main(){
    int a,b,c;
    printf("Enter Three Numbers(seperated by spaces): ");
    scanf("%d %d %d",&a,&b,&c);
    int r1 = (a==b);
    int r2 = (c>b) ;
    int r3 = (a==b) && (c>b);
    int r4 = (a==b) || (c<b);
    int r5 = (a==b) || (b==c) || (a==c);
    int r6 = (a<=b) && (b<=c);
    int r7 = (a>=b) && (b>=c);
    
    printf("(a==b) is %d\n",r1);
    printf("(c>b) is %d\n",r2);
    printf("(a==b) && (c>b) is %d\n",r3);
    printf("(a==b) || (c<b) is %d\n",r4);
    printf("(a==b) || (b==c) || (a==c) is %d\n",r5);
    printf("(a<=b) && (b<=c) is %d\n",r6);
    printf("(a>=b) && (b>=c) is %d\n",r7);
    return 0;
}