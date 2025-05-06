// Minimalizes number of comparisons
int BinarySearch(int *arr, int start, int end, int value) {
    if (end - start < 2) {
        if (arr[start] == value) {
            return start;
        }
        return -1;
    }
    
    int mid = (start + end) / 2;

    if (arr[mid] > value) {
        return BinarySearch(arr, start, mid, value);
    } else {
        return BinarySearch(arr, mid, end, value);
    }
}

// Minimalizes number of comparisons
// Version for longs
long BinarySearch_long(long *arr, long start, long end, long value) {
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

// Checks the midpoint every time, better best case time
int BinarySearch1(int *arr, int start, int end, int value) {
    if (end - start < 2) {
        if (arr[start] == value) {
            return start;
        }
        return -1;
    }
    
    int mid = (start + end) / 2;

    if (arr[mid] == value) {
        return mid;
    } else if (arr[mid] > value) {
        return BinarySearch(arr, start, mid, value);
    } else {
        return BinarySearch(arr, mid, end, value);
    }
}

// Checks the midpoint every time, better best case time
// Version for longs
long BinarySearch1_long(long *arr, long start, long end, long value) {
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
        return BinarySearch(arr, start, mid, value);
    } else {
        return BinarySearch(arr, mid, end, value);
    }
}