// Naively searching for left and right index
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty()) return;
        int n = nums.size();
        int left = -1, right=0; // Left should be set as special -1 to detect necessity
        for(int i=n-1; i>=1; i--){
            if(nums[i-1] < nums[i]){
                left = i-1;
                break;
            }
        }
        if(left == -1){ // Original is descending
            reverse(nums.begin(), nums.end()); // Convert as ascending
            return;
        }
        for(int i=n-1; i>left; i--){
            if(nums[i] > nums[left]){
                right = i;
                break;
            }
        }
        swap(nums[left], nums[right]);
        reverse(nums.begin()+left+1, nums.end());
        return;
    }
};
