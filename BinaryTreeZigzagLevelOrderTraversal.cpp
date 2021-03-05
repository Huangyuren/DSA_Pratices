// Using deque as to enable bi-directional poping & pushing
// Beware of direction
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        deque<TreeNode*> mydq;
        mydq.push_back(root);
        int direction = 1; // direction toggling
        while(mydq.size()){
            int currsize = mydq.size();
            direction ^= 1;
            vector<int> tmpvec;
            for(int i=0; i<currsize; i++){
                TreeNode* tmp = nullptr;
                if(direction == 1){ // pop_front, push_back, right then left
                    tmp = mydq.front(); mydq.pop_front();
                    if(tmp->right) mydq.push_back(tmp->right); // Should enter deque from another direction also
                    if(tmp->left) mydq.push_back(tmp->left);
                }
                else
                { // pop_back, push_front, left then right
                    tmp = mydq.back(); mydq.pop_back();
                    if(tmp->left) mydq.push_front(tmp->left); // Should enter deque from another direction also
                    if(tmp->right) mydq.push_front(tmp->right);
                }
                tmpvec.push_back(tmp->val);
            }
            res.push_back(tmpvec);
        }
        return res;
    }
};
