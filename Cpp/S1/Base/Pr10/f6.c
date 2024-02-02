#include <stdio.h>
void bubbleSort(int arr[], int n){
    int temp, swapped;
    do {
        swapped = 0;
        for (int i = 1; i < n; i++){
            if (arr[i - 1] > arr[i]){
                temp = arr[i - 1];
                arr[i - 1] = arr[i]; arr[i] = temp; swapped = 1;
            }
        }
    } while (swapped);
}
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
