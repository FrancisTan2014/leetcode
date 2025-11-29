// solution.cpp
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        int need[52] = {0};
        int window[52] = {0};

        int required = build_frequency_table(t, need);
        int valid = 0;

        int left = 0;
        int bestL = -1;
        int bestLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            int rslot = get_slot_index(s[right]);
            window[rslot]++;

            if (window[rslot] == need[rslot])
                valid++;

            // While the window is valid, try shrinking it
            while (valid == required) {
                // Update best window BEFORE shrinking
                int currLen = right - left + 1;
                if (currLen < bestLen) {
                    bestLen = currLen;
                    bestL = left;
                }

                // Shrink from the left
                int lslot = get_slot_index(s[left]);
                window[lslot]--;

                if (window[lslot] < need[lslot])
                    valid--;

                left++;
            }
        }

        if (bestL == -1) return "";
        return s.substr(bestL, bestLen);
    }

private:
    // Maps 'A'–'Z' to 0–25 and 'a'–'z' to 26–51
    int get_slot_index(char c) {
        if (c >= 'A' && c <= 'Z')
            return c - 'A';
        return 26 + (c - 'a');
    }

    int build_frequency_table(const string &str, int table[52]) {
        int types = 0;
        for (char c : str) {
            int idx = get_slot_index(c);
            if (table[idx] == 0)
                types++;
            table[idx]++;
        }
        return types;
    }
};
