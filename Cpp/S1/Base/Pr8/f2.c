// Use Linear search to find the index of a given element
#include<stdio.h>
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

    //linear search algorithm

    for (int i=0; i<n;++i){
        if(arr[i]==elemToSearch){
            printf("Element %d found at index %d",elemToSearch,i);
            goto skipiffound;
        }
    }
    printf("Element %d not Found",elemToSearch);
    skipiffound:
    return 0;
}