# Selection Sort

Sorts the array by finding the n-th element in n-th step and swapping it with the n-th element of the array, until the array is sorted. 

## Problem

**<u>Input:</u>** An array of length n.

**<u>Output:</u>** The same array, but sorted.


## Pseudocode 

```
Min(A, l, h):
    min = A[l]
    min_index = l
    for i = l+1 to h:
        if A[i] < min:
            min = A[i]
            min_index = i

    return min_index

SelectionSort(A):
    for i = 0 to length(A) - 2:
        min_index = Min(A, i, lenth(A) - 1)
        swap(A[i], A[min_index])
```

## Time complexity

**Average case:** $\theta(n^2)$  
**Worst case:** $\theta(n^2)$  
**Best case:** $\theta(n^2)$

`Min` function does all operation inside and outside the loop in constant time, so it takes O(h - l) time.  
In each iteration of the loop in `SelectionSort`, `Min` function is called with arguments `l = i` and `h = n -1`, so the total time complexity is  
$\sum_{i=0}^{n-2} O(n - 1 - i) = \sum_{i=1}^{n-1} O(i) = O\left(\frac{n(n-1)}{2}\right) = O(n^2).$

## Memory complexity - O(n)

Algorithm only requires enough memory to store the initial array and two variables at the same time.

## Proof of correctness 

### Min

**Loop invariant:** At the start of k-th iteration of the loop min holds the smallest value in A[l..l+k-1] and min_index hold the index at which this value appears in array.

**Initialization:** At the start, k = 1 and min holds A[l], which is trivially the smallest value in A[l..l] and min_index holds its index, which is l, so the loop invariant holds.  

**Maintenance:** During the k-th iteration, we check if A[l+k] is smaller than min, thus the smallest value in A[l..l+k], if it's not we continue and the loop invariant holds, if it is, we change the value of min to A[l+k] and min_index to l+k, so the loop invariant also holds.

**Termination:** The loop terminates, when l + k > h, so l + k = h + 1 and by out loop invariant we know that min is set to the smallest value in A[l..h] and min_index is set to the index of the smallest value, so the algorithm is correct.

### SelectionSort

**Loop invariant:** At the start of i-th iteration of the loop A[0..i-1] contains the i smallest numbers in A in nondescending order.

**Initialization:** At the start, A[0..-1] has no elements so the loop invariant holds.

**Maintenance:** During the i-th loop, A[0..i-1] contains the i smallest values of A in sorted order and we find the minimum of A[i..n-1] i.e. the remaining terms, so the next smallest value in array and then swap it with A[i], so the loop invariant holds.

**Termination:** When the loop terminates, i = length(A) - 1 = n - 1, so A[0..n-2] contains the n-1 smallest numbers in A in nondescending order, but then A[n-1] is bigger than all of them, so the entire array is sorted.
