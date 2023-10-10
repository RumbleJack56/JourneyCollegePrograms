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
    int arr[] = {1,2,2,3,3,3,4,5,6,8,8,8,8,9};

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