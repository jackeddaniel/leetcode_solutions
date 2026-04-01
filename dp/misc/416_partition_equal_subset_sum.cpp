#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    //we just gotta find out if there is one solution this is not a coungint problem
    int solve(vector<int>& nums, int i, int sum, vector<vector<int>>& memo) {
        if(sum == 0) return true;
        if(i >= nums.size()) return false;
        if(memo[i][sum] != -1) return memo[i][sum];
        // at every index, we can either take or not take
        bool skips = solve(nums, i+1, sum, memo);

        if(nums[i] <= sum) {
            bool takes = solve(nums, i+1, sum-nums[i], memo);

            return memo[i][sum] = takes || skips;
        } else {
            return memo[i][sum] = skips;
        }
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        vector<vector<int>> memo(n+1, vector<int>(sum+1, -1));

        return solve(nums, 0, sum/2, memo);
    }
};
