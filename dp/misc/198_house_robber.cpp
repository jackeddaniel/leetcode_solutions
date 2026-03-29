
class Solution {
public:
    int bt(vector<int>& nums, int i, vector<int>& memo) {
        if(i >= nums.size()) return 0;
        if(memo[i] != -1) return memo[i];

        return memo[i] = max(nums[i] + bt(nums, i+2, memo), bt(nums, i+1, memo));
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size()+1, -1);
        return bt(nums, 0, memo);
    }
};
