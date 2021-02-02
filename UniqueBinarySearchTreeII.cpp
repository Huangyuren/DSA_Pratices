// Recursive thinking, solver function designed to return a vector of TreeNode*
// Then we can iterate through this vector to achieve a series of different trees
// Special logical thinking.

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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return solver(1, n);
    }
    vector<TreeNode*> solver(int left, int right){
        vector<TreeNode*> res;
        if(left > right) {
            res.push_back(nullptr);
            return res;
        }
        for(int i=left; i<=right; i++){
            vector<TreeNode*> leftsub = solver(left, i-1);
            vector<TreeNode*> rightsub = solver(i+1, right);
            for(auto& x : leftsub){
                for(auto& y : rightsub){
                    TreeNode* curoot = new TreeNode(i);
                    curoot->left = x;
                    curoot->right = y;
                    res.push_back(curoot);
                }
            }
        }
        return res;
    }
};
