// A little inspiration from random id generator, so unordered_map plus vector
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mymap.find(val) == mymap.end()){
            myvec.push_back(val);
            mymap[val] = myvec.size()-1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mymap.find(val) == mymap.end()){
            return false;
        }
        int valindex = mymap[val];
        mymap[myvec.back()] = valindex; // Remember to update current back of myvec with new index
        swap(myvec[valindex], myvec.back()); // Swap with last element in order to pop back
        myvec.pop_back(); // removing this val
        mymap.erase(val); // removing this val
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return myvec[rand() % myvec.size()];
    }
private:
    unordered_map<int, int> mymap;
    vector<int> myvec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
