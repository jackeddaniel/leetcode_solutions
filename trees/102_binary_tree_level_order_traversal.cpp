class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res;
            
            if(root == nullptr) return res;
            TreeNode* curr = nullptr;
            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()) {
                int size = q.size();
                
                vector<int> ins;

                for(int i = 0; i < size; i++) {
                    curr = q.front();
                    q.pop();

                    ins.push_back(curr->val);

                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                res.push_back(ins);
            }
            return res;
        }
};

                    
                
