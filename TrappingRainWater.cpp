// Lower part in each iteration would be the current water level
// We can record this current level, so all steps that are lower
// than this level will accumulate water!
// Very smart solution
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int level = 0, lower = 0, res = 0;
        while(left < right){
            if(height[left] < height[right]){
                lower = height[left];
                left++;
            }
            else
            {
                lower = height[right];
                right--;
            }
            if(lower > level) level = lower;
            res += level - lower; // res will only addup depths that are lower than current level
        }
        return res;
    }
};
