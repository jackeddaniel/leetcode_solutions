class Solution {
public:
    bool is_valid(int i, int j, vector<pair<int,int>>& tmp) {
        for (auto it : tmp) {
            int x = abs(it.first - i);
            int y = abs(it.second - j);

            if (x == 0 || y == 0 || x == y) return false;
        }
        return true;
    }

    void help(int i, int j, int n, vector<string>& base, vector<pair<int,int>>& tmp, vector<vector<string>>& res) {
        if (i == n) {
            if (tmp.size() == n) {
                vector<string> copy = base;
                for (auto it : tmp) {
                    copy[it.first][it.second] = 'Q';
                }
                res.push_back(copy);
            }
            return;
        }

        for (int b = 0; b < n; b++) {
            if (is_valid(i, b, tmp)) {
                tmp.push_back({i, b});
                help(i + 1, 0, n, base, tmp, res);
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<pair<int,int>> tmp;
        vector<string> base(n, string(n, '.'));
        help(0, 0, n, base, tmp, res);
        return res;
    }
};

