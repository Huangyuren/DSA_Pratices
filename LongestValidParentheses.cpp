// Simple stack solution that compute res on the fly, O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        stack<int> mystack;
        mystack.push(-1); // default value
        int n = s.size();
        int res = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '('){
                mystack.push(i);
            }else{
                mystack.pop();
                if(mystack.empty()){
                    mystack.push(i);
                }else{
                    res = max(res, i - mystack.top());
                }
            }
        }
        return res;
    }
};
