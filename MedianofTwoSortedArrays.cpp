// YouTube link: https://www.youtube.com/watch?v=LPFhl65R7ww&t=1336s
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = m;
        while(low <= high){
            int partitionx = (low+high)/2;
            int partitiony = (m+n+1)/2 - partitionx;
            int maxleftx = (partitionx == 0) ? INT_MIN : nums1[partitionx-1];
            int minrightx = (partitionx == m) ? INT_MAX : nums1[partitionx];
            int maxlefty = (partitiony == 0) ? INT_MIN : nums2[partitiony-1];
            int minrighty = (partitiony == n) ? INT_MAX : nums2[partitiony];
            
            if(maxleftx <= minrighty && maxlefty <= minrightx){
                if((m+n)%2 == 0){
                    // Even
                    return (max(maxleftx, maxlefty) + min(minrightx, minrighty))/2.0;
                }
                else
                {
                    return max(maxleftx, maxlefty);
                }
            }
            else if(maxleftx > minrighty){
                high = partitionx - 1;
            }
            else
            {
                low = partitionx + 1;
            }
        }
        return -1;
    }
};
