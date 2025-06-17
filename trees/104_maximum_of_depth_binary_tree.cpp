class Solution {
    public:

        void help(TreeNode* root, int calc, int &res) {
            if(root == nullptr) return;

            calc++;
            res = max(calc,res);
            help(root->left,calc,res);
            help(root->right,calc,res);
        }

        int maxDepth(TreeNode* root) {
            int depth = 0;
            
            help(root,0,depth);
            return depth;
        }
};
