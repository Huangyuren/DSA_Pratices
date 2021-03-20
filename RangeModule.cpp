class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        // Remove any current [left, right) if possible, then insert left,right and fix gaps
        removeRange(left, right);
        mymap[left] = right;
        auto x = mymap.find(left);
        if(x != mymap.begin() && prev(x)->second == left){
            // previous node's second is exactly left
            x--;
            x->second = right;
            mymap.erase(left);
        }
        if(x != prev(mymap.end()) && next(x)->first == right){
            // next node's first is exactly right
            x->second = next(x)->second;
            mymap.erase(next(x));
        }
        // two cases may happen simultaneously
        return;
    }
    
    bool queryRange(int left, int right) {
        auto search = mymap.upper_bound(left); // equal or goes after!
        if(mymap.empty() || search == mymap.begin()) return false;
        search--;
        return search->second >= right;
    }
    
    void removeRange(int left, int right) {
        if(mymap.empty()) return;
        auto x = mymap.lower_bound(left); // equal or goes after!
        if(x != mymap.begin()) x--;
        vector<int> tobedel;
        // Consider 4 cases:
        //   | -------- | (left, right)
        //     | -- |     (x, case 1)
        // | -----|       (x, case 2)
        //          | ----- | (x, case 3)
        // | --------------| (x, case 4)
        while(x != mymap.end() && x->first < right){
            if(x->first < left && x->second > left){
                // case 2
                int backup = x->second;
                mymap[x->first] = left;
                if(backup > right){
                    // case 4
                    mymap[right] = backup;
                }
            }else if(x->first >= left){
                // case 2
                tobedel.push_back(x->first);
                if(x->second > right){
                    // case 3
                    mymap[right] = x->second;
                }
            }
            // We cannot do erase within while loop, since x++ will lose
            x++;
        }
        for(auto i : tobedel){
            mymap.erase(i);
        }
        return;
    }
    void printmap(){
        for(auto& x : mymap){
            printf("First: %d, second: %d\n", x.first, x.second);
        }
        return;
    }
private:
    map<int, int> mymap; // [left, right)
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
