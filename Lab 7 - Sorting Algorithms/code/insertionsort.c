#include <stdio.h>
#include <string.h>

struct veg {
    char item[10];
    int price;
};

void insertionSort(struct veg arr[], int n) {
    int i, j;
    struct veg temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].price > temp.price) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void printArray(struct veg arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%s\t%d\n", arr[i].item, arr[i].price);
    printf("\n");
}

int main() {
    struct veg vegetables[5] = {{"tomato", 10},
                                {"carrot", 20},
                                {"potato", 15},
                                {"onion", 5},
                                {"pepper", 25}};
    int n = sizeof(vegetables) / sizeof(vegetables[0]);

    printf("Initial array:\n");
    printArray(vegetables, n);

    insertionSort(vegetables, n);

    printf("Sorted array:\n");
    printArray(vegetables, n);

    return 0;
}
