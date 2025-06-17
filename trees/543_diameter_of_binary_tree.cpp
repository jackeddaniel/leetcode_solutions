class Solution {
    public:
    int help(TreeNode* root, int &ans) {
        if(root == nullptr) return 0;

        int lheight = help(root->left, ans);
        int rheight = help(root->right, ans);

        ans = max(ans, lheight + rheight);

        return 1 + max(lheight, rheight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        help(root, ans);
        return ans;
    }


};
