#include <string>
#include <vector>


// we need the optimized version for this
using namespace std;

class Solution {
public:

    bool ispalindrome(string& s, int i, int j) {
        if (i > j) return false;
        while (i < j) {
            if (s[i] == s[j]) {
                i++; 
                j--;
            } else {
                return false;
            }
        }
        return true;
    }

    int bt(string& s, vector<vector<int>>& memo, int i, int j) {
        if (i >= j) return 0;
        if (ispalindrome(s, i, j)) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int mn = INT_MAX;

        for (int k = i; k < j; k++) {
            int tmp = 1 + bt(s, memo, i, k) + bt(s, memo, k+1, j);
            mn = min(mn, tmp);
        }

        return mn;
    }
    int minCut(string s) {
        
        vector<vector<int>> memo(1001, vector<int>(1001, -1));
        return bt(s, 0, s.size())-1;
    }
};
