from typing import List

# Minimalizes the average number of comparisons
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
    
# Checks the midpoint every time, better best case time
def BinarySearch1(arr: List, start: int, end: int, value):
    if end - start < 2:
        if arr[start] == value:
            return start
        return -1
    
    mid = (start + end) // 2

    if arr[mid] == value:
        return mid
    elif arr[mid] > value:
        return BinarySearch(arr, start, mid, value)
    else:
        return BinarySearch(arr, mid, end, value)
