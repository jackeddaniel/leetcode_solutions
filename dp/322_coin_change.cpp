class Solution {
    public:
        int solve(int amount, vector<int>& coins, vector<int>& memo) {
            if(amount < 0) return INT_MAX;
            if(amount == 0) return 0;
            if(memo[amount] != -2) return memo[amount];

            int min_coins = INT_MAX;
            for(int coin : coins) {
                int res = solve(amount - coin, coins, memo);
                if(res != INT_MAX) {
                    min_coins = min(min_coins, 1 + res);
                }
            }

            memo[amount] = min_coins;
            return memo[amount];
        }



        int coinChange(vector<int>& coins, int amount) {
            vector<int> memo(amount+1, -2);
            memo[0] = 0;
            int ans = solve(amount, coins, memo);
            return ans == INT_MAX ? -1 : ans;
        }
};

