#include <stdio.h>
#include <string.h>

struct student {
    char name[10];
    int rank;
};

int main() {
    struct student arr[5] = {{"John", 3}, {"Alice", 1}, {"Bob", 5}, {"Emily", 2}, {"David", 4}};

    // print initial array
    printf("Initial array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s, %d\n", arr[i].name, arr[i].rank);
    }
    printf("\n");

    // bubble sort
    for (int i = 0; i < 4; i++) { // iterate n-1 times
        for (int j = 0; j < 4-i; j++) { // iterate n-1-i times
            if (arr[j].rank > arr[j+1].rank) {
                // swap
                struct student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s, %d\n", arr[i].name, arr[i].rank);
    }

    return 0;

}