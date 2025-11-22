// solution.cpp
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> buff;

        string curr("");
        for (int i = 0; i < path.size(); i++) {
            char c = path[i];
            if (c == '/') {
                saveCurrIfNeeded(buff, curr);
                curr = "";
            } else {
                curr += c;
            }
        }

        saveCurrIfNeeded(buff, curr);

        if (buff.empty()) {
            return "/";
        } else {
            return join(buff, '/');
        }
    }
    
private:
    void saveCurrIfNeeded(vector<string>& buff, const string& curr) {
        if (curr == "..") {
            if (!buff.empty()) {
                buff.pop_back();
            }
        } else {
            if (curr != "" && curr != ".") {
                buff.push_back(curr);
            }
        }
    }

    string join(const vector<string>& vec, char sep) {
        string res;
        for (int i = 0; i < vec.size(); i++) {
            res += sep + vec[i];
        }
        return res;
    }
};
