// Simply use serialization to check whether current subtree exists or not
// Indeed, the string serialization order is preorder, but actually it is postorder
// Because we will firstly push left subtree, then right subtree
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        postordertraversal(root, res);
        return res;
    }
    string postordertraversal(TreeNode* root, vector<TreeNode*>& res){
        if(root == nullptr) return "#";
        string currstr = to_string(root->val)+","+postordertraversal(root->left, res)+","+postordertraversal(root->right, res);
        if(mymap[currstr] == 1){
            res.push_back(root);
        }
        mymap[currstr] += 1;
        return currstr;
    }
private:
    unordered_map<string, int> mymap;
};
