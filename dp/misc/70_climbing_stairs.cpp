#include<vector>

using namespace std;
class Solution {
public:
    int bt(int n, vector<int>& memo) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;

        if(memo[n] != -1) return memo[n];

        return memo[n] = bt(n - 1, memo) + bt(n - 2, memo);
    }
    int climbStairs(int n) {
        vector<int> memo(n+1, -1);
        return bt(n, memo);
    }
};
