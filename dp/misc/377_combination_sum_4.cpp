#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int solve(vector<int>& nums, int target, vector<int>& memo) {
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(memo[target] != -1) return memo[target];

        int accumulate = 0;

        for(int j = 0; j < nums.size(); j++) {
            accumulate += solve(nums, target-nums[j], memo);
        }
        return memo[target] = accumulate;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target+1, -1);
        return solve(nums, target, memo);
    }

};
