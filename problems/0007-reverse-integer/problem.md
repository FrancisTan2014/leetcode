# 7. Reverse Integer

Given a signed 32-bit integer ```x```, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range ```[-2^31, 2^31 - 1]```, then return 0.

`Assume the environment does not allow you to store 64-bit integers (signed or unsigned).`

 

### Example 1:

> Input: x = 123
> Output: 321

Example 2:
> Input: x = -123
> Output: -321

Example 3:
> Input: x = 120
> Output: 21
 

### Constraints:

- ```-2^31 <= x <= 2^31 - 1```

---

## Thinking
- Is there any one step approach? "No"
- Can I reverse a number by bit operations? "No"
- What is the brute-force approach?
    - Extract all digits by repeating `MOD` operations with 10^n(n >=0)
    - Break from the loop when the result of MOD equals to x (the origin number)
    - Return numbers in the range of [-9,9] without any operations
- How can I determine if a case is overflow?
    - Assume that all digits are stored in a `vector<byte>`
    - Assume that `int.MinValue` is converted to `vector<byte> min`
    - Assume that `int.MaxValue` is converted to `vector<byte> max`
    - Reverse this vector and compare the result with `min/max`
        - if `x < 0`, overflow occurs when any digit is less than its counterpart of `min`
        - if `x > 0`, overflow occurs when any digit is greater than its counterpart of `max`