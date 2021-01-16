/*
   Using one stack to track all indexes whose elements are less than current
   accessing vector element. Since stack can record closest indexes, great idea!
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
