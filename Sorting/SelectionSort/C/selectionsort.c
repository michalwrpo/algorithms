#include "selectionsort.h"

void swap(int* array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int min(int* array, int l, int h) {
    int min_value = array[l];
    int min_index = l;

    for (int i = l; i < h + 1; i++) {
        if (array[i] < min_value) {
            min_value = array[i];
            min_index = i;
        }
    }
    
    return min_index;
}

void selectionSort(int* array, int len) {
    int min_index;
    for (int i = 0; i < len - 1; i++) {
        min_index = min(array, i, len - 1);
        swap(array, min_index, i);
    }
}
