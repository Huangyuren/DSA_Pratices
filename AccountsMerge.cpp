class Solution {
public:
    // Union & Find key part, finding parent iteratively
    int findparent(vector<int>& parentlst, int id){
        // Finding the root node
        // without path compression
        // while(parentlst[id] != id){
        //     id = parentlst[id];
        // }
        // with path compression, faster
        if(parentlst[id] != id){
            parentlst[id] = findparent(parentlst, parentlst[id]);
        }
        return parentlst[id];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parentlst(n);
        unordered_map<string, int> mymap; // This map helps us determine string1 & string2 have relation or not
        unordered_map<int, vector<string>> overallmap;
        vector<vector<string>> res;
        for(int i=0; i<n; i++){
            parentlst[i] = i;
            for(int j=1; j<accounts[i].size(); j++){
                string currstr = accounts[i][j];
                if(mymap.find(currstr) == mymap.end()){
                    mymap[currstr] = parentlst[i];
                }else{
                    // They have relation
                    int root1 = findparent(parentlst, mymap[currstr]);
                    int root2 = findparent(parentlst, i);
                    parentlst[root2] = root1; // no need to check root1 == root2, since we already know they have relation
                }
            }
        }
        for(auto& x : mymap){
            int rootid = findparent(parentlst, x.second);
            overallmap[rootid].push_back(x.first);
        }
        for(auto& x : overallmap){
            vector<string> tmp = x.second;
            sort(tmp.begin(), tmp.end());
            tmp.insert(tmp.begin(), accounts[x.first][0]);
            res.push_back(tmp);
        }
        return res;
    }
};
