// Here we will split BT into left & right subtree in each iteration
// So we have to define both subtrees' left & right indexes of both preorder & inorder
// The result is generating 8 new indexes!
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;
        int n = preorder.size();
        return solver(preorder, inorder, 0, n-1, 0, n-1); // we should give left & right indication to both orders
    }
    TreeNode* solver(vector<int>& preorder, vector<int>& inorder, int prel, int prer, int inl, int inr) {
        if(prel > prer || inl > inr) return nullptr;
        //Finding root index in inordering
        int rootidx = 0;
        for(int i=inl; i<=inr; i++){
            if(inorder[i] == preorder[prel]){
                rootidx = i;
                break;
            }
        }
        //left subtree, preorder & inorder next index
        int leftprel = prel+1;
        int leftprer = prel + (rootidx - inl); // rootidx - inl == how many elements in left subtree
        int leftinl = inl;
        int leftinr = rootidx-1;
        
        //right subtree, preorder & inorder next index
        int rightprel = prel + (rootidx - inl) + 1;
        int rightprer = prer;
        int rightinl = rootidx + 1;
        int rightinr = inr;
        
        TreeNode* curr_root = new TreeNode(inorder[rootidx]);
        curr_root->left = solver(preorder, inorder, leftprel, leftprer, leftinl, leftinr);
        curr_root->right = solver(preorder, inorder, rightprel, rightprer, rightinl, rightinr);
        return curr_root;
    }
};
