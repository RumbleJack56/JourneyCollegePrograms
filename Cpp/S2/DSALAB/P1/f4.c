#include<stdio.h>
int main(){
  int arr[] = {2,4,6,41,12,4,1,4,2};   
  int len = sizeof(arr)/sizeof(arr[0]);
  for (int k=0; k<len-1; k++) {
    int sortpos=k;
    int curMin=k;
    for (int m= k+1; m<=len-1; m++){
      if (arr[m] < arr[curMin]) {curMin=m;}
    }
    int temp= arr[curMin];
    arr[curMin]= arr[sortpos];
    arr[sortpos]= temp;
  }


  for (int i=0; i<len; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}