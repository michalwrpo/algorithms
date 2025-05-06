package binarysearch

// Minimalizes the average number of comparisons
func BinarySearch(arr []int, start, end, value int) int {
	if end-start < 2 {
		if arr[start] == value {
			return start
		}
		return -1
	}

	mid := (start + end) / 2

	if arr[mid] > value {
		return BinarySearch(arr, start, mid, value)
	} else {
		return BinarySearch(arr, mid, end, value)
	}
}

// Checks the midpoint every time, better best case time
func BinarySearch1(arr []int, start, end, value int) int {
	if end-start < 2 {
		if arr[start] == value {
			return start
		}
		return -1
	}

	mid := (start + end) / 2

	if arr[mid] == value {
		return mid
	} else if arr[mid] > value {
		return BinarySearch(arr, start, mid, value)
	} else {
		return BinarySearch(arr, mid, end, value)
	}
}
