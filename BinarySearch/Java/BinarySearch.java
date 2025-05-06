package BinarySearch.Java;

class BinarySearch {
    // Minimalizes the average number of comparisons
    public static <T extends Comparable<T>> int binarySearch(T[] arr, int start, int end, T value) {
        if (end - start < 2) {
            if (arr[start].equals(value)) {
                return start;
            }
            return -1;
        }

        int mid = (start + end) / 2;

        if (arr[mid].compareTo(value) > 0) {
            return binarySearch(arr, start, mid, value);
        } else {
            return binarySearch(arr, mid, end, value);
        }
    }

    // Checks the midpoint every time, better best case time
    public static <T extends Comparable<T>> int binarySearch1(T[] arr, int start, int end, T value) {
        if (end - start < 2) {
            if (arr[start].equals(value)) {
                return start;
            }
            return -1;
        }

        int mid = (start + end) / 2;

        if (arr[mid].equals(value)) {
            return mid;
        } else if (arr[mid].compareTo(value) > 0) {
            return binarySearch1(arr, start, mid, value);
        } else {
            return binarySearch1(arr, mid, end, value);
        }
    }
}