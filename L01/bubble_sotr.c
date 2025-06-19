#include <stdlib.h>
#include <stdio.h>

int* bubble_sort(int arr[], int n);

int main() {
    int arr[] = {5, 2, 9, 1, 3, 6};
    int n = 6;

    int* sorted_arr = bubble_sort(arr, n);

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
    
    free(sorted_arr);
    return 0;
}

int* bubble_sort(int arr[], int n) {
    int* sorted = (int*)malloc(n * sizeof(int));

    if (sorted == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }

    // Perform bubble sort on the copy
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sorted[j] > sorted[j + 1]) {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    return sorted;
}