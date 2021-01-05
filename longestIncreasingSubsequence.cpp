class Solution {
public:
    /*
     * [Important] this method can't be used when there are allowed for 
     * repeated elements in nums, since up/left backtracking can produce
     * different results. However, when filling backtrack_arr, we can only
     * choose either 2(left) or 3(up) given that nums[j-1] != sortednums[i-1]
     * 1: left up
     * 2: left
     * 3: up
    */
    unordered_map<int, int> mymap;
    unordered_map<int, int>::const_iterator got;
    vector<int> result_seq;
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sortednums(nums);
        sort(sortednums.begin(), sortednums.end());
        int dimen = nums.size()+1;
        vector<vector<int>> arr(dimen, vector<int>(dimen));
        vector<vector<int>> backtrack_arr(dimen, vector<int>(dimen));        
        for(int i=0; i<dimen; i++){
            arr[0][i] = 0;
            backtrack_arr[0][i] = 0;
        }
        for(int i=1; i<dimen; i++){
            arr[i][0] = 0;
            backtrack_arr[i][0] = 0;
            for(int j=1; j<dimen; j++){
                if(sortednums[i-1] == nums[j-1]){
                    arr[i][j] = arr[i-1][j-1] + 1;
                    backtrack_arr[i][j] = 1;
                }
                else if(arr[i-1][j] < arr[i][j-1]){
                    arr[i][j] = arr[i][j-1];
                    backtrack_arr[i][j] = 2;
                }
                else{
                    arr[i][j] = arr[i-1][j];
                    backtrack_arr[i][j] = 3;
                }
            }
        }
        printvec(backtrack_arr);
        backTrack(backtrack_arr, nums, sortednums);
        return mymap.size();
    }
    void backTrack(const vector<vector<int>>& backtrack_arr, const vector<int>& nums, const vector<int>& sortednums){
        int cur_row = backtrack_arr.size()-1;
        int cur_col = backtrack_arr.size()-1;
        while(cur_row != 0 && cur_col != 0){
            if(sortednums[cur_row-1] == nums[cur_col-1]){
                got = mymap.find(sortednums[cur_row-1]);
                if(got == mymap.end()){
                    mymap.insert({sortednums[cur_row-1], cur_row-1});
                }
                result_seq.push_back(sortednums[cur_row-1]);
                cur_row--;
                cur_col--;
            }
            else if(backtrack_arr[cur_row][cur_col] == 2){
                cur_col--;
            }
            else{
                cur_row--;
            }
        }
    }
    void printvec(vector<vector<int>>& input){
        for(int i=0; i<input.size(); i++){
            for(int j=0; j<input[i].size(); j++){
                printf("%d, ", input[i][j]);
            }
            printf("\n");
        }
    }
};
