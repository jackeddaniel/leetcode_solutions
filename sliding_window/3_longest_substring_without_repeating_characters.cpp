class Solution {
    public:
        int lengthOfLongestSubstring(string s) {

            unordered_map<char,int> check;

            int start = 0;
            int end = 0;
            int ans = 0;

            while (end < s.size()) {
                 if (check.find(s[end]) == check.end() || check[s[end]] < start) {
                     check[s[end]] = end;
                     end++;
                     ans = max(ans, end-start);
                 } else {
                     start = check[s[end]]+1;
                     //check[s[end]] = end;
                 }
            }

            return ans;
        }
};

