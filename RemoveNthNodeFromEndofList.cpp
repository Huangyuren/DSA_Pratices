// Clever solution, using faster pointer that is ahead of normal
// pointer n nodes
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fastptr = head;
        ListNode* slowptr = head;
        for(int i=0; i<n; i++){
            fastptr = fastptr->next;
        }
        if(fastptr == nullptr) return head->next; // Some edge case
        while(fastptr->next){
            fastptr = fastptr->next;
            slowptr = slowptr->next;
        }
        slowptr->next = slowptr->next->next;
        return head;
    }
};
