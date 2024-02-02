#include<stdio.h>
void arrMerge(int[] a, int[] b)
{
    int lena = sizeof(a)/sizeof(a[0]);
    int lenb = sizeof(b)/sizeof(b[0]);
    
    static int arr[a+b];

    for (int k=0;k<lena;++k){
        arr[k]=a[k];
    }
    for (int k=0;k<lenb;++k){
        arr[k+lena]=b[k];
    }
}


int main(){
    int arr1[] = {2,3};
    int arr2[] = {9,3};
    arrMerge(arr1,arr2); 
    return 0;
    
}



/*
Traversal
Copying
Reversing
Sorting
Insertion
Deletion
Searching
Merging
*/