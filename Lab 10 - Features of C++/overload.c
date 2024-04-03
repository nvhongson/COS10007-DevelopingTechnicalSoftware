#include <iostream>

// Overload 1: countNegative for integer arrays
int countNegative(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) { // If the current element is negative, increment the count
            count++;
        }
    }
    return count;
}

// Overload 2: countNegative for floating point arrays
int countNegative(float arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) { // If the current element is negative, increment the count
            count++;
        }
    }
    return count;
}

int main() {
    // Test the countNegative function with integer array
    int arr1[] = {1, -2, 3, -4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int negCount1 = countNegative(arr1, size1);
    if (negCount1 > 0) { // If there are negative numbers, print how many there are
        std::cout << "There are " << negCount1 << " negative numbers in the integer array." << std::endl;
    } else { // Otherwise, print that there are none
        std::cout << "There are no negative numbers in the integer array." << std::endl;
    }

    // Test the countNegative function with floating point array
    float arr2[] = {1.5, -2.3, 3.7, 4.2, -5.1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int negCount2 = countNegative(arr2, size2);
    if (negCount2 > 0) { // If there are negative numbers, print how many there are
        std::cout << "There are " << negCount2 << " negative numbers in the floating point array." << std::endl;
    } else { // Otherwise, print that there are none
        std::cout << "There are no negative numbers in the floating point array." << std::endl;
    }

    // Test the countNegative function with floating point array that has no negative numbers
    float arr3[] = {1.5, 2.3, 3.7, 4.2, 5.1};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int negCount3 = countNegative(arr3, size3);
    if (negCount3 > 0) { // If there are negative numbers, print how many there are
        std::cout << "There are " << negCount3 << " negative numbers in the floating point array." << std::endl;
    } else { // Otherwise, print that there are none
        std::cout << "There are no negative numbers in the floating point array." << std::endl;
    }

    return 0;
}
