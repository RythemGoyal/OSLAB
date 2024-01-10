#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the middle element is the target
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore left half
        if (arr[mid] < target)
            low = mid + 1;
        // If target is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If the target is not present in the array
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [sorted integers] [target]\n", argv[0]);
        return 1;
    }

    int n = argc - 2; // Number of elements in the array
    int arr[n]; // Array to store the sorted integers

    // Parse the command-line arguments into the array
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    int target = atoi(argv[argc - 1]); // Target value to search

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
