#include<stdio.h>


int binarySearch(int arr[],int arrlen,int val){
  int min=0;
  int max=arrlen-1;

  while (min<max){
    int mid = (min+max)/2;
    if (arr[mid]==val){
      return mid;
    }
    else if (arr[mid]>val){
      max=mid-1;
    }
    else{
      min=mid+1;
    }
  }
  return -1;
}

int main(){
  int arr[] = {1,2,3,4,5,6,7,8,9};
  int len = sizeof(arr)/sizeof(arr[0]);
  printf("Index of Element \"%d\" in array is : %d\n",3,binarySearch(arr,len,3));
}