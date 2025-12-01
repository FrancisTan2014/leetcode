#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.length() <= k) return s.length();

        int left = 0;
        int right = 0;
        
        int seen[26] = {0};
        
        int max_len = 0;
        int most_freq = 0;

        while (right < s.length()) {
            char c = s[right];
            if (++seen[c - 'A'] > most_freq) {
                most_freq = seen[c - 'A'];
            }

            while ((right - left + 1) - most_freq > k) {
                seen[s[left++] - 'A']--;
            }

            max_len = max(max_len, right - left + 1);
            right++;
        }

        return max_len;
    }
};
