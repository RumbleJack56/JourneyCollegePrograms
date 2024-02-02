#include<stdio.h>

int linearSearch(int arr[],int arrsize,int val){
  for (int k=0;k<arrsize;++k){
    if (arr[k]==val){
      return k;
    }
  }
  return -1;
}

int main(){
  int arr[] = {1,2,3,4,5,812,3,4,23,45,23,1};
  int len = sizeof(arr)/sizeof(arr[0]);

  printf("Index of Element \"%d\" in array is : %d\n",45,linearSearch(arr,len,45));
}

