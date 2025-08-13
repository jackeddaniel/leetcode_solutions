class Solution {
    public:
        bool is_p(string& s, int start, int end) {
            while(start < end) {
                if(s[start] != s[end]) return false;
                start++;
                end--;
            }
            return true;

        }

        void help(int start, int end, string& s, vector<string>& tmp, vector<vector<string>>& res) {
            if(end == s.size()) {
                return;
            }
            if(is_p(s, start, end)) {
                string sub = s.substr(start, end-start+1);
                tmp.push_back(sub);
                if(end == s.size()-1) res.push_back(tmp);
                help(end+1, end+1, s, tmp, res);
                tmp.pop_back();
            }

            help(start, end+1, s, tmp, res);
        }
        

        vector<vector<string>> partition(string s) {
            vector<vector<string>> res;
            vector<string> tmp;
            help(0, 0, s, tmp, res);
            return res;
        }

};
