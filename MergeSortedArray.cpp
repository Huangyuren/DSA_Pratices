// A little bit tricky, but very efficient
// Start from back and gradually coming to front, because nums1 has already reserved room for nums2
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, currptr = nums1.size()-1;
        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j]){
                nums1[currptr] = nums1[i];
                i--;
            }else{
                nums1[currptr] = nums2[j];
                j--;
            }
            currptr--;
        }
        return;
    }
};
