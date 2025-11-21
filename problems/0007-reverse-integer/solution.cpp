// solution.cpp
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x > -10 && x < 10) {
            return x;
        }

        vector<int> digits = reverseDigits(x);

        bool isNegative = x < 0;
        bool isOverflowed = false;
        if (isNegative) {
            vector<int> intMinDigits = { -2, -1, -4, -7, -4, -8, -3, -6, -4, -8 };
            isOverflowed = isNegativeOverflow(digits, intMinDigits);
        } else {
            vector<int> intMaxDigits = { 2, 1, 4, 7, 4, 8, 3, 6, 4, 7 };
            isOverflowed = isPositiveOverflow(digits, intMaxDigits);
        }

        if (isOverflowed) {
            return 0;
        } else {
            return composeDigits(digits);
        }
    }

    int reverseByChatGPT(int x) {
        int result = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check potential overflow before multiplying
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && digit > INT_MAX % 10))
                return 0;

            if (result < INT_MIN / 10 ||
                (result == INT_MIN / 10 && digit < INT_MIN % 10))
                return 0;

            result = result * 10 + digit;
        }

        return result;
    }

private:
    vector<int> reverseDigits(int x) {
        vector<int> digits;
        int modResult = 0;
        int divisor = 10;
        while (true) {
            modResult = x % divisor;
            digits.push_back(modResult);
            if (modResult == x) {
                break;
            }
            
            x /= divisor;
        }

        return digits;
    }

    int composeDigits(const vector<int>& digits) {
        int result = 0;
        int multiplier = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            result += digits[i] * multiplier;
            if (i > 0) {
                // Avoid integer overflow in multiplier
                multiplier *= 10;
            }
        }
        return result;
    }

    bool isPositiveOverflow(vector<int> reversedDigits, vector<int> boundary) {
        if (reversedDigits.size() != boundary.size()) {
            return false;
        }

        for (int i = 0; i < reversedDigits.size(); i++) {
            if (reversedDigits[i] < boundary[i]) {
                return false;
            } else if (reversedDigits[i] == boundary[i]) {
                continue;
            } else {
                return true;
            }
        }

        return false;
    }

    bool isNegativeOverflow(vector<int> reversedDigits, vector<int> boundary) {
        if (reversedDigits.size() != boundary.size()) {
            return false;
        }

        for (int i = 0; i < reversedDigits.size(); i++) {
            if (reversedDigits[i] > boundary[i]) {
                return false;
            } else if (reversedDigits[i] == boundary[i]) {
                continue;
            } else {
                return true;
            }
        }

        return false;
    }
};
