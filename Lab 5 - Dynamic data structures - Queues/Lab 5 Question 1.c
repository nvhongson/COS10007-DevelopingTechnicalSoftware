#include <stdio.h>
#include <string.h>

struct veg {
    char item[10];
    int price;
};

void merge(struct veg arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    struct veg L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i].price <= R[j].price) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct veg arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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

    mergeSort(vegetables, 0, n - 1);

    printf("Sorted array:\n");
    printArray(vegetables, n);

    return 0;
}
