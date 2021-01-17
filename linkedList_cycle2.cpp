/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr) return nullptr;
        ListNode* fastptr = head->next;
        ListNode* slowptr = head;

        // Checking loop exists or not
        while(fastptr != slowptr){
            if(fastptr==nullptr || slowptr==nullptr || fastptr->next==nullptr){
                return nullptr;
            }
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
        }

        // Ok, loop existing, then check at which point will these two pointers meet.
        fastptr = fastptr->next;
        slowptr = head;
        while(fastptr != slowptr){
            fastptr = fastptr->next;
            slowptr = slowptr->next;
        }
        return fastptr;
    }
};
