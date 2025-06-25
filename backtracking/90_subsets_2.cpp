class Solution {
    public:
        void help(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, int start) {
            res.push_back(tmp);

            for(int i = start; i < nums.size(); i++) {
                if(i>start && nums[i] == nums[i-1]) continue;

                tmp.push_back(nums[i]);
                help(nums,res,tmp,i+1);
                tmp.pop_back();
            }
        }

            vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                vector<vector<int>> res;
                vector<int> tmp;
                sort(nums.begin(), nums.end());
                help(nums,res,tmp,0);
                return res;
            }
};       
