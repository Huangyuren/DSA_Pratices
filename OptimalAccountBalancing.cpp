class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        int n = transactions.size();
        unordered_map<int, int> mymap;
        for(auto& x : transactions){
            mymap[x[0]] -= x[2];
            mymap[x[1]] += x[2];
        }
        overall = vector<int>(n);
        for(auto& x : mymap){
            if(x.second != 0) overall.push_back(x.second); // only take debts without zero
        }
        return dfs(0);
    }
    int dfs(int pos){
        while(pos < overall.size() && overall[pos]==0) pos++;
        int res = INT_MAX;
        for(int i=pos+1; i<overall.size(); i++){
            if(overall[i]*overall[pos] < 0){
                overall[i] += overall[pos];
                res = min(res, 1 + dfs(pos+1)); // now i is not under our considerations
                overall[i] -= overall[pos]; // restore back
            }
        }
        return res==INT_MAX ? 0 : res;
    }
private:
    vector<int> overall;
};
