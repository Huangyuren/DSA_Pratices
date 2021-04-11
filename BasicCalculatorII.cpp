// Solution without stack
// Looking at previous sign is a little hard to think of
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int tmp=0, prev=0, res=0;
        char prevsign = '+'; // Since all integers are all >= 0
        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                tmp = tmp*10 + (s[i]-'0'); // remember to add () bracket
            }
            if(!isdigit(s[i]) && !isspace(s[i]) || i==n-1){
                // Condition at previous sign
                if(prevsign == '+'){
                    res += prev;
                    prev = tmp;
                }else if(prevsign == '-'){
                    res += prev; // still plus
                    prev = -tmp; // change sign
                }else if(prevsign == '*'){
                    prev *= tmp;
                }else{
                    prev /= tmp;
                }
                prevsign = s[i];
                tmp = 0;
            }
        }
        res += prev;
        return res;
    }
};
