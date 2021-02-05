// Should perfectly detach "exactly same tree equivalence".
// That is, the code structure should be one main for looping all elements in tree s.
// Plus one utility function for checking exactly same tree or not.
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(s==nullptr || t==nullptr) return false;
        if(solver(s, t)) return true;
        else
        {
            return isSubtree(s->left, t) || isSubtree(s->right, t); // be careful
        }
    }
    bool solver(TreeNode* s, TreeNode* t){
        if(!s && !t) return true;
        if(s==nullptr || t==nullptr) return false;
        if(s->val == t->val){
            return solver(s->left, t->left) && solver(s->right, t->right);
        }
        else
        {
            return false;
        }
    }
};
