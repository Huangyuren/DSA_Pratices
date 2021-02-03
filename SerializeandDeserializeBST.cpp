// Simply use preorder to store BST, since preorder + BST can decide the only tree.
// Using memcpy to explicitly copy contents of both elements
// Should bear in mind that each char is one byte long, and generally int = 4 bytes
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        encode(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        return decode(data, start, INT_MIN, INT_MAX);
    }
    void encode(TreeNode* root, string& res){
        if(root==nullptr) return;
        char buf[4];
        memcpy(buf, &root->val, sizeof(int));
        for(int i=0; i<4; i++) res.push_back(buf[i]);
        encode(root->left, res);
        encode(root->right, res);
        return;
    }
    TreeNode* decode(string& data, int& pos, int low, int high){
        if(pos >= data.size()) return nullptr;
        int currval;
        memcpy(&currval, &data[pos], sizeof(int));
        if(currval < high && currval > low){
            TreeNode* curr = new TreeNode(currval);
            pos += sizeof(int);
            curr->left = decode(data, pos, low, currval);
            curr->right = decode(data, pos, currval, high);
            return curr;
        }
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
