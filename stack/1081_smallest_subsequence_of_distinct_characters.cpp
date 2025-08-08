class Solution {
    public:

        string smallestSubsequence(string s) {
            vector<int> last(26);
            vector<int> visited(26, 0);

            for(int i = 0; i < s.size(); i++) {
                last[s[i] - 'a'] = i;
            }

            stack<char> check;

            for(int i = 0; i < s.size(); i++) {
                if(visited[s[i] - 'a'] == 1) continue;

                while(!check.empty() && check.top() > s[i] && last[check.top() - 'a'] > i) {
                    visited[check.top() - 'a'] = 0;
                    check.pop();
                }

                check.push(s[i]);
                visited[s[i] - 'a'] = 1;
            }

            string res;

            while(!check.empty()) {
                res += check.top();
                check.pop();
            }

            reverse(res.begin(), res.end());
            return res;
        }
};

            

