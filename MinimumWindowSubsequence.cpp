class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        int s = 0, t = 0, minlen = INT_MAX, startpos = 0;
        while(s < m){
            if(S[s] == T[t]){
                if(++t == n){
                    int endpoint = s+1; // set for endpoint, s+1 since s not yet ++
                    // Backward porpagation for shortest result
                    while(--t >= 0){ // --t since t has already ++
                        while(S[s--] != T[t]); // s will eventually delete one more time
                    }
                    s++; t = 0; // s++ restore back
                    if(endpoint - s < minlen){
                        minlen = endpoint - s;
                        startpos = s;
                    }
                }
            }
            s++; // s proceed
        }
        if(minlen == INT_MAX) return "";
        return S.substr(startpos, minlen);
    }
};
