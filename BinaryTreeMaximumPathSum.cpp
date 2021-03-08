// Similar concepts with tree diameter, but should beware to compare leftres with 0
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
    int maxPathSum(TreeNode* root) {
        int currmax = INT_MIN;
        solver(root, currmax);
        return currmax;
    }
    int solver(TreeNode* root, int& currmax){
        if(root == nullptr) return 0;
        int leftres = max(solver(root->left, currmax), 0); // Compare with zero to avoid negative elements
        int rightres = max(solver(root->right, currmax), 0); // Compare with zero to avoid negative elements
        currmax = max(currmax, root->val+leftres+rightres);
        return root->val + max(leftres, rightres);
    }
};
