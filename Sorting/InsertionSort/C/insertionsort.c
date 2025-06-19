#include "insertionsort.h"

void insertionSort(long* array, long len) {
    long key, i;

    for (long j = 1; j < len; j++) {
        key = array[j];
        i = j - 1;
        while (i > -1 && array[i] > key) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
}

// Sorts an array in non-increasing order
void insertionSortDecreasing(long* array, long len) {
    long key, i;
    
    for (long j = 1; j < len; j++) {
        key = array[j];
        i = j - 1;
        while (i > -1 && array[i] < key) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
}