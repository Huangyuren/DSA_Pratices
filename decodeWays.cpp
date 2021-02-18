/* This is O(2^n), TLE. 
 * class Solution {
 * public:
 *     int recursive(string s, int start){
 *         if(s[start] == '0') return 0;
 *         if(start == s.length()) return 1;
 *         int tmp = recursive(s, start+1);
 *         if(start < s.length()-1 && (s[start]=='1' || (s[start]=='2'&&s[start+1]<'7'))){
 *             tmp += recursive(s, start+2);
 *         }
 *         return tmp;
 *     }
 *     int numDecodings(string s) {
 *         if(s == "0") return 0;
 *         return recursive(s, 0);
 *     }
 * }; */
/* something better than above, non-dp using memoization.
 * class Solution {
 * public:
 *     int recur(string s, int start, vector<int>& vec){
 *         if(s[start] == '0') return 0;
 *         if(vec[start] > -1) {
 *             return vec[start];
 *         }
 *         int tmp = recur(s, start+1, vec);
 *         if(start < s.length()-1 && (s[start]=='1' || (s[start]=='2'&&s[start+1]<'7'))){
 *             tmp += recur(s, start+2, vec);
 *         }
 *         vec[start] = tmp;
 *         return tmp;
 *     }
 *     int numDecodings(string s) {
 *         if(s == "0") return 0;
 *         vector<int> vec(s.length()+1, -1);
 *         vec[s.length()] = 1;
 *         return recur(s, 0, vec);
 *     }
 * }; */

// Using dp
// All the way to last element in s, then go back to starting point!
// The key spirit is that index i is determined by i+1 & i+2
// What left behind is indexing problem
// Time: O(1), Space: O(n)
class Solution {
public:
    int numDecodings(string s) {
        if(s == "0") return 0;
        int n=s.length();
        vector<int> vec(n+1, -1);
        vec[n] = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='0'){
                vec[i] = 0;
            }
            else{
                vec[i] = vec[i+1];
                if(i < n-1 && (s[i]=='1' || (s[i]=='2'&&s[i+1]<'7'))){
                    vec[i] += vec[i+2];
                }
            }
        }
        return vec[0];
    }
};

// Simplified dp
// Time: O(1), space: O(1)!, need careful thinking.
class Solution {
public:
    int numDecodings(string s) {
        if(s == "0") return 0;
        int n=s.length();
        int cur, prev=1, prevp;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='0'){
                cur = 0;
            }
            else{
                cur = prev;
                if(i < n-1 && (s[i]=='1' || (s[i]=='2'&&s[i+1]<'7'))){
                    cur += prevp;
                }
            }
            prevp = prev;
            prev = cur;
        }
        return cur;
    }
};

