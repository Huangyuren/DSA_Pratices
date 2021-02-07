class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        if(n==0) return {};
        vector<int> res(n, -1);
        int cpos = -n; // should be negative enough
        for(int i=0; i<n; i++){
            if(s[i]==c) {
                cpos = i;
            }
            res[i] = i - cpos;// may be zero or a large value.
        }
        for(int i=cpos - 1; i>=0; i--){ // provided at least one element matches
            if(s[i]==c){
                cpos = i;
            }
            res[i] = min(res[i], cpos - i); // refresh
        }
        return res;
    }
};
