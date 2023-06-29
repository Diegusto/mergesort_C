#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int right[], int leftLength, int rightLength) {
    int i = 0, j = 0, k = 0;

    // Mescla os subarrays left e right em ordem crescente
    while (i < leftLength && j < rightLength) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes do subarray left
    while (i < leftLength) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copia os elementos restantes do subarray right
    while (j < rightLength) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int length) {
    if (length < 2)
        return;

    int mid = length / 2;
    int left[mid];
    int right[length - mid];

    // Divide o array em dois subarrays: left e right
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < length; i++) {
        right[i - mid] = arr[i];
    }

    // Chama recursivamente mergeSort para ordenar os subarrays left e right
    mergeSort(left, mid);
    mergeSort(right, length - mid);

    // Mescla os subarrays left e right em arr
    merge(arr, left, right, mid, length - mid);
}

void printArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 5, 7, 1, 3, 6, 2};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenacao:\n");
    printArray(arr, length);

    // Chama a função mergeSort para ordenar o array
    mergeSort(arr, length);

    printf("Array apos a ordenacao:\n");
    printArray(arr, length);
    system("pause");
    return 0;
}
