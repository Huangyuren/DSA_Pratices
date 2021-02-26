class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // nth_element C++ STL partial sorting method, beware of nums.begin() + k-1 and greater
        // nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        // return nums[k-1];
        //
        //Or
        //
        // partial_sort C++ STL partial sorting method, beware of nums.begin() + k and greater
        // partial_sort(nums.begin(), nums.begin()+k, nums.end(), greater<int>());
        // return nums[k-1];
        //
        //Or
        //
        // Self implemented partition based (quicksort) partial sorting, very slow
        int left = 0, right = nums.size()-1;
        while(true){
            int mid = partition(nums, left, right);
            if(mid == k-1) return nums[mid];
            else if(mid < k){
                left = mid + 1;
            }
            else
            {
                right = mid-1;
            }
        }
        return 0; // no meaning
    }
private:
    int partition(vector<int>& nums, int left, int right){
        // Here, we want to build a descending sequence
        // int pivot = nums[left], l = left+1, r = right;
        // while(l <= r){
        //     if(nums[l] < pivot && nums[r] > pivot){
        //         swap(nums[l], nums[r]);
        //         l++; r--;
        //     }
        //     if(nums[l] >= pivot){
        //         l++;
        //     }
        //     if(nums[r] <= pivot){
        //         r--;
        //     }
        // }
        // swap(nums[left], nums[r]); // since nums[r] will > pivot
        // return r;
        int pivot = nums[right], j = left-1;
        for(int i=left; i<right; i++){
            if(nums[i] > pivot){
                j++;
                swap(nums[j], nums[i]);
            }
        }
        j++; // Since previous j, nums[j] is swapped, the condition says that it is nums[i] > pivot
        swap(nums[j], nums[right]);
        return j;
    }
};
