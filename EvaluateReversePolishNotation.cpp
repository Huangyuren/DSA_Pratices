class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> myst;
        int n = tokens.size();
        for(int i=0; i<n; i++){
            if(tokens[i].size() > 1 || isdigit(tokens[i][0])){
                // Take care of signed elements, and only need to look at [0]
                myst.push(stoi(tokens[i]));
            }
            else{
                int tmp1 = myst.top(); myst.pop();
                int tmp2 = myst.top(); myst.pop();
                if(tokens[i] == "+"){
                    myst.push(tmp2+tmp1);
                }else if(tokens[i] == "-"){
                    myst.push(tmp2-tmp1);
                }else if(tokens[i] == "*"){
                    myst.push(tmp2*tmp1);
                }else if(tokens[i] == "/"){
                    myst.push(tmp2/tmp1);
                }
            }
        }
        return myst.top();
    }
};
