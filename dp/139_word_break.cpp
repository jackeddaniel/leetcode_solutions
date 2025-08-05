class Solution {
    public:
        bool check(string& s, vector<string>& wordDict, int l, int r) {
            return find(wordDict.begin(), wordDict.end(), s.substr(l, r-l+1)) != wordDict.end();
        }

        bool solve(int l, string& s, vector<string>& wordDict, vector<int>& dp) {
            if(l == s.size()) return true;

            if(dp[l] != -1) return dp[l];

            for(int r = l; r < s.size(); r++) {
                if(check(s, wordDict, l, r)) {
                    if(solve(r+1, s, wordDict, dp)) {
                        return dp[l] = true;
                    }
                }
            }

            return dp[l] = false;
        }

        bool wordBreak(string s, vector<string>& wordDict) {
            vector<int> dp(s.size(), -1);
            return solve(0, s, wordDict, dp);
        }
};

                        
