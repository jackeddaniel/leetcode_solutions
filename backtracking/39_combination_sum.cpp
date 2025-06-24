class Solution {
	public:

		void backtrack(vector<int>& candidates, int target, int i, vector<vector<int>>& res, vector<int>& tmp) {
			if(target == 0) {
				res.push_back(tmp);
				return;
			}
			if(i == candidates.size() || target < 0) {
				return;
			}

			tmp.push_back(candidates[i]);
			backtrack(candidates, target-candidates[i], i, res, tmp);
			tmp.pop_back();

			backtrack(candidates, target, i+1, res, tmp);
		}
		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			vector<vector<int>> res;
			vector<int> tmp;
			backtrack(candidates, target, 0, res,tmp);
			return res;
		}
};
