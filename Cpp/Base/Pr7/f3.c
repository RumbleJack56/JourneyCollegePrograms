#include<stdio.h>
int main(){
    int n,keyFound=0;
    printf("Enter Number: ");
    scanf("%d",&n);
    int arr[] = {1,5,18,3,9,2,6,4,3,11};
    int len = &arr;
    printf("%d",len);
    len = (&arr + 1);
    printf("%d",len);
    len = *(&arr + 1);
    printf("%d",len);
    len = *(&arr + 1) - arr;
    printf("%d",len);
    

    for (int i=0; i<len;++i){
        if (arr[i]==n){
            keyFound=1;
            printf("%d found at index %d",n,i);
            break;
        }
    }
    if(keyFound==0){
        printf("%d not found in array",n);
    }

}