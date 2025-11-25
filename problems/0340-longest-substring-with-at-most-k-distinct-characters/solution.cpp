// solution.cpp
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> charCount;
        int maxLength = 0;
        int pl = 0;
        int dc = 0;
        for (int pr = 0; pr < s.size(); pr++) {
            if (charCount[s[pr]] == 0) {
                dc++;
            }
            charCount[s[pr]]++;

            while (dc > k) {
                --charCount[s[pl]];
                if (charCount[s[pl]] == 0) {
                    dc--;
                }
                pl++;
            }
            
            maxLength = max(maxLength, pr - pl + 1);
        }

        return maxLength;
    }
};
