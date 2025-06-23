class Solution {
    public:
        void backtrack(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res, int i, int n) {
            if( i == n) {
                res.push_back(tmp);
                return;
            }

            // without considering nums[i]
            backtrack(nums, tmp, res, i+1,n);

            //add nums[i] to tmp i.e., considering nums[i]
            tmp.push_back(nums[i]);

            backtrack(nums, tmp, res, i+1,n);

            tmp.pop_back();
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> tmp;
            int n = nums.size();
            backtrack(nums, tmp, res, 0, n);

            return  res;
        }
};
