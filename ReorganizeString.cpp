// If we can put most frequently occurred char in even index(position) in res (string)
// Then there exists valid reorganized string
// Put most frequently chars in even places, and put others in other indexes
class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> mymap;
        for(int i=0; i<S.size(); i++){
            mymap[S[i]] += 1;
        }
        int currmax = 0;
        char currmaxchar;
        vector<pair<char, int>> myvec;
        for(auto& x : mymap){
            if(x.second > currmax){
                currmax = x.second;
                currmaxchar = x.first;
            }
            if(currmax > (S.size()+1)/2) return "";  // Will definitely overflow, so adjacent are the same
            myvec.push_back({x.first, x.second});
        }
        // Here we don't need to do sorting, just clustering same chars and dispatching with interleaving order
        string clusterstr = string(currmax, currmaxchar);
        for(auto& x : myvec){
            if(x.first != currmaxchar){
                clusterstr += string(x.second, x.first); // This will create something like aaaaabbbcc
            }
        }
        // Tricky part
        // Remember, if valid, most frequently occurred char will showup at most (s.size()+1)/2
        string res = "";
        int mid = (clusterstr.size()+1)/2;
        int left = 0, right = mid;
        while(left < mid || right < clusterstr.size()){
            if(left < mid){
                res += clusterstr[left];
                left++;
            }
            if(right < clusterstr.size()){
                res += clusterstr[right];
                right++;
            }
        }
        return res;
    }
};
