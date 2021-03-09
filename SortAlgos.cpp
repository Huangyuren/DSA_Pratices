#define mypair pair<int, ListNode*>
class sortingCluster{
public:
    // Here we have four different ways of sorting for practices
    void mergesort(vector<int>& nums){
        mergesortUtil(nums, 0, nums.size()-1);
    }
    void quicksort(vector<int>& nums){
        quicksortUtil(nums, 0, nums.size()-1);
    }
    void bubblesort(vector<int>& nums){
        int n = nums.size();
        for(int i=n-1; i>=0; i--){
            bool swapornot = false;
            for(int j=0; j<i; j++){
                if(nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]);
                    swapornot = true;
                }
            }
            if(!swapornot) return;
        }
        return;
    }
    ListNode* mergesort_list_pq(ListNode* head){
        if(head==nullptr) return;
        ListNode* slowptr = head;
        ListNode* fastptr = head->next;
        while(fastptr && fastptr->next){
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        ListNode* secondlist = slowptr->next;
        slowptr->next = nullptr;
        priority_queue<mypair, vector<mypair>, larger<mypair>> mypq;
        while(head){
            mypq.push({head->val, head});
            head = head->next;
        }
        while(secondlist){
            mypq.push({secondlist->val, secondlist});
            secondlist = secondlist->next;
        }
        ListNode* res = new ListNode(0);
        ListNode* dummy = res;
        while(mypq.size()){
            auto tmp = mypq.top();
            dummy->next = tmp.second;
            dummy = dummy->next;
        }
        return res->next;
    }
    void mergesort_list_recur(ListNode* head){
        if(head==nullptr) return;
        ListNode* slowptr = head;
        ListNode* fastptr = head->next;
        while(fastptr && fastptr->next){
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        ListNode* secondlist = slowptr->next;
        slowptr->next = nullptr;
        ListNode* head1 = mergesort_list_recur(head);
        ListNode* head2 = mergesort_list_recur(secondlist);
        ListNode* res = new ListNode(0);
        ListNode* dummy = res;
        while(head1 && head2){
            if(head1->val < head2->val){
                dummy->next = head1;
                head1 = head1->next;
            }else{
                dummy->next = head2;
                head2 = head2->next;
            }
            dummy = dummy->next;
        }
        return res->next;
    }
private:
    void quicksortUtil(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int mid = partition(nums, left, right);
        quicksortUtil(nums, left, mid);
        quicksortUtil(nums, mid+1, right);
        return;
    }
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[right];
        int j = left-1;
        for(int i=left; i<right; i++){
            if(nums[i] < pivot){
                j++;
                swap(nums[j], nums[i]);
            }
        }
        j++;
        swap(nums[j], nums[right]);
        return j;
    }
    void mergesortUtil(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int mid = (mid+right)/2;
        mergesortUtil(nums, left, mid);
        mergesortUtil(nums, mid+1, right);
        merge2(nums, left, mid, right);
        return;
    }
    void merge2(vector<int>& nums, int left, int mid, int right){
        vector<int> leftpart(nums.begin()+left, nums.begin()+mid+1); // inclusion: [)
        vector<int> rightpart(nums.begin()+mid+1, nums.begin()+right+1);
        int i=0, j=0, curr = left;
        while(i < leftpart.size() && j<rightpart.size()){
            if(leftpart[i] < rightpart[j]){
                nums[curr] = leftpart[i];
                i++; curr++;
            }
            else{
                nums[curr] = rightpart[j];
                j++; curr++;
            }
        }
        while(i<leftpart.size()){
            nums[curr] = leftpart[i];
            curr++; i++;
        }
        while(j<rightpart.size()){
            nums[curr] = rightpart[j];
            curr++; j++;
        }
        return;
    }
}
