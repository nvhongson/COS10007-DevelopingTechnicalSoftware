//Part A 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function for Binary Search
int binary_search(int arr[], int start, int end, int key);

int main() {
    // Initialize the array with random integers
    int arr[10];
    srand(time(NULL)); // Adding this so there is no duplicate result 
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 101; // Generate a random integer between 0 and 100
    }

    // Sorting array using loop 
    for (int i = 0; i < 9; i++) {
        for (int j = i+1; j < 10; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print the sorted array using a for loop
    printf("Initial sorted array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input from user for search key 
    int key;
    printf("Enter the search key: ");
    scanf("%d", &key);

    // Call function for binary search 
    int location = binary_search(arr, 0, 9, key);

    // Print the search result 
    if (location == -1) {
        printf("%d not found in the array\n", key);
    } else {
        printf("%d found at location %d in the array\n", key, location);
    }

    return 0;
}
// Part B
// Function definition for binary search
int binary_search(int arr[], int begin, int end, int key) {
    // While there are still elements to search in the sub-array
    while (begin <= end) {
        // Calculate the middle of the sub-array
        int mid = (begin + end) / 2;
        // Print the current sub-array being searched
        printf("Sub-array: ");
        for (int i = start; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        // If the middle element is equal to the key, return the middle index
        if (arr[mid] == key) {
            return mid;
        // If the middle element is less than the key, search the right half of the sub-array
        } else if (arr[mid] < key) {
            start = mid + 1;
        // If the middle element is greater than the key, search the left half of the sub-array
        } else {
            end = mid - 1;
        }
    }
    // If the key is not found in the sub-array, return -1
    return -1;
}
