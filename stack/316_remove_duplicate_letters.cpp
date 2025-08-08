class Solution {
    public:
        string removeDuplicateLetters(string s) {
            vector<int> count(26, 0);
            vector<int> visited(26, 0);

            for(int i = 0; i < s.size(); i++) {
                int loc = s[i] - 'a';
                count[loc]++;
            }

            stack<char> s;

            for(int i = 0; i < s.size(); i++) {
                count[s[i] - 'a']--;

                if(visited[s[i] - 'a']) {
                    continue;
                }

        }
};
