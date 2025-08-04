class Solution {
    public:
        int min_cost(int i, vector<int>& cost, vector<int>& dp) {
            if(i >= cost.size()) return 0;
            if(dp[i] != -1) return dp[i];

            int one_step = min_cost(i+1, cost, dp);

            int two_step = min_cost(i + 2, cost, dp);

            return dp[i] = cost[i] + min(one_step, two_step);
        }

        int minCostClimbingStairs(vector<int>& cost) {

            vector<int> dp(cost.size(), -1);

            if(dp.size() == 1) return dp[0];
            return min(dp[0], dp[1]);
        }
};
