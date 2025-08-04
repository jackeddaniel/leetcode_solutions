class Solution {
    public: 
        int help(int i, vector<int>& nums, vector<int>& dp) {
            if(i >= nums.size()) return  0;
            if(dp[i] != -1) return dp[i];

            int rob_this = nums[i] + help(i+2, nums, dp);
            int skip_this = help(i+1, nums, dp);

            return dp[i] = max(rob_this, skip_this);
        }
        int rob(vector<int>& nums) {
            vector<int> dp(nums.size(), -1);
            return help(0, nums, dp);
        }
};
