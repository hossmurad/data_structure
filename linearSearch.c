#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index where the key is found
        }
    }

    return -1; // Return -1 if the key is not found
}

int main() {
    int arr[] = {2, 5, 7, 12, 18, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 18;

    int result = linearSearch(arr, n, key);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
