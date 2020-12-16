/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        /*
         * Consider using O(1) extra space, we should make use of two pointers.
         * cur will point to one level above of current level.
         * headptr points to current level's first element.
         * */
        if(root == nullptr) return root;
        Node* cur = root;
        Node* headptr = root->left;
        while(headptr){
            while(cur){
                cur->left->next = cur->right;
                if(cur->next){
                    cur->right->next = cur->next->left;
                }
                else{
                    cur->right->next = nullptr;
                }
                cur = cur->next;
            }
            cur = headptr;
            headptr = headptr->left;
        }
        return root;
    }
};
