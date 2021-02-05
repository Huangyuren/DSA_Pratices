// Getting mid val by simply (head + tail) / 2 in BST should work.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return nullptr;
        return solver(nums, 0, n-1);
    }
    TreeNode* solver(vector<int>& nums, int left, int right){
        if(left > right) return nullptr;
        int mid = (left+right)/2;
        TreeNode* tmproot = new TreeNode(nums[mid]);
        tmproot->left = solver(nums, left, mid-1);
        tmproot->right = solver(nums, mid+1, right);
        return tmproot;
    }
};
