// How to let space be O(1)?
// Using two-pass checking, first pass for finding max value of occurance 
// and how many elements satisfies this occurance.(i.e., mode.size())
// Second pass eventually filling elements into this mode vecotr.
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
    bool firstround;
    int currcount;
    int maxcount;
    TreeNode* prev = nullptr;
    TreeNode* dummy = nullptr;
    vector<int> res;
    
    vector<int> findMode(TreeNode* root) {
        firstround = true;
        dummy = root;
        currcount = maxcount = 0;
        inorder(dummy);
        firstround = false;
        dummy = root;
        currcount = 0; // Remember to set back currcount to zero.
        inorder(dummy);
        return res;
    }
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        inorder(root->left);
        if(prev && prev->val != root->val){
            currcount = 1;
        }
        else
        {
            currcount++;
        }
        if(firstround){
            maxcount = max(maxcount, currcount);
        }
        else
        {
            if(currcount == maxcount){
                res.push_back(root->val);
            }
        }
        prev = root;
        inorder(root->right);
        return;
    }
};
