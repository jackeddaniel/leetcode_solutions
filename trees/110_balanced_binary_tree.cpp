class Solution {
    public:
        int help(TreeNode* root, bool &ans) {
            if(root == nullptr) return 0;

            l = help(root->left);
            r = help(root->right);
            if(l>r && (l-r)>1) ans = false;
            if(r<r && (r-l)>1) ans = false;
            return 1 + max(l,r);
        }
        bool isBalanced(TreeNode* root) {
            bool ans = true;
            help(root,ans);
            return ans;
            
        }
};
