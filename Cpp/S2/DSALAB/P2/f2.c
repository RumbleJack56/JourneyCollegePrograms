#include <stdio.h>

int parting(int arr[],int L, int R){
  int piv = arr[R];
  int i = L;
  for (int k=L;k<R;++k){
    if (arr[k]<=piv) {
      int t = arr[i];
      arr[i]= arr[k];
      arr[k] =t;
      ++i;
      }
  }
  int t = arr[i+1];
  arr[i+1]= arr[R];
  arr[R] =t;
  return i+1;
}
void qSort(int arr[], int L, int R){
  if (L<R){
    int cen = parting(arr,L,R);
    qSort(arr,L,cen-1);
    qSort(arr,cen+1,R);
  }
}

int main() {
    int arr[] = {3,2,5,6,9,8,12};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Original array: ");
    for (int k=0;k<len;++k) {printf("%d ",arr[k]);} printf("\n");
    qSort(arr,0,len-1);
    printf("Sorted array: ");
    for (int k=0;k<len;++k) {printf("%d ",arr[k]);} printf("\n");
    return 0;
}
