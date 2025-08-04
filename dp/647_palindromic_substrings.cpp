class Solution {
    public:
        void help(string s, int l, int r, int& res) {
            while(l > -1 && r < s.size() && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
        }
        
        int countSubstrings(string s) {
            int res = 0;

            for(int i = 0; i < s.size(); i++) {
                help(s,i,i,res);
                help(s,i,i+1,res);
            }
            return res;

        }
};
