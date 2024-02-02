#include<stdio.h>
#include<math.h>
int main(){
    int n,ncopy,armval=0,len=0;
    printf("Enter Number: ");
    scanf("%d",&n);
    ncopy=n;
    for (int i=0;i<n;i=i){
        n/=10;
        len+=1;
    }
    n = ncopy;
    for (int i=0;i<n;i=i){
        int t = n%10;
        armval += pow(t,len);
        n/=10;
    }
    if (armval==ncopy){printf("Arm is strong");}
    else {printf("Arm is weak");}
    return 0;
}
