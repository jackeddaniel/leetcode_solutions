class Solution {
    public:
        void bt(vector<int>& candidates, vector<vector<int>>& res, vector<int>& tmp, int i, int target) {
            if(target == 0) {
                res.push_back(tmp);
            }

            for(int a = i; a < candidates.size(); a++) {
                if(a > i && candidates[a] == candidates[a-1]) continue;
                
                if(candidates[a] > target) break;

                tmp.push_back(candidates[a]);

                bt(candidates, res, tmp, a + 1, target - candidates[a]);
                tmp.pop_back();
            }
        }

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> res;
            vector<int> tmp;

            sort(candidates.begin(), candidates.end());
            
            bt(candidates, res, tmp, 0, target);
            return res;
        }
};
