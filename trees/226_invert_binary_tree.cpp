class Solution {
    public:


        TreeNode* invertTree(TreeNode* root) {
            if(root == nullptr) return;

            TreeNode* inv_left = invertTree(root->left);
            TreeNode* inv_right = invertTree(root->right);

            root->left = inv_right;
            root->right = inv_left;
            
            
            return root;
        }
};
