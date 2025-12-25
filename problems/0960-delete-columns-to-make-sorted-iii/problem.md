# 960. Delete Columns to Make Sorted III

**Difficulty:** Hard

## Problem Description

You are given an array of `n` strings `strs`, all of the same length.

We may choose any **deletion indices**, and we delete all the characters in those indices for each string.

For example, if we have `strs = ["abcdef","uvwxyz"]` and deletion indices `{0, 2, 3}`, then the final array after deletions is `["bef","vyz"]`.

Suppose we chose a set of deletion indices `answer` such that after deletions, the final array has every string (row) in **lexicographic** order. (i.e., `(strs[i][0] <= strs[i][1] <= ... <= strs[i][strs[i].length - 1])` for all `0 <= i < n`).

Return the **minimum possible value** of `answer.length`.

## Examples

**Example 1:**

```
Input: strs = ["babca","bbazb"]
Output: 3
Explanation: After deleting columns 0, 1, and 4, the final array is strs = ["abc", "azb"].
Both these strings are in lexicographic order.
If we only delete column 0, then strs = ["babca", "bazb"].
We would still need to delete column 1 to make the first string sorted.
```

**Example 2:**

```
Input: strs = ["edcba"]
Output: 4
Explanation: If we delete fewer than 4 columns, the only row will not be lexicographically sorted.
```

**Example 3:**

```
Input: strs = ["ghi","def","abc"]
Output: 0
Explanation: All strings are already in lexicographic order, so no columns need to be deleted.
```

## Constraints

- `n == strs.length`
- `1 <= n <= 100`
- `1 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.
