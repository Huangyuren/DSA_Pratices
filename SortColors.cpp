class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return;
        // quicksort(nums, 0, n-1);
        // bubblesort(nums);
        mergesort(nums, 0, n-1);
        return;
    }
    void printvec(vector<int>& nums){
        for(int i=0; i<nums.size(); i++){
            printf("%d, ", nums[i]);
        }
        printf("\n");
    }
    void mergesort(vector<int>&nums, int start, int end){
        if(start >= end) return;
        int mid = (start+end) / 2;
        mergesort(nums, start, mid);
        mergesort(nums, mid+1, end);
        merge(nums, start, mid, end);
    }
    void merge(vector<int>&nums, int left, int mid, int right){
        // printf("Left: %d, mid: %d, right: %d\n", left, mid, right);
        // vector<int> vecleft(nums.begin()+left, nums.begin()+mid+1);
        // vector<int> vecright(nums.begin()+mid+1, nums.begin()+right+1);
        // Or using vector's constructor, remind: with this inclusion, [)
        vector<int> vecleft(mid-left+1);
        vector<int> vecright(right-mid);
        for(int i=left; i<=mid; i++){
            vecleft[i-left] = nums[i];
        }
        for(int i=mid+1; i<=right; i++){
            vecright[i-mid-1] = nums[i];
        }
        int i=0, j=0;
        int k = left;
        while(i<vecleft.size() && j<vecright.size()){
            if(vecleft[i] < vecright[j]){
                nums[k] = vecleft[i];
                i++;
            }
            else
            {
                nums[k] = vecright[j];
                j++;
            }
            k++;
        }
        if(i<vecleft.size()){
            for(int tmp=i; tmp<vecleft.size(); tmp++){
                nums[k] = vecleft[tmp];
                k++;
            }
        }
        if(j<vecright.size()){
            for(int tmp=j; tmp<vecright.size(); tmp++){
                nums[k] = vecright[tmp];
                k++;
            }
        }
        return;
    }
    
    void bubblesort(vector<int>& nums){
        bool swapornot=false;// true if swap occurred
        for(int i=nums.size()-1; i>=0; i--){ // bubble sort begins from back.
            swapornot = false;
            for(int j=0; j<=i; j++){
                if(j && nums[j] < nums[j-1]){
                    swap(nums[j], nums[j-1]);
                    swapornot = true;
                }
            }
            if(!swapornot) return;
        }
        return;
    }
    
    void quicksort(vector<int>& nums, int start, int end){
        if(start >= end) return;
        int mid = partition(nums, start, end);
        printf("mid: %d\n", mid);
        quicksort(nums, start, mid-1);
        quicksort(nums, mid+1, end);
        return;
    }
    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[end];
        int j=start-1;
        for(int i=start; i<end; i++){
            if(nums[i] < pivot){
                j++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[j+1], nums[end]);
        return j+1;
    }
};
