#include <stdio.h>

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i], temp2;
            for (temp2 = i; temp2 >= gap && arr[temp2 - gap] > temp; temp2 -= gap) {arr[temp2] = arr[temp2 - gap];}
            arr[temp2] = temp;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}