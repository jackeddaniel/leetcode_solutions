class Solution {
    public:
        void help(TreeNode* root, int targetSum, vector<int>& tmp, vector<vector<int>>& res) {
            if(root == nullptr) {
                return;
            }

            if(root->left == nullptr && root->right == nullptr) {
                if(root->val == targetSum) {
                    tmp.push_back(root->val);
                    res.push_back(tmp);
                    tmp.pop_back();
                }
                return;
            }

            int num = root->val;
            tmp.push_back(num);

            if(root->left) help(root->left, targetSum - num, tmp, res);
            
            if(root->right) help(root->right, targetSum - num, tmp, res);

            tmp.pop_back();
        }


        vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<vector<int>> res;
            vector<int> tmp;

            help(root, targetSum, tmp, res);
            return res;
        }
};
