# Insertion Sort

Sorts the array by taking elements one at a time and inserting them to into proper place among previously sorted elements.

## Pseudocode 

*Taken from third edition of "Introduction to Algorithms" by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. Modified to fit repository standards*

```
InsertionSort(A):
    for j = 1 to length(A) - 1:
        key = A[j]
        i = j - 1
        while i > -1 and A[i] > key:
            A[i + 1] = A[i]
            i = i - 1
        A[i + 1] = key
```

`InsertionSortDecreasing` changes direction of comparison in while, i.e. `A[i] < key`.