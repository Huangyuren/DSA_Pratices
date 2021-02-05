// Besides fast & slow pointer for mid position,
// use head & tail plus == comparator is useful in utility function.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        return solver(head, nullptr);
    }
    TreeNode* solver(ListNode* head, ListNode* tail){
        if(head == tail) return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* tmproot = new TreeNode(slow->val);
        tmproot->left = solver(head, slow);
        tmproot->right = solver(slow->next, tail); // Need to be slow->next
        return tmproot;
    }
};
