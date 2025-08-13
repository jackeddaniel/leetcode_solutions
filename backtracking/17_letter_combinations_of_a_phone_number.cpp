class Solution {
    public:
        void help(int i,  string& s, string& digits, vector<string>& res, vector<vector<char>>& track){
            if(s.size() == digits.size()) {
                res.push_back(s);
                return;
            }

            char c = digits[i];
            int curr = c - '0';

            for(int j = 0; i < track[curr].size(); j++) {
                s += track[curr][j];
                help(j+1, s, digits, res, track);
                s.pop_back();
            }
        }


                

        vector<string> letterCombinations(string digits) {
            vector<vector<char>> track= {
                {},                     // 0
                {},                     // 1
                {'a', 'b', 'c'},        // 2
                {'d', 'e', 'f'},        // 3
                {'g', 'h', 'i'},        // 4
                {'j', 'k', 'l'},        // 5
                {'m', 'n', 'o'},        // 6
                {'p', 'q', 'r', 's'},   // 7
                {'t', 'u', 'v'},        // 8
                {'w', 'x', 'y', 'z'}    // 9
            };
            vector<string> res;
            string s;

            help(0, s, digits, res, track);
            return res;




        }
};
