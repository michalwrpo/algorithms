#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

// Minimalizes number of comparisons
template <typename T>
long BinarySearch(T *arr, long start, long end, T value);

// Minimalizes number of comparisons
// Version for vectors
template <typename T>
long BinarySearch(std::vector<T> vec, long start, long end, T value);

// Checks the midpoint every time, better best case time
template <typename T>
long BinarySearch1(T *arr, long start, long end, T value);

// Checks the midpoint every time, better best case time
// Version for vectors
template <typename T>
long BinarySearch1(std::vector<T> vec, long start, long end, T value);

#endif