// No need to do trivial swapping or checking childs from parent...etc.
// Recursive, logical consequences
// Under the constraint: all unique node values, the time complexity is O(n), since only 2 conditions
// can go all the way to leaf nodes, resulting in O(2 ^ depth), and depth is log(n)
// Without this constraint, it will be O(n^2), since all 4 recursions may go to leaf, resulting O(4 ^ depth)
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // if(!root1 && !root2) return true;
        // if(!root1 || !root2) return false;
        // above two conditions are equivalent to below one line:
        if(root1==nullptr || root2==nullptr) return root1==root2;
        if(root1->val != root2->val) return false;
        bool res = (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) \
                || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
        return res;
    }
};
