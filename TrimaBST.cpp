// When facing problems requiring pointer modification, often the case that we should
// use a return value(pointer) to update current pointer!
// Here is how it works.

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return nullptr;
        return solver(root, low, high);
    }
    TreeNode* solver(TreeNode* root, int low, int high){
        if(root == nullptr) return nullptr;
        if(root->val < low){
            return solver(root->right, low, high); // Directly returning new pointer.
        }
        else if(root->val > high){
            return solver(root->left, low, high); // Directly returning new pointer.
        }
        else
        {
            root->left = solver(root->left, low, high);
            root->right = solver(root->right, low, high);
            return root;
        }
    }
};
