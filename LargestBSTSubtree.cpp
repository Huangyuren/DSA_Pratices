// This problem approach is different from isvalidBST, while the former checks root val
// validity at the begining of recursion, by comparing from its parent value (top-down)
// This problem should firstly dig into the tree's leaf (bottom-up), and by comparing its left subtree's
// max value & its right subtree's min value to check validity, different.
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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        solver(root, res);
        return res;
    }
    vector<int> solver(TreeNode* root, int& res){
        if(root == nullptr) return {INT_MAX, INT_MIN, 0}; // minval, maxval, node count
        vector<int> leftpart = solver(root->left, res);
        vector<int> rightpart = solver(root->right, res);
        // check BST valid
        if(leftpart[2] == -1 || rightpart[2] == -1) return {INT_MAX, INT_MIN, -1}; // First we check its subtree
        int currcount = -1;
        if(root->val > leftpart[1] && root->val < rightpart[0]){ // compare left subtree max, right subtree min
            currcount = 1+leftpart[2]+rightpart[2];
            res = max(res, currcount);
        }
        return {min(root->val, leftpart[0]), max(root->val, rightpart[1]), currcount};
    }
};
