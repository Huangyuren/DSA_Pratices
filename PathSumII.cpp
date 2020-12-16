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
    void printUtil(vector<int>& vec){
        for(int i=0; i<vec.size(); ++i){
            printf("%d, ", vec[i]);
        }
    }
    void findPath(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res){
        /*
         * Actually, first if statement is for leaf position, leaf node will not enter other if stats.
         * Suppose we are not at leaf node, we will try both last two if statements.
         * path.pop_back() is for back-track, once this path reaches the end and we still not get desired sum.
         * */
        if(root == nullptr) return;
        path.push_back(root->val);
        if(root->val == sum && root->right==nullptr && root->left==nullptr) {
            res.push_back(path);
        }
        if(root->right){
            findPath(root->right, sum - root->val, path, res);
        }
        if(root->left){
            findPath(root->left, sum-root->val, path, res);
        }
        path.pop_back();  //pop back to backtrack another potential answer.
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return{};
        vector<vector<int>> res;
        vector<int> path;
        findPath(root, sum, path, res);
        return res;
    }
};
