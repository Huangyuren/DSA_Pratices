// Can be done by either count from postorder's front or by postorder's end
// Should be careful of indexing issues
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty()) return nullptr;
        int n = inorder.size();
        return solver(inorder, postorder, 0, n-1, 0, n-1);
    }
    TreeNode* solver(vector<int>& inorder, vector<int>& postorder, int postl, int postr, int inl, int inr){
        if(postl > postr || inl > inr) return nullptr;
        int root_idx = 0;
        for(int i=inl; i<=inr; i++){
            if(inorder[i] == postorder[postr]){
                root_idx = i;
                break;
            }
        }
        //Left subtree
        int leftpostl = postl;
        int leftpostr = postl + (root_idx-inl)-1; // Should minus 1, since we count from front, which doesn't contain root
        int leftinl = inl;
        int leftinr = root_idx-1;
        //Right subtree
        int rightpostl = leftpostr + 1;
        int rightpostr = postr-1;
        int rightinl = root_idx + 1;
        int rightinr = inr;
        TreeNode* curr_root = new TreeNode(inorder[root_idx]);
        curr_root->left = solver(inorder, postorder, leftpostl, leftpostr, leftinl, leftinr);
        curr_root->right = solver(inorder, postorder, rightpostl, rightpostr, rightinl, rightinr);
        return curr_root;
    }
};
