#include<stdio.h>

int ncr(int a,int b){
    int c = b;
    int d = a;
    int ret = 1;
    for (int k=0; k<b;++k){
        ret*=d;
        d--;
    }
    for (int k=0; k<b;++k){
        ret/=c;
        c--;
    }
    return ret;
}


int main(){
    printf("%d",ncr(5,3));
}

