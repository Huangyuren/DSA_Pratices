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
#define mypair pair<int, ListNode*>
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        return merge2List(head, second);
    }
    
    ListNode* merge2List(ListNode* head1, ListNode* head2){
        priority_queue<mypair, vector<mypair>, greater<mypair>> pq;
        while(head1 != nullptr){
            pq.push(make_pair(head1->val, head1));
            head1 = head1->next;
        }
        while(head2 != nullptr){
            pq.push(make_pair(head2->val, head2));
            head2 = head2->next;
        }
        ListNode dummy(INT_MIN);
        ListNode* trace = new ListNode();
        trace = &dummy;
        while(pq.size()){
            auto x = pq.top().first;
            pq.pop();
            trace->next = new ListNode(x, nullptr);
            trace = trace->next;
        }
        return dummy.next;
    }
};
