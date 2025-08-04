class Solution {
    public:
        int help(int i, int end, vector<int>& nums, vector<int>& dp) {
            if(i >= end) return 0;
            if(dp[i] != -1) return dp[i];

            int rob_this = nums[i] + help(i+2, end, nums, dp);
            int skip_this = help(i+1, end, nums, dp);

            return dp[i] = max(rob_this, skip_this);
        }
        int rob(vector<int>& nums) {
            if(nums.size() == 1) return nums[0];
            vector<int> dp_1(nums.size(), -1);
            vector<int> dp_2(nums.size(), -1);

            int first_house = help(0, nums.size()-1, nums, dp_1);
            int second_house = help(1, nums.size(), nums, dp_2);
            return max(first_house, second_house);
        }
};
