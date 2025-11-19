// solution.cpp
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (charIndexMap.find(s[i]) != charIndexMap.end()) {
                maxLength = 1;
                charIndexMap.clear();
            } else {
                maxLength++;
            }
            charIndexMap[s[i]] = i;
        }

        return maxLength;
    }
};
