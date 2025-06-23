class Solution {
    public:
        void help(TreeNode* root, int max, int &ans) {
            if(root == nullptr) return;
            if(root->val >= max) {
                ans++;
                max = root->val;
            }

            help(root->left,max,ans);
            help(root->right,max,ans);
        }

        int goodNodes(TreeNode* root) {
            int ans = 0;
            //we initiliase the checker var to min int to account for negatives
            int var = INT_MIN;

            help(root,var,ans);

            return ans;
        }

};
