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
    ListNode* merge2Sort(ListNode* input1, ListNode* input2) {
        ListNode* head = new ListNode();
        ListNode* ret = head;   
        while(input1 != nullptr && input2 != nullptr) {
            if(input1->val < input2->val) {
                head->next = input1;
                input1 = input1->next;
            }else{
                head->next = input2;
                input2 = input2->next;
            }
            head = head->next;
        }
        if(input1 != nullptr) {
            head->next = input1;
        }
        if(input2 != nullptr) {
            head->next = input2;
        }
        return ret->next;
    }
    ListNode* mergeKSort(vector<ListNode*>& input, int up, int down) {
        if(down - up == 0) {
            return input[up];
        }
        if(down - up == 1) {
            return merge2Sort(input[up], input[down]);
        }
        ListNode* tmp1 = mergeKSort(input, up, up+(down-up)/2);
        ListNode* tmp2 = mergeKSort(input, up+(down-up)/2+1, down);
        return merge2Sort(tmp1, tmp2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return {};
        return mergeKSort(lists, 0, lists.size()-1);
    }
};
