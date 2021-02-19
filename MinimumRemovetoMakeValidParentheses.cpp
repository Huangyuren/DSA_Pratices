// Actually, don't need to bother minimum, since passively removing
// redundant chars can achieve it.
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.empty()) return "";
        stack<int> mystack;
        string res = "";
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                mystack.push(i);
            }
            else if(s[i] == ')')
            {
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
            int tmp = mystack.top();
            s[tmp] = '*';
            mystack.pop();
        }
        for(int i=0; i<n; i++){
            if(s[i] != '*'){
                res += s[i];
            }
        }
        return res;
    }
};
