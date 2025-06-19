#include <stdio.h>
#include <stdlib.h>

int* insertion_sort(int arr[], int n);

int main() {
    int arr[] = {5, 2, 9, 1, 3, 6};
    int n = 6;

    int* sorted_arr = insertion_sort(arr, n);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    free(sorted_arr);  // Free the allocated memory
    return 0;
}

int* insertion_sort(int arr[], int n) {
    // Allocate memory for the new array
    int* sorted = (int*)malloc(n * sizeof(int));
    
    if (sorted == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Copy the original array
    for (int i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }

    // Perform insertion sort on the copy
    for (int i = 1; i < n; i++) {
        int key = sorted[i];
        int j = i - 1;

        while (j >= 0 && sorted[j] > key) {
            sorted[j + 1] = sorted[j];
            j--;
        }
        sorted[j + 1] = key;
    }

    return sorted;
}