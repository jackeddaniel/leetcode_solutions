class Solution {
    public:
        int help(int n, vector<int>& memo) {
            if(n == 1 || n == 0) return 1;

            if(memo[n] != -1) return memo[n];

            return memo[n] = help(n-1, memo) + help(n-2,memo);
        }




        int climbStairs(int n) {
            vector<int> memo(n+1, -1);
            return help(n,memo);
        }
};
