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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        
        ListNode* head1 = sortList(head);
        ListNode* head2 = sortList(second);
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* trace = dummy;
        while(head1 != nullptr && head2 != nullptr){
            if(head1->val < head2->val){
                trace->next = head1;
                trace = trace->next;
                head1 = head1->next;
            }
            else
            {
                trace->next = head2;
                trace = trace->next;
                head2 = head2->next;
            }
        }
        if(head1) trace->next = head1;
        if(head2) trace->next = head2;
        return dummy->next;
    }
    
};
