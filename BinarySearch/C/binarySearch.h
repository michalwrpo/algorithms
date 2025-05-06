#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

// Minimalizes number of comparisons
int BinarySearch(int *arr, int start, int end, int value) {

// Minimalizes number of comparisons
// Version for longs
long BinarySearch_long(long *arr, long start, long end, long value);

// Checks the midpoint every time, better best case time
int BinarySearch1(int *arr, int start, int end, int value);

// Checks the midpoint every time, better best case time
// Version for longs
long BinarySearch1_long(long *arr, long start, long end, long value);

#endif