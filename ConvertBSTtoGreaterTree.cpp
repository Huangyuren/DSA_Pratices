// Accumulate all right subtree element's val in current root node.
// Sweep from right to left is the solution.
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
    TreeNode* convertBST(TreeNode* root) {
        accumulate_sum = 0;
        solver(root);
        return root;
    }
    void solver(TreeNode* root){
        if(root==nullptr) return;
        solver(root->right);
        accumulate_sum += root->val;
        root->val = accumulate_sum; // Refresh current node's val.
        solver(root->left);
        return;
    }
private:
    int accumulate_sum;
};
