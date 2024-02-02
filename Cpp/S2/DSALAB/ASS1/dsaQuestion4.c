/*
    QUESTION STEM:
    WAP IN C TO IMPLEMENT QUICK SORT ON AN ARRAY. ASSUME THAT THE ARRAY IS CUSTOM INPUT BY THE USER.
*/

/*
    What quick sort does:
        It keeps a pivot element that helps us divide arrays into two different sub arrays where 
        all elements before the pivot are smaller (but unsorted/sorted) and all elements after
        pivot are larger(and unsorted/sorted).

        We then recursively run on each smaller array until l>=r
*/

#include<stdio.h>

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high] to place the pivot at its correct position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Function to perform QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the pivot index such that elements smaller than the pivot are on the left,
        // and elements greater than the pivot are on the right
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 4, 5, 6, 7, 3, 1, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}