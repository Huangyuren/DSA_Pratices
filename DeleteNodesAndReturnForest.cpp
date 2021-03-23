// We will add a node into result vector only when this node is a root & is not deleted
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> myset(to_delete.begin(), to_delete.end());
        solver(root, myset, res, true);
        return res;
    }
    // Should update root's left & right child also!
    TreeNode* solver(TreeNode* root, unordered_set<int>& myset, vector<TreeNode*>& res, bool isroot){
        if(!root) return nullptr;
        bool deleteornot = myset.find(root->val) == myset.end() ? false : true;
        if(isroot && deleteornot == false){
            // if this is root && this is not gonna be deleted, then push_back as res
            res.push_back(root);
        }
        root->left = solver(root->left, myset, res, deleteornot); // if currently no deletion, then next node will not be root as well
        root->right = solver(root->right, myset, res, deleteornot); // same above
        return deleteornot ? nullptr : root;
    }
};
