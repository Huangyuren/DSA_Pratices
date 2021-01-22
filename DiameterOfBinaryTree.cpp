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
// This problem aims at:
// 1. recording maximum distance of every node.
// 2. Then we pickup the max number of all these nodes.
// 3. return
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int glob_max = 0;
        solver(root, glob_max);
        return glob_max;
    }
    int solver(TreeNode* root, int& glob_max){
        if(root == nullptr) return 0;
        int left = solver(root->left, glob_max);
        int right = solver(root->right, glob_max);
        // Need to record global maximum of left subtree + right subtree.
        glob_max = max(glob_max, left + right);
        return 1 + max(left, right);
    }
};
