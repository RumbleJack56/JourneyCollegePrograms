#include<stdio.h>
int main(){
  int arr[] = {2,4,6,41,12,4,1,4,2};   
  int len = sizeof(arr)/sizeof(arr[0]);
  for (int k=0;k<len-1;++k){
    int flag=0;
    for (int m=0;m<len-1;++m){
      if (arr[m]>arr[m+1]){
        int tem = arr[m];
        arr[m]=arr[m+1];
        arr[m+1]=tem;
        flag=1;
      }
    }
    if (flag==0) break;
  }
  for (int k=0;k<len;++k){
    printf("%d   ",arr[k]);
  }
}