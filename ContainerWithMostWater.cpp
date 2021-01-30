class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n==0) return 0;
        int res=0;
        int i=0, j=n-1;
        while(i < j){
            res = max(res, (j-i)*min(height[i], height[j]));
            // Idea: we can only keep higher point!
            // Since in every iteration, water width will decrease by 1,
            // there is no way dropping higher height.
            if(height[i] < height[j]){
                i++;
            }
            else
            {
                j--;
            }
        }
        return res;
    }
};
