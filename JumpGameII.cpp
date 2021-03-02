// Implicit BFS structure
// 2 approaches, same concept but different implementations
class Solution {
public:
    int jump(vector<int>& nums) {
        // We can comprehend this solution: currendgoal is per-stride goal, so once reach, res should + 1
        // The stop condition would remain i == size-1
        int farthest = 0, currend = 0, res = 0;
        for(int i=0; i<nums.size(); i++){
            farthest = max(farthest, i+nums[i]);
            if(i == nums.size()-1) return res; // Should return res as soon as possible to prevent possibility of res++
            if(i == currend){
                res++;
                currend = farthest; // current queue size
            }
        }
        return res;
        //
        //or less experssive solution
        //
        // int res = 0, currstart = 0, currend = 0, currfarthest = 0, n = nums.size();
        // while(currend < n-1){ // since reaching nums[n-1] is deemed successful
        //     res++;
        //     currfarthest = currend + 1;
        //     for(int i=currstart; i<=currend; i++){
        //         if(i + nums[i] >= n-1) return res;
        //         currfarthest = max(currfarthest, i+nums[i]);
        //     }
        //     currstart = currend+1; // at least start from last end + 1
        //     currend = currfarthest;
        // }
        // return res;
    }
};
