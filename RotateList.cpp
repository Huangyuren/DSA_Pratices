// Not a good problem
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        ListNode* dummy = head;
        ListNode* dummyhead = nullptr;
        int len = 1; // special number, designed for later for loop
        while(dummy->next){
            len++;
            dummy = dummy->next;
        }
        // dummy will eventually stop at last element of list.
        dummy->next = head; // Linked as circular linked list
        if(k % len){
            k = k%len;
            for(int i=0; i<len-k; i++){
                dummy = dummy->next;
            }
            dummyhead = dummy->next;
            dummy->next = nullptr; // break down circular linked list
            return dummyhead;
        }
        dummy->next = nullptr; // restore back singlely linked list
        return head;
    }
};
