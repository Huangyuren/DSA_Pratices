#include <bits/stdc++.h>
#include <listNode.h>
#define pi pair<int,ListNode*>
#ifndef _MINHEAPMERGESORT_H_ 
#define _MINHEAPMERGESORT_H_

using namespace std;

/* struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };  */

class MinHeapMergeSolution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& A) {
            priority_queue<pi, vector<pi>, greater<pi>> pq;
            ListNode dummy(INT_MIN);
            ListNode* trace = new ListNode();
            trace = &dummy;
            for(auto x : A) {
                if(x != nullptr) pq.push({x->val, x});
                // if(x) pq.push(make_pair(x->val, x));
            }
            while(pq.size()) {
                auto x = pq.top().second;
                pq.pop();
                trace->next = x;
                trace = trace->next;
                if(x->next != nullptr) pq.push({x->next->val, x->next});
            }
            return dummy.next;
        }
};
#endif
/* int main(int argc, char* argv[]) {
 *     MinHeapMergeSolution varSol;
 *     vector<ListNode*> inputvec;
 *     ListNode* lst1 = new ListNode(0);
 *     ListNode* lst2 = new ListNode(10);
 *     ListNode* lst3 = new ListNode(20);
 *     ListNode* h1 = lst1;
 *     ListNode* h2 = lst2;
 *     ListNode* h3 = lst3;
 *     
 *     for(int i=1; i<10; ++i){
 *         lst1->next = new ListNode(i);
 *         lst2->next = new ListNode(i+10);
 *         lst3->next = new ListNode(i+20);
 *         lst1 = lst1->next;
 *         lst2 = lst2->next;
 *         lst3 = lst3->next;
 *     }
 *     inputvec.push_back(h1);
 *     inputvec.push_back(h2);
 *     inputvec.push_back(h3);
 *     ListNode* demo = varSol.mergeKLists(inputvec);
 *     while(demo != nullptr){
 *        printf("%d, ", demo->val);
 *        demo = demo->next;
 *     }
 *     printf("\n");
 * } */


