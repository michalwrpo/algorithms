# Binary Addition

Addition of two binary numbers represented as arrays.

## Problem

**<u>Input:</u>** Two binary numbers represented as arrays of equal length, from the most significant bit to the least one.

**<u>Output:</u>** One binary number represented as array, which is a sum of the two given ones.

## Pseudocode

`if` checks can be removed if we're absolutely sure of input correctness.

```
BinaryAddition(num1, num2):
    if length(num1) != length(num2):
        return NIL

    sum = 0
    carry = 0

    for i = length(num1)-1 down to 0:
        if num1[i] not in {0, 1}:
            return NIL

        if num2[i] not in {0, 1}:
            return NIL
        
        sum = num1[i] + num2[i] + carry
        carry = floor(sum / 2) // integer division
        ans[i + 1] = sum mod 2
    
    ans[0] = carry

    return ans
```

## Time Complexity

**Average case:** $\theta(n)$  
**Worst case:** $\theta(n)$  
**Best case:** $\theta(n)$

Assignments before and after loop are in constant time, all operation in loop are in constant time, loop executes once for every bit of length, thus giving us linear time complexity.


## Memory complexity - O(n)

Constant memory size for sum and carry, ans requires space to store n + 1 bits, where n is the length of inputs.

## Proof of correctness

The only possible option for invalid inputs is when:
1. Arrays have different length, which is handled by `if` statement before the loop.
2. Arrays contain something other than bits, which is handled by `if` statements inside the loop.
Both cases are handled, so we will assume that inputs are correct in the rest of the proof.

**Loop invariant:** At the start of each iteration of for loop in lines 5-14 ans[i+2..length(num1)] contains the result of addition of the length(num1)-1-i least significant bits of num1 and num2, while carry contains the overflow from the sum of num1[i+1] and num2[i+1].

**Initialization:** Before the start of the loop ans is empty (so in a sense contains the sum of the first zero bits) and carry = 0, which matches the lack of overflow, so the loop invariant holds.

**Maintenance:** `if` statements inside the loop do not modify any variables, so we can move past them.

Let's consider all possible bit sums separately, using a table

| num1[i] | num2[i] | carry | sum (binary) | sum (decimal) | current digit | overflow | $\lfloor$sum / 2$\rfloor$ | sum mod 2 |  
| -----:  | ------: | ----: | -----------: | ------------: | ------------: | -------: | ------------------------: | --------: |
| 0       | 0       | 0     | 0            | 0             | 0             | 0        | 0                         | 0         |
| 0       | 0       | 1     | 1            | 1             | 1             | 0        | 0                         | 1         |
| 0       | 1       | 0     | 1            | 1             | 1             | 0        | 0                         | 1         |
| 0       | 1       | 1     | 10           | 2             | 0             | 1        | 1                         | 0         |
| 1       | 0       | 0     | 1            | 1             | 1             | 0        | 0                         | 1         |
| 1       | 0       | 1     | 10           | 2             | 0             | 1        | 1                         | 0         |
| 1       | 1       | 0     | 10           | 2             | 0             | 1        | 1                         | 0         |
| 1       | 1       | 1     | 11           | 3             | 1             | 1        | 1                         | 1         |

As we can see, in all 8 cases the remainder of sum divided by 2 matches the overflow and integer division of sum by 2 matches the currect digit, so ans[i] holds the current digit and carry holds the overflow from sum of num1[i] and num2[i]. We don't modify other bits of ans, so loop invariant holds.

**Termination:** Loop terminates when i < 0, so i = -1. From our loop invariant it gives us that ans[1..length(num1)] constains the result of addition of the n = length(num1) least siginificant bits (which are all the bits) of num1 and num2, while carry contains the overflow from the sum of num1[0] and num2[0], so their most significant bits. Then we assign carry to ans[0], which results in ans holding the result of addition of num1 and num2 and the algorithm is correct. $\square$