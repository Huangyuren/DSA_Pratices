// Actually this is a graph problem. Firstly we convert this BT into our familiar graph,
// by one-pass scanning whole tree and grouping neighboring nodes in findconnection function.
// Second, apply DFS to this graph and get answer.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root==nullptr || target==nullptr) return {};
        findconnection(root, nullptr);
        solver(target, K);
        return res;
    }
    void findconnection(TreeNode* currnode, TreeNode* prevnode){
        if(currnode==nullptr) return;
        if(prevnode){
            mymap[currnode].insert(prevnode);
            mymap[prevnode].insert(currnode);
        }
        findconnection(currnode->left, currnode);
        findconnection(currnode->right, currnode);
        return;
    }
    void solver(TreeNode* target, int k){
        if(visited.count(target)) return;
        visited.insert(target);
        if(k==0){
            res.push_back(target->val);
            return;
        }
        for(auto x : mymap[target]){
            solver(x, k-1);
        }
        return;
    }
private:
    unordered_map<TreeNode*, unordered_set<TreeNode*>> mymap;
    unordered_set<TreeNode*> visited;
    vector<int> res;
};
