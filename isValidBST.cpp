class Solution {
public:
    bool validBSTUtil(TreeNode* root, TreeNode* left, TreeNode* right) {
        if (root == nullptr) return true;
        if (left !=nullptr && left->val >= root->val) return false;
        if (right != nullptr && right->val <= root->val) return false;
        return validBSTUtil(root->left, left, root) && validBSTUtil(root->right, root, right);
    }
    bool isValidBST(TreeNode* root) {
        return validBSTUtil(root, nullptr, nullptr);
    }
};
