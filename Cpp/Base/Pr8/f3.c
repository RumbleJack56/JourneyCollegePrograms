#include<stdio.h>

int binarySearch(int arr[],int x,int min,int max){
    int mid = (min+max)/2;
    if(max>=min){
        if (arr[mid]==x){
            return mid;
        } else if (arr[mid]<x){
            return binarySearch(arr,x,mid+1,max);
        } else{
            return binarySearch(arr,x,min,mid-1);
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Enter Length of Array: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;++i){
        printf("Enter Element %d: ",i+1);
        scanf("\n%d",&arr[i]);
    }

    int elemToSearch;
    printf("Enter Element to search: ");
    scanf("\n%d",&elemToSearch);

    int binSearchResult = binarySearch(arr,elemToSearch,0,sizeof(arr)/sizeof(arr[0]) -1);
    if (binSearchResult==-1){
        printf("Element %d not found",elemToSearch);
    }
    else{
        printf("Element %d found at index %d",elemToSearch,binSearchResult);
    }
    return 0;
}