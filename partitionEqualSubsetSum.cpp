class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 == 1) return false;
        int target = sum/2;
        return dpKnapSack(nums, target);
    }
    void printvec(vector<vector<bool>>& input){
        for(int i=0; i<input.size(); i++){
            for(int j=0; j<input[i].size(); j++){
                if(input[i][j])
                    printf("T, ");
                else
                    printf("F, ");
            }
            printf("\n");
        }
    }
    bool dpKnapSack(vector<int>& nums, int target){
        vector<vector<bool>> dp_arr(nums.size()+1, vector<bool>(target+1));
        dp_arr[0][0] = true;
        for(int i=1; i<target+1; i++){
            dp_arr[0][i] = false;
        }
        for(int i=1; i<dp_arr.size(); i++){
            dp_arr[i][0] = false;
            for(int j=1; j <= target; j++){
                if(nums[i-1] <= j){
                    dp_arr[i][j] = (dp_arr[i-1][j-nums[i-1]] || dp_arr[i-1][j]);
                }
                else{
                    dp_arr[i][j] = dp_arr[i-1][j];
                }
            }
        }
        return dp_arr[dp_arr.size()-1][target];
    }
};
