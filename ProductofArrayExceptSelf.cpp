class Solution {
public:
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     // Solution using two vector
    //     int n = nums.size();
    //     vector<int> frombegin(n, 1);
    //     vector<int> fromend(n, 1);
    //     vector<int> res(n, 1);
    //     for(int i=1; i<n; i++){
    //         frombegin[i] = frombegin[i-1] * nums[i-1]; // nums[i-1] correspond to nums[0]
    //         fromend[i] = fromend[i-1] * nums[n-i]; // nums[n-i] correspond to nums[n-1]
    //         // but frombegin/end is behind i by 1
    //     }
    //     for(int i=0; i<n; i++){
    //         res[i] = frombegin[i] * fromend[n-i-1]; // will escape self
    //     }
    //     return res;
    // }
    // or using 2 variables, preferred thinking.
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        res[0] = 1;
        int frombegin = 1;
        int fromend = 1;
        for(int i=0; i<n; i++){
            res[i] *= frombegin;
            frombegin *= nums[i]; // Assign frombegin variable just before res[current front index]
            res[n-i-1] *= fromend;
            fromend *= nums[n-i-1]; // Assing fromend variable just before res[current last index]
        }
        return res;
    }
};
