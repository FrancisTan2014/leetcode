# 76. Minimum Window Substring

Given two strings `s` and `t` of lengths `m` and `n` respectively, return *the **minimum window substring** of* `s` *such that every character in* `t` *(including duplicates) is included in the window*. If there is no such substring, return *the empty string* `""`.

The testcases will be generated such that the answer is **unique**.

 

**Example 1:**

```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

**Example 2:**

```
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
```

**Example 3:**

```
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
```

 

**Constraints:**

- `m == s.length`
- `n == t.length`
- `1 <= m, n <= 10^5`
- `s` and `t` consist of uppercase and lowercase English letters.

 

**Follow up:** Could you find an algorithm that runs in `O(m + n)` time?

---


### Declaration
- `int need[52]`: the character frequency counts of `t`
- `int window[52]`: the character frequency counts of the current window
- `int ts`: the size of `t`
- `pl`: the left pointer of the current window
- `pr`: the right pointer of the current window
- `ll`: the left pointer of the last matched window
- `lr`: the right pointer of the last matched window
- `m`: the matched count of character type in the current window

### Fast Return
Return imediately if the length of `s` is less than the lenght of `t`.

### Algorithm (Origin)
1. Compute `need` by going through all letters of `t`, increasing the values of each slot.
2. Expand `pr` till the end, let `c` repsent each letter, for each step:
    - a. Increase `window[c]`
    - b. Increase `m` if `window[c] >= need[c]`
    - c. If `m == ts`, update `ll` and `lr` if the size of the current window is less, skip the following judges
    - d. If `m` is greater than `ts`, move `pl` till `m < ts`, let `ci` represent each letter, for each step:
        - Decrease `window[ci]`
        - Decrease `m` if `window[ci] < need[c]`
3. Return `""` if the distance between `ll` and `lr` is `0`; otherwise, return the substring between `ll` and `lr`.

---


# Corrected Description of the Algorithm (ChatGPT)

## 1. Declarations
- `int need[52]`: the frequency counts of characters in `t`
- `int window[52]`: the frequency counts of characters in the current window
- `int requiredTypes`: the number of distinct characters in `t` that must be satisfied
- `int valid`: the number of character types currently satisfied in the window
- `int pl`: left pointer of the current window
- `int pr`: right pointer of the current window
- `int bestL`: left index of the smallest valid window found
- `int bestR`: right index of the smallest valid window found

## 2. Fast Return
Return immediately if the length of `s` is less than the length of `t`.

## 3. Algorithm (Revised)
1. Build the `need` array by scanning all characters of `t`.  
   Count how many distinct characters appear to determine `requiredTypes`.

2. Expand the window by moving `pr` from left to right:
   - Let `c` be the current character.  
   - Increase `window[c]`.  
   - If `window[c]` becomes equal to `need[c]`, increase `valid`.

3. When `valid == requiredTypes`, attempt to shrink the window:
   - Update `bestL` and `bestR` if the current window is smaller.
   - Then repeatedly move `pl` right:
     - Let `d` be the character at `pl`.  
     - Decrease `window[d]`.  
     - If `window[d]` becomes less than `need[d]`, decrease `valid` and stop shrinking.

4. After the process ends:
   - If no valid window was found, return an empty string.
   - Otherwise return the substring between `bestL` and `bestR`.

