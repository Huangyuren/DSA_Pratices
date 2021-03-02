// Simple principles, open a meeting room when needed, and close a meeting room when 
// the meeting ends
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> mymap;
        int res = 0, currooms = 0;
        for(auto x : intervals){
            mymap[x[0]] += 1;
            mymap[x[1]] -= 1;
        }
        for(auto x : mymap){
            currooms += x.second; // current rooms needed
            res = max(res, currooms); // Record for maximum room needed
        }
        return res;
    }
};
