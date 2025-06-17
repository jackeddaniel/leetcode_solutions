#include <iostream>
#include <vector>
#include <stack>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr),right(nullptr) {}
};

void inorderRecursive(TreeNode* root) {
    
    if(root == nullptr) return;

    inorderRecursive(root->left);
    //some func
    inorderRecursive(root->right);
}

void inorderIterative(TreeNode* root) {
    std::stack<TreeNode*> s;
    TreeNode* current = root;

    while(current != nullptr || !s.empty()) {

        while(current != nullptr) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();

        //func on current->val

        current = current->right;
    }
}

void preorderRecursive(TreeNode* root) {
    if(root == nullptr) return;

    //func root->val
    
    preOrder(root->left);
    preOrder(root->right);
}

void preorderIterative(TreeNode* root) {
    
    if(root == nullptr) {
        return;
    }
    std::stack<TreeNode*> s;

    while(!s.empty()) {
        TreeNode* current = s.top();
        s.pop();

        //func on current->val

        if(current->right != nullptr) {
            s.push(current->right);
        }
        if(current->left != nullptr) {
            s.push(current->left);
        }
    }
}

void postorderRecursive(TreeNode* root) {
    
    if(root == nullptr) return;

    postorderRecursive(root->left);
    postorderRecursive(root->right);

    //func on root->val
}

void postorderIterative(TreeNode* root) {

    if(root == nullptr) {
        return;
    }

    std::stack<TreeNode*> a;
    std::stack<TreeNode*> b;

    while(!a.empty()) {
        TreeNode* current = a.top();
        a.pop();
        b.push(current);

        if(current->left != nullptr) {
            a.push(current->left);
        }
        if(current->right != nullptr) {
            a.push(current->right);
        }

    }

    while(!b.empty()) {
        //b.top()->val;

        b.pop();
    }
}


void levelOrder(TreeNode* root) {
    if(root == nullptr) {
        return;
    }

    std::queue<TreeNode*>  q;
    q.push(root);

    while(!q.empty()) {

        TreeNode* current = q.front();

        q.pop();
        //func curr->val
        if(current->left != nullptr) {
            q.push(current->left);
        }
        if(current->right != nullptr) {
            q.push(current->right);
        }

    }
}








