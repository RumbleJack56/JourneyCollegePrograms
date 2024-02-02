#include<stdio.h>
void pattern(int n){
    for (int k=1;k<=n;++k){
        for (int j=n;j>n-k;--j)       {printf("%d  ",j);}
        for (int j=0;j<=2*(n-k)-1;++j){printf("%d  ",n+1-k);}
        for (int j=n+2-k;j<n+1;++j)   {printf("%d  ",j);}
        printf("\n");
    }
    for (int k=1;k<n;++k){
        for (int j=n;j>k;--j)     {printf("%d  ",j);}
        for (int j=0; j<2*k-1;++j){printf("%d  ",k+1);}
        for (int j=k+1; j<=n;++j) {printf("%d  ",j);}
        printf("\n");
    }
}
int main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    pattern(n);
    return 0;
}