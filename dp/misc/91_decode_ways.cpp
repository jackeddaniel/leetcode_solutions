#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int bt(string& s, int i, vector<int>& memo) {
        if(s[i] == '0') return 0;
        if(i >= s.size()) return 1;
        if(i == s.size()-1) return 1;
        if(memo[i] != -1) return memo[i];

        int res;

        if(i < s.size()-1 && stoi(s.substr(i, 2)) <= 26) {
            memo[i] = bt(s, i+1, memo) + bt(s, i+2, memo);
        } else {
            memo[i] =  bt(s, i+1, memo);
        }
        return memo[i];
    }
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return bt(s,0, memo);
    }
};

