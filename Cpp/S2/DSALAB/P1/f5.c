#include<stdio.h>
int main(){
  int arr[] = {2,4,6,41,12,4,1,4,2};   
  int len = sizeof(arr)/sizeof(arr[0]);

  for (int k=1; k<len; k++) {
      int key= arr[k];
      int m= k-1;
      // find till sortpos reached, and then swap
      while (m>=0 && arr[m] > key) {
          arr[m+1]= arr[m];
          m= m-1;
      }
      //now continue sorting from new tillsorted point
      arr[m+1]= key;
  }

  for (int k=0; k<len; k++) {
      printf("%d ", arr[k]);
  }

  return 0;

}