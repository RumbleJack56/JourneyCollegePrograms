#include<stdio.h>
void pattern(int n){
    for (int k=1; k<=n;++k){
        for (int j=0; j<n-k;++j){printf("  ");}
        for (int j=k; j>0;--j){printf("%d ",j);}
        for (int j=2; j<=k;++j){printf("%d ",j);}
        printf("\n");
    }

}
int main(){
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    pattern(n);
    return 0;
}