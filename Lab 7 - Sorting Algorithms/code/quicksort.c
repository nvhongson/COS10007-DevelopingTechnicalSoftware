#include <stdio.h>
#include <string.h>

struct veg {
    char item[10];
    int price;
};

void swap(struct veg* a, struct veg* b) {
    struct veg t = *a;
    *a = *b;
    *b = t;
}

int partition(struct veg arr[], int low, int high) {
    int pivot = arr[high].price;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].price <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct veg arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(vegetables, 0, n - 1);

    printf("Sorted array:\n");
    printArray(vegetables, n);

    return 0;
}
