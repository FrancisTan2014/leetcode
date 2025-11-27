# 567. Permutation in String

Given two strings `s1` and `s2`, return `true` *if* `s2` *contains a permutation of* `s1`*, or* `false` *otherwise*.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.

 

**Example 1:**

```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
```

**Example 2:**

```
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
```

 

**Constraints:**

- `1 <= s1.length, s2.length <= 10^4`
- `s1` and `s2` consist of lowercase English letters.

---

## Thinking process
The window size is fixed and equal to the size of `s1`, so we initialize `pl` and `pr` to `0` and `s1.size() - 1`, and expand the window as the loop proceeds.
The difficult part is determining whether the current window is a permutation of `s1`.
The brute-force idea would be to generate all permutations of `s1` and store them in a map, then check membership, but that is obviously too expensive.
There must be a clever way to avoid generating all permutations.

How can we determine if a string `s` is the permutation of another string `t`?
- a. Enumerate all permuations of `t`
- b. Some clever logic way
    - Two strings are permutations of each other if and only if  
        they have identical character frequency counts.


### Algorithm
1. Return `false` if `s2.size() < s1.size()`.
2. Build the frequency array of `s1` to the unordered map `need`.
3. Iterate each characters of `s2` with the expanding index `i`, for each `c` we do:
    - a. Increase `window[c]`;
    - b. Jump to the next cycle if `i` is less `s1.size()`, otherwise, we have the full frenquency array built;
    - c. Compare `need` with `window`, return `true` if they have identical character frequency counts;
    - d. Decrease the frequency count of the character that leaves the sliding window if exists;
    - e. Return `false` if no permutations of `s1` are found after the loop.

### Corrected (English)
With the guidance you've given me, I’ll try to describe the algorithm using the following steps:

1. Return false if s2.size() is smaller than s1.size().
2. Build a frequency map need for the characters in s1.
3. Iterate through s2 using an expanding index i. For each character c:
    - a. Increment window[c].
    - b. If i is still less than s1.size() - 1, continue to the next iteration; otherwise the first full window has been formed.
    - c. Compare window and need; if they match, return true.
    - d. Remove the character that slides out of the window by decrementing its count in window.

4. If the loop finishes with no match, return false.