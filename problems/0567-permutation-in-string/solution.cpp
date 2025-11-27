// solution.cpp
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        if (s1.size() == 1) {
            return s2.find_first_of(s1[0]) != string::npos;
        }

        int need[26] = { 0 };
        int window[26] = { 0 };
        build_frequency_table(s1, need);

        int pl = 0;
        for (int pr = 0; pr < s2.size(); pr ++) {
            char c = s2[pr];
            window[c - 'a']++;

            int w = pr - pl + 1; // window size
            if (w < s1.size()) {
                continue;
            } 

            if (w > s1.size()) {
                window[s2[pl] - 'a']--;
                pl++;
            }

            if (matches(s1, need, window)) {
                return true;
            }
        }

        return false;
    }

private:
    bool matches(const string& charset, const int need[], const int window[]) {
        for (char c: charset) {
            int index = c - 'a';
            if (need[index] != window[index]) {
                return false;
            }
        }
        return true;
    }

    void build_frequency_table(const string& s, int freq[26]) {
        for (char c: s) {
            freq[c - 'a']++;
        }
    }
};
