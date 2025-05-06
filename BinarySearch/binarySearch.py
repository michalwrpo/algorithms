from typing import List

def BinarySearch(arr: List, start: int, end: int, value):
    if end - start < 2:
        if arr[start] == value:
            return start
        return -1
    
    mid = (start + end) // 2

    if arr[mid] > value:
        return BinarySearch(arr, start, mid, value)
    else:
        return BinarySearch(arr, mid, end, value)