# 325. Maximum Size Subarray Sum Equals k

[Link to Problem](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)

## Description

Given an integer array `nums` and an integer `k`, return the maximum length of a contiguous subarray whose sum equals `k`. If there is no such subarray, return `0`.

## Examples

**Example 1:**
```
Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and has length 4.
```

**Example 2:**
```
Input: nums = [-2, -1, 2, 1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and has length 2.
```

## Constraints

- `1 <= nums.length <= 2 * 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `-10^9 <= k <= 10^9`
