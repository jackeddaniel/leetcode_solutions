class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& nums) {
            int current_max = nums[0];
            int current_min = nums[0];

            int global_max = nums[0];
            int global_min = nums[0];

            int total = nums[0];

            for(int i = 1; i < nums.size(); i++) {

                current_max = max(current_max + nums[i], nums[i]);
                current_min = min(current_min + nums[i], nums[i]);

                global_max = max(global_max, current_max);
                global_min = min(global_min, current_min);

                total += nums[i];
            }

            if(global_max < 0) return global_max;

            return max(global_max, total - global_min);

        }
};
