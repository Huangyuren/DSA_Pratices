// Use additional unordered_set to record all duplications' position info
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        myvec.push_back(val);
        mymap[val].insert(myvec.size()-1);
        if(mymap[val].size() == 1){
            return true;
        }
        return false;
    }
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(mymap.find(val) == mymap.end()){
            return false;
        }
        int currpos = *mymap[val].begin(); // take out from set
        mymap[val].erase(currpos); // erase for this position's info
        mymap[myvec.back()].insert(currpos); // Update, since last element will swap with currpos
        mymap[myvec.back()].erase(myvec.size()-1); // Update, erase old position info
        swap(myvec[currpos], myvec.back());
        myvec.pop_back();
        if(mymap[val].size() == 0) mymap.erase(val); // Should be aware to actively cleaning
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return myvec[rand() % (myvec.size())];
    }
private:
    unordered_map<int, unordered_set<int>> mymap;
    vector<int> myvec;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
