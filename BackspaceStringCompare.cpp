// Follow up, O(1) time is hard, the key is we go from back to front
// Because front->back, we cannot determine current char will be deleted or not
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int m = S.size(), n = T.size(), back=0;
        int i=m-1, j=n-1;
        while(true){
            back = 0;
            while(i>=0 && (S[i]=='#' || back!=0)){
                back += S[i]=='#' ? 1 : -1; // Trick, decrement back or increment
                i--;
            }
            back = 0;
            while(j>=0 && (T[j]=='#' || back!=0)){
                back += T[j]=='#' ? 1 : -1;
                j--;
            }
            // When reaching here, all chars right to S[i], T[j] can all be cancelled
            if(i>=0 && j>=0 && S[i]==T[j]){
                i--; j--;
            }
            else
            {
                break;
            }
        }
        return i<0 && j<0;
    }
};
// O(N) solution using vector
// class Solution {
// public:
//     bool backspaceCompare(string S, string T) {
//         int m = S.size(), n = T.size();
//         vector<int> svec, tvec;
//         for(char x : S){
//             if(x != '#') svec.push_back(x);
//             else if(svec.size()) svec.pop_back();
//         }
//         for(char x : T){
//             if(x != '#') tvec.push_back(x);
//             else if(tvec.size()) tvec.pop_back();
//         }
//         return svec == tvec;
//     }
// };
