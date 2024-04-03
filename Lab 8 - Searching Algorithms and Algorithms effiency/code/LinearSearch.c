
// Part A
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function for Linear Search 
int linear_search(int arr[], int size, int key);

int main() {
    // Array 10 intergers 
    int arr[10];
    srand(time(NULL)); // Adding this so there is no duplicate result
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 101; // Generate a random integer between 0 and 100
    }

    // Print the initial array
    printf("Initial array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Search key 
    int key;
    printf("Enter the search key: ");
    scanf("%d", &key);

    // Call function for linear search
    int location = linear_search(arr, 10, key);

    // Print the search result
    if (location == -1) {
        printf("%d not found in the array\n", key);
    } else {
        printf("%d found at location %d in the array\n", key, location);
    }

    return 0;
}
//Part B 
// Function definition for linear search
int linear_search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the number if found
        }
    }
    return -1; // Return -1 if the element was not found
}
