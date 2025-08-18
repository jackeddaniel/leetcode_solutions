class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int global_max = nums[0];
            int current_max = nums[0];

            for(int i = 1; i < nums.size(); i++) {
                current_max = max(current_max + num[i], nums[i]);
                global_max = max(global_max, current_max);
            }

            return global_max;

        }
};
