#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> indices;

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            
            while (!indices.empty()) {
                int top_i = indices.top();
                if (t > temperatures[top_i]) {
                    indices.pop();
                    answer[top_i] = i - top_i;
                } else {
                    break;
                }
            }

            indices.push(i);
        }

        return answer;
    }
};
