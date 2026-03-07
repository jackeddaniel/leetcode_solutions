#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;
/*
class Solution {
public:
    int bt(string& a, string& b, int n, int m, vector<vector<int>>& memo) {
        if (n == 0 || m == 0) return 0;

        if (memo[n][m] != -1) return memo[n][m];

        if (a[n-1] == b[m-1]) {
             return memo[n][m] = 1 + bt(a, b, n-1, m-1, memo);
        } else {
            return memo[n][m] = max(bt(a, b, n-1, m, memo), bt(a, b, n, m-1, memo));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        return bt(text1, text2, text1.size(), text2.size(), memo);
    }
};
*/

class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            int n = text1.size();
            int m = text2.size();

            vector<vector<int>> tab(n+1, vector<int>(m+1, 0));
            
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    if(text1[i-1] == text2[j-1]) {
                        tab[i][j] = 1 + tab[i-1][j-1];
                    } else {
                        tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
                    }
                }
            }
            return tab[n][m];
        }
};

