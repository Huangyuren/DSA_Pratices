#include <bits/stdc++.h>
#include <listNode.h>
#include <iterativeMergeSort.h>
#include <minHeapMergeSort.h>
// #include <cstdlib>
// #include <ctime>
// #include <algorithm>
using namespace std;

void printVec(ListNode* input){
    ListNode* track = input;
    while(track != nullptr){
       printf("%d, ", track->val);
       track = track->next;
    }
    printf("\n");
}
vector<ListNode*> demo(){
    vector<ListNode*> inputvec;
    vector<vector<int>> numericVec(3, vector<int>(10, 0));
    ListNode* lst1 = new ListNode(0);
    ListNode* lst2 = new ListNode(0);
    ListNode* lst3 = new ListNode(0);
    ListNode* h1 = lst1;
    ListNode* h2 = lst2;
    ListNode* h3 = lst3;
    
    srand(time(nullptr));
    for(int i=0; i<10; ++i){
        for(int j=0; j<3; ++j){
            numericVec[j][i] = rand()%300;
        }
    }
    for(int i=0; i<3; ++i){
        sort(numericVec[i].begin(), numericVec[i].end());
    }
    for(int i=0; i<10; ++i){
        lst1->next = new ListNode(numericVec[0][i]);
        lst2->next = new ListNode(numericVec[1][i]);
        lst3->next = new ListNode(numericVec[2][i]);
        lst1 = lst1->next;
        lst2 = lst2->next;
        lst3 = lst3->next;
    }
    inputvec.push_back(h1->next);
    inputvec.push_back(h2->next);
    inputvec.push_back(h3->next);
    printf("\nBelow are three lists that are to be sorted into single sorted list:\n");
    printVec(h1->next);
    printVec(h2->next);
    printVec(h3->next);
    return inputvec;
}
int main(int argc, char* argv[]){
    IterMergeSolution iter;
    MinHeapMergeSolution minh;
    vector<ListNode*> inputvecDemo1 = demo();
    vector<ListNode*> inputvecDemo2 = demo();
    ListNode* demo_iter = iter.mergeKLists(inputvecDemo1);
    printf("\n**First, sorted result using iterative sorting method.\n");
    printVec(demo_iter);
    printf("\n**Second, it is minheap solution\n");
    ListNode* demo_minh = minh.mergeKLists(inputvecDemo2);
    printVec(demo_iter);
}
