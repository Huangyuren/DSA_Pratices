// char Toggling plus can solve this.
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        stack<int> mystack;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                mystack.push(i);
            }
            else if(s[i] == ')'){
                if(mystack.empty()){
                    s[i] = '*';
                }
                else
                {
                    mystack.pop();
                }
            }
        }
        while(mystack.size()){
            int curridx = mystack.top();
            s[curridx] = '*';
            mystack.pop();
        }
        int currcounter = 0;
        int res = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                res = max(res, currcounter);
                currcounter = 0;
            }
            else
            {
                currcounter++;
            }
        }
        res = max(res, currcounter);
        return res;
    }
};
