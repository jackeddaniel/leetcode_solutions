#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool issquare(int n) {
        if(n == 0) return false;
        if(n == 1) return true;

        for(int i = 0; i <= n/2; i++) {
            if(i*i == n) return true;
        }
        return false;
    }

    int bt(int n, vector<int>& memo) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(memo[n] != -1) return memo[n];

        //if(issquare(n)) return memo[n] = 1;

        int res = INT_MAX;

        for(int i = n; i > 0; i--) {
            if(issquare(i)) {
                int tmp = 1 + bt(n-i, memo);
                res = min(res, tmp);
            } else {
                continue;
            }
        }
        return memo[n] = res;
    }
    int numSquares(int n) {
        vector<int> memo(n+1, -1);
        return bt(n, memo);
    }
};
