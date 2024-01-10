#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int item_to_search = 25;
    bubbleSort(arr, n);

    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        char *args[n + 3]; // Extra space for program name, item_to_search, and NULL
        char buffer[10];

        args[0] = "./binary_search"; // Assuming the binary search program is named binary_search
        for (int i = 0; i < n; i++) {
            sprintf(buffer, "%d", arr[i]);
            args[i + 1] = strdup(buffer);
        }
        args[n + 1] = strdup("-1"); // Placeholder for the searched item (to be replaced)
        args[n + 2] = NULL;

        // Replace the placeholder with the item to search
        sprintf(buffer, "%d", item_to_search);
        args[n + 1] = strdup(buffer);

        execve(args[0], args, NULL);
    } else {
        
        // Parent process
        wait(NULL); // Wait for the child process to finish sorting

        // Sort the array
        

        // Print the sorted array
        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Parent process completed.\n");
    }

    return 0;
}
