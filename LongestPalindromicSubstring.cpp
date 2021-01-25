class Solution {
public:
    Normal dp solution, starting from string right to left, important.
    string longestPalindrome(string s) {
        if(s == "") return "";
        int n = s.length();
        if(n==1) return s;
        int strstart=0;
        int longest=1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j] && (dp[i+1][j-1]==1 || j-i < 2)){
                    dp[i][j] = 1;
                    if(j-i+1 > longest){
                        strstart = i;
                        longest = j-i+1;
                    }
                }
            }
        }
        return s.substr(strstart, longest);
    }
    
    // Trick solution using expand center.
    // I think this is more straight forward but not consistent with dp thinks.
    // May be think of special solution.
    // string longestPalindrome(string s) {
    //     if(s=="") return "";
    //     int n = s.length();
    //     if(n == 1) return s;
    //     int strstart = 0;
    //     int longest = 1;
    //     for(int i=0; i<n; i++){
    //         int oddlong = expandcenter(s, i, i); //for things such as [1,2,3,2,1]
    //         int evenlong = expandcenter(s, i, i+1); //for things such as [1,2,2,1]
    //         int tmplongest = max(oddlong, evenlong);
    //         if(tmplongest > longest){
    //             strstart = i - (tmplongest-1)/2;
    //             longest = tmplongest;
    //         }
    //     }
    //     return s.substr(strstart, longest);
    // }
    // int expandcenter(string& s, int left, int right){
    //     int res;
    //     while(left >=0 && right < s.length() && s[left] == s[right]){
    //         res = right - left + 1;
    //         left--;
    //         right++;
    //     }
    //     return res;
    // }
};
