class Solution {
    public:
        void bt(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp) {
            if(tmp.size() == nums.size()) {
                res.push_back(tmp);
                return;
            }

            for(int i = 0; i < nums.size(); i++) {
                if(find(tmp.begin(), tmp.end(), nums[i]) != tmp.end()) continue;

                tmp.push_back(nums[i]);

                bt(nums,res,tmp);
                tmp.pop_back();

            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> res;
            vector<int> tmp;
            bt(nums,res,tmp);
            return res;
        }

};
