class Solution {
    public:
        void help(int i , vector<int>& nums, vector<vector<int>>& res) {
            if(i == nums.size()) {
                res.push_back(nums);
                return;
            }

            unordered_set<int> used;

            for(int j = i; j < nums.size(); j++) {
                if(used.count(nums[j])) continue;

                used.insert(nums[j]);

                swap(nums[i], nums[j]);
                help(i+1, nums, res);
                swap(nums[i], nums[j]);
            }
        }

        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end());

            vector<vector<int>> res;
            help(0, nums, res);
            return res;
        }
};
