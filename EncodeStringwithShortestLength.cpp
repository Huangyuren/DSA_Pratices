#define mypair pair<int, string>
class Solution {
public:
    // bool sort_criterion(string input1, string input2){
    //     return input1.size() < input2.size();
    // }
    string encode(string s) {
        unordered_map<string, string> mymap; // current string: s, s's encoded string: res
        return solver(s, mymap);
    }
    string solver(string s, unordered_map<string, string>& mymap){
        // case 1: have already found it
        if(mymap.count(s)) return mymap[s];
        if(s.size() <= 4) return s; // edge case handling
        
        // case 2: whole string s can be encoded as x[some repeat part]
        string encodewhole;
        int ones = (s+s).find(s, 1);
        if(ones >= s.size()){
            encodewhole = s;
        }else{
            encodewhole = to_string((s.size() / ones))+"["+solver(s.substr(0, ones), mymap)+"]"; // Encode into repeated string part
        }
        
        // case 3: divide and conquer, also maybe no encoding
        priority_queue<mypair, vector<mypair>, greater<mypair>> mypq; mypq.push({encodewhole.size(), encodewhole});
        for(int i=1; i<s.size(); i++){
            string tmp = solver(s.substr(0, i), mymap)+solver(s.substr(i), mymap);
            mypq.push({tmp.size(), tmp});
        }
        string shorteststr = mypq.top().second;
        
        // case 3: Or using vector, but really slow, slower than pq
        // vector<string> myvec; myvec.push_back(encodewhole);
        // for(int i=1; i<s.size(); i++){
        //     string tmp = solver(s.substr(0, i), mymap)+solver(s.substr(i), mymap);
        //     myvec.push_back(tmp);
        // }
        // sort(myvec.begin(), myvec.end(), [this](string& a, string& b) { return sort_criterion(a, b); });
        // string shorteststr = myvec[0];
        mymap[s] = shorteststr;
        return shorteststr;
    }
};
