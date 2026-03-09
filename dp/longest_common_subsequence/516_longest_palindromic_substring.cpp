
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> t(n, vector<int>(n, 0));

        for (int i = n-1; i >= 0; i--) {
            t[i][i] = 1;
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) {
                    t[i][j] = 2 + t[i+1][j-1];
                } else {
                    t[i][j] = max(t[i+1][j], t[i][j-1]);
                }
            }
        }

        return t[0][n-1];
    }
};


class Solution {
public:
    int bt(string& s, int i, int j, vector<vector<int>>& memo) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == s[j]) {
            return memo[i][j] = 2 + bt(s, i+1, j-1,memo);
        } else {
            return memo[i][j] = max(bt(s, i+1, j,memo), bt(s, i, j-1,memo));
        }
    }
    int longestPalindromeSubseq(string s) {

        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));

        return bt(s, 0, s.size()-1, memo);
    }
};
