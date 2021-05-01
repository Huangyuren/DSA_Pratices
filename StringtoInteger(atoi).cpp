class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()) return 0;
        int i = 0, sign = 1;
        long res = 0;
        
        // Concept, white spaces and sign should be dealt at the beginning and only once
        while(s[i]==' '){
            i++;
        }
        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }else if(!isdigit(s[i])) return 0;
        
        while(isdigit(s[i])){
            res = res*10 + s[i] - '0';
            if(res >= INT_MAX || res <= INT_MIN) break;
            i++;
        }
        res *= sign;
        if(res >= INT_MAX) return INT_MAX;
        if(res <= INT_MIN) return INT_MIN;
        return res;
    }
};
