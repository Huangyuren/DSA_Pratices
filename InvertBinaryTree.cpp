// We cannot simply do root->left = invertTree(root->right);
// Since in that way, root->left will be overrided and lost.
// We have to store these original information
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // if(root == nullptr) return nullptr;
        // TreeNode* tmpleft = root->left;
        // TreeNode* tmpright = root->right;
        // root->left = invertTree(tmpright);
        // root->right = invertTree(tmpleft);
        // return root;
        //
        // Or do it iteratively
        //
        if(root==nullptr) return nullptr;
        stack<TreeNode*> mystack;
        mystack.push(root);
        while(mystack.size()){
            TreeNode* curr = mystack.top(); mystack.pop();
            TreeNode* backupleft = curr->left;
            curr->left = curr->right;
            curr->right = backupleft;
            if(curr->left) mystack.push(curr->left);
            if(curr->right) mystack.push(curr->right);
        }
        return root;
    }
};
