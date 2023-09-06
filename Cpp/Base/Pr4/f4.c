#include<stdio.h>

int main(){
    int inp;
    
    printf("enter number: ");
    scanf("%d",&inp);


    for (int k=1;k<=inp;++k){
    
    
        int a=0,b=1,c;
        if (k==1){printf("%d ",a);}

        else if (k==2){printf("%d ",b);}
        
        else{
            for(int j=0;j<k-2;++j){
            c=a+b;
            a=b;
            b=c;
            }
            printf("%d ",c);
        }
    }
    return 0;
}