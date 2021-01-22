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
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> mymap;
        int counter=0;
        mymap[0] = 1;
        solver(root, 0, counter, sum, mymap);
        return counter;
    }
    // unordered_map for storing all possible "path sum fragments"
    // Then recursively traverse all subtrees.
    void solver(TreeNode* root, int currsum, int& counter, int target, unordered_map<int, int>& mymap){
        if(root == nullptr) return;
        currsum += root->val;
        if(mymap.find(currsum - target) != mymap.end()){
            counter += mymap[currsum - target];
        }
        mymap[currsum] += 1;
        solver(root->left, currsum, counter, target, mymap);
        solver(root->right, currsum, counter, target, mymap);
        mymap[currsum] -= 1;
    }
};
