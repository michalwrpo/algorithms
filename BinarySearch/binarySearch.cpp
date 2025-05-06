#include <iostream>
#include <vector>

#include "binarySearch.hpp"

// Minimalizes number of comparisons
template <typename T>
long BinarySearch(T *arr, long start, long end, T value) {
    if (end - start < 2) {
        if (arr[start] == value) {
            return start;
        }
        return -1;
    }
    
    long mid = (start + end) / 2;

    if (arr[mid] > value) {
        return BinarySearch(arr, start, mid, value);
    } else {
        return BinarySearch(arr, mid, end, value);
    }
}

// Minimalizes number of comparisons
// Version for vectors
template <typename T>
long BinarySearch(std::vector<T> vec, long start, long end, T value) {
    if (end - start < 2) {
        if (vec.at(start) == value) {
            return start;
        }
        return -1;
    }
    
    long mid = (start + end) / 2;

    if (vec.at(mid) > value) {
        return BinarySearch(vec, start, mid, value);
    } else {
        return BinarySearch(vec, mid, end, value);
    }
}

// Checks the midpoint every time, better best case time
template <typename T>
long BinarySearch1(T *arr, long start, long end, T value) {
    if (end - start < 2) {
        if (arr[start] == value) {
            return start;
        }
        return -1;
    }
    
    long mid = (start + end) / 2;

    if (arr[mid] == value) {
        return mid;
    } else if (arr[mid] > value) {
        return BinarySearch1(arr, start, mid, value);
    } else {
        return BinarySearch1(arr, mid, end, value);
    }
}

// Checks the midpoint every time, better best case time
// Version for vectors
template <typename T>
long BinarySearch1(std::vector<T> vec, long start, long end, T value) {
    if (end - start < 2) {
        if (vec.at(start) == value) {
            return start;
        }
        return -1;
    }
    
    long mid = (start + end) / 2;

    if (vec.at(mid) == value) {

    } else if (vec.at(mid) > value) {
        return BinarySearch(vec, start, mid, value);
    } else {
        return BinarySearch(vec, mid, end, value);
    }
}

int main() {
    int arr[5] = {2, 3, 4, 5, 9};
    std::cout << BinarySearch(arr, 0, 5, 9) << std::endl;
    std::cout << BinarySearch(arr, 0, 5, 7) << std::endl;

    std::cout << BinarySearch1(arr, 0, 5, 9) << std::endl;
    std::cout << BinarySearch1(arr, 0, 5, 7) << std::endl;
    
    std::vector<int> vec = {1, 3, 6, 7}; 
    std::cout << BinarySearch(vec, 0, 4, 3) << std::endl;
    std::cout << BinarySearch(vec, 0, 4, 4) << std::endl;
}