// solution.cpp
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Sliding Window Pattern - 11/24/2025
    // Ajusted implementation using sliding window technique
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();

        unordered_map<char, int> seen;
        int pl = 0;
        int pr = 0;
        int maxLength = 1;
        int counter = 0;
        while (pr < s.size()) {
            char c = s[pr];
            auto it = seen.find(c);
            if (it == seen.end() || it->second < pl) {
                counter++;
            } else {
                if (counter > maxLength) {
                    maxLength = counter;
                }
                counter = pr - it->second;
                pl = it->second + 1;
            }
            seen[c] = pr;
            pr++;
        }

        if (counter > maxLength) {
            maxLength = counter;
        }
        
        return maxLength;
    }

    int lengthOfLongestSubstring_BeforeLearningSlidingWindow_Pattern(string s) {
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
