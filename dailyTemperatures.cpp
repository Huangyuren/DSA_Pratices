/*
   Using stack to track all previous elements that are waiting
   a larger value showing up.
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        stack<int> mystack;
        for(int i=0; i<n; i++){
            while(mystack.size() && T[mystack.top()] < T[i]){
                ans[mystack.top()] = i - mystack.top();
                mystack.pop();
            }
            mystack.push(i);
        }
        return ans;
    }
};
