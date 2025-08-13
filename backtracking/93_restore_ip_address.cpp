class Solution {
public:
    bool valid(const string& s, int a, int b) {
        if (a > b) return false;
        if (s[a] == '0' && a != b) return false; // leading zero
        int num = 0;
        for (int i = a; i <= b; i++) {
            if (!isdigit(s[i])) return false;
            num = num * 10 + (s[i] - '0');
        }
        return num <= 255;
    }

    void backtrack(int idx, int dot_count, string& s, vector<string>& path, vector<string>& res) {
        if (dot_count == 4) {
            if (idx == s.size()) {
                string ip = path[0];
                for (int i = 1; i < 4; i++) ip += "." + path[i];
                res.push_back(ip);
            }
            return;
        }

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            if (valid(s, idx, idx + len - 1)) {
                path.push_back(s.substr(idx, len));
                backtrack(idx + len, dot_count + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> path;
        backtrack(0, 0, s, path, res);
        return res;
    }
};

