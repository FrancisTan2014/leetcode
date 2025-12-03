#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(const vector<int>& nums, int k) {
        if (nums.size() < k) return 0;
        if (k == 1) return atMostKDistinct(nums, 1);
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }

/**
 * The elegant version of atMostKDistinct was developed by following the guide of AI.
 * It gave me the core insight `count += right - left + 1` after reviewing my own implementation.
 */
private:
    int atMostKDistinct(const vector<int>& nums, int k) {
        unordered_map<int, int> seen;

        int distinct = 0;
        int count = 0;

        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (seen[nums[right]]++ == 0) {
                distinct++;
            }

            while (distinct > k) {
                if (--seen[nums[left++]] == 0) {
                    distinct--;
                }
            }

            count += right - left + 1;
        }
        
        return count;
    }

/*
* The following code was wrote by myself, it works but it is hard to maintain and understand.
*/
private:
    int atMostKDistinct_byMySelf(const vector<int>& nums, int k) {
        int lastRight = -1;
        unordered_map<int, int> seen;

        int count = 0;
        int left = 0;
        int right = 0;
        int distinct = 0;
        for (right = 0; right < nums.size(); right++) {
            if (seen[nums[right]]++ == 0) {
                distinct++;
            }

            if (distinct > k) {
                count += compute_increment(left, right - 1, lastRight);
                lastRight = right - 1;
                
                while (distinct != k) {
                    if (--seen[nums[left++]] == 0) {
                        distinct--;
                    }
                }
            }
        }

        count += compute_increment(left, right - 1, lastRight);

        return count;
    }

    int compute_increment(int left, int right, int lastRight) {
        int duplicated_num_count = lastRight - left + 1;
        int len = right - left + 1;
        int current_window_sub_cnt = compute_subarrays(len);
        int duplicated_sub_cnt = compute_subarrays(duplicated_num_count);
        return current_window_sub_cnt - duplicated_sub_cnt;
    }

    int compute_subarrays(int n) {
        return n * (n + 1) / 2;
    }
};
