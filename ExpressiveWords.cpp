// Code writing pattern & skipping strategy
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for(string& x : words){
            if(solver(S, x)) res++;
        }
        return res;
    }
    bool solver(const string& S, string& curr){
        int m = S.size(), n = curr.size(), j=0;
        // if(m < n) return false; // redundant, j<=n check also
        for(int i=0; i<m; i++){
            if(j < n && S[i] == curr[j]) j++;
            // Skipping process
            else if(i > 0 && i<m-1 && S[i] == S[i-1] && S[i] == S[i+1]);
            else if(i > 1 && S[i] == S[i-1] && S[i] == S[i-2]);
            else return false;
        }
        return j==n; // j should traverse all, Ex, abccc & abcd
    }
};
