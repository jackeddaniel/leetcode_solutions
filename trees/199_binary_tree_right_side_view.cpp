class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            vector<int> res;
            
            if(root == nullptr) return res;
            
            queue<TreeNode*> q;
            q.push(root);

            while(!q.empty()) {

                //in this program we mainly need to output the last element in every level
                //so we keep track of the number of nodes at each level and push the rightmost
                int levelSize = q.size();

                for(int i = 0; i < levelSize; i++) {
                    TreeNode* curr = q.front(); 
                    q.pop();
                    if(i == levelSize-1) res.push_back(curr->val);

                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
            }
            return res;
        }
};
