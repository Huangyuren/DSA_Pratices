class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mymap = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int currsum = mymap[s.back()];
        int n = s.size();
        for(int i=n-2; i>=0; i--){
            if(mymap[s[i]] < mymap[s[i+1]]){
                currsum -= mymap[s[i]];
            }
            else
            {
                currsum += mymap[s[i]];
            }
        }
        return currsum;
    }
};
