// Commented with new thinkings
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        vector<int> curr;
        solver(root, res, curr, targetSum);
        return res;
    }
    void solver(TreeNode* root, vector<vector<int>>& res, vector<int>& curr, int target){
        if(root==nullptr) return;
        curr.push_back(root->val); // no matter how, just push in.
        if(root->val == target && root->left == nullptr && root->right == nullptr){
            res.push_back(curr); // only when cumulated sum == target, will it be pushed into res.
            // Cannot return, since we still have to pop_back()
        }
        if(root->left) solver(root->left, res, curr, target - root->val);
        if(root->right) solver(root->right, res, curr, target - root->val);
        curr.pop_back();
        return;
    }
};
