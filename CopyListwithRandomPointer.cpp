/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* dummy = head;
        // append extra duplicated node right after original node.
        while(dummy){
            Node* backup = dummy->next;
            Node* tmp = new Node(dummy->val);
            dummy->next = tmp;
            tmp->next = backup;
            dummy = dummy->next->next;
        }
        // processing random pointer
        dummy = head;
        while(dummy){
            if(dummy->random){
                dummy->next->random = dummy->random->next;
            }
            dummy = dummy->next->next;
        }
        // restore original list & crop out our answer
        dummy = head;
        Node* dummyhead = new Node(0);
        Node* res = dummyhead;
        while(dummy){
            dummyhead->next = dummy->next;
            dummy->next = dummy->next->next;
            dummyhead = dummyhead->next;
            dummy = dummy->next;
        }
        return res->next;
    }
};
