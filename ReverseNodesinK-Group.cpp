// Really tricky to imagine this pattern
// Recursive solution
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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* dummy = head;
        while(count < k){
            if(dummy == nullptr) return head;
            dummy = dummy->next;
            count++;
        }
        ListNode* prev = reverseKGroup(dummy, k); // Next batch of k groups
        while(count > 0){
            ListNode* nextnode = head->next;
            head->next = prev;
            prev = head;
            head = nextnode;
            count--;
        }
        return prev;
    }
};
