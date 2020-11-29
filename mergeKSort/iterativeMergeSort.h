#include <bits/stdc++.h>
#include <listNode.h>
// #ifndef _ITERATIVEMERGESORT_H_
// #define _ITERATIVEMERGESORT_H_ 
#pragma once
using namespace std;

/* struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * }; */

class IterMergeSolution {
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

// #endif
/* int main(int argc, char* argv[]) {
 *     IterMergeSolution varSol;
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


