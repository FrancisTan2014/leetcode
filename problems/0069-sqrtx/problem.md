# 69. Sqrt(x)

**Difficulty**: Easy

## Description

Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.
- For example, do not use `pow(x, 0.5)` in C++ or `x ** 0.5` in Python.

## Examples

### Example 1:
```
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
```

### Example 2:
```
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```

## Constraints

- `0 <= x <= 2^31 - 1`

## Algorithm

**Binary Search**:
- Search range: [0, x]
- For mid, check if `mid * mid <= x` and `(mid+1) * (mid+1) > x`
- Handle overflow: use `mid <= x/mid` instead of `mid*mid <= x`
- Time: O(log x), Space: O(1)
