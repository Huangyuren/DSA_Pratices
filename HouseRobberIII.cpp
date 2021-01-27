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
    int rob(TreeNode* root) {
        if(root==nullptr) return 0;
        int left=0, right=0;
        return solver(root, left, right);
    }
    int solver(TreeNode* root, int& left, int& right){
        /*
        * In each selection, we only need to consider rob
        * current + grandchilds
        *       or
        * childs
        * and should be conscious that siblings can be robbed at same time
        */
        if(root==nullptr) return 0;
        // grandchildren
        int ll=0, lr=0;
        int rl=0, rr=0;
        // setting for children and also grandchildren
        left = solver(root->left, ll, lr);
        right = solver(root->right, rl, rr);
        return max(root->val + ll + lr + rl +rr, left + right);// sibling can be robbed simultaneously.
    }
};
