#include<stdio.h>

/*Args: Enter Array, Array Length,number to find*/
int binSearch(int arr[],int len,int n){
    int min=0, max = len;
    while(min<=max){
        int mid = (min + max)/2;
        if (arr[mid]==n){
            return mid;
            break;

        } else if(arr[mid]<n){
            min = mid+1;
        } else{
            max= mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);
    int arr[] = {1,2,4,7,8,12};
    printf("%d",binSearch(arr,sizeof(arr)/sizeof(arr[0]),n));
    return 0;
}